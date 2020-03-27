#include "Irq.h"
#include "system.h"
#include "tftlcd.h"


IRQ_EVENT IRQ_Events[IRQMAX];


void KEY_Gpio_Init(void)
{   
	  RCC->APB2ENR |=(1<<2);//复位GPIOA
		RCC->APB2ENR |=(1<<6);//复位GPIOE
		GPIOA->CRL &=~(0xF<<0);//清空GPIOA下的GPIOA0管脚
		GPIOE->CRL &=~(0xFFF<<8);//清空GPIOE下GPIOE2、3、4管脚
		GPIOA->CRL |=(0x8<<0);//将GPIOA0下的管脚配置为上下拉输入模式（10 00）
		GPIOE->CRL |=(0x888<<8);//将GPIOE2、3、4下的管脚配置为上下拉输入模式（10 00）
	  GPIOA->ODR |=~(1<<0);//配置默认是低电平输入
	  GPIOE->ODR |=(0x7<<2);//配置默认是高电平输入
		
}

void KEY_Exti_Init(void)
{
	RCC->APB2ENR |=(1<<0);//复位辅助功能
	AFIO->EXTICR[0] &=~(0xF<<0);//外部中断配置寄存器
	AFIO->EXTICR[0] &=~(0xF<<8);//外部中断配置寄存器
	AFIO->EXTICR[0] &=~(0xF<<12);//外部中断配置寄存器
	AFIO->EXTICR[1] &=~(0xF<<0);//外部中断配置寄存器
	AFIO->EXTICR[0] |=(0x4<<8);//将外部中断配置器配置为EXTI2配置为PE2（0100）
	AFIO->EXTICR[0] |=(0x4<<12);//将外部中断配置器配置为EXTI3配置为PE3（0100）
	AFIO->EXTICR[1] |=(0x4<<0);//将外部中断配置器配置为EXTI4配置为PE4（0100）
	/*
	EXTI->IMR |=(1<<0);//设置中断屏蔽使能 默认是不屏蔽的
	EXTI->IMR |=(1<<2);//设置中断屏蔽使能 默认是不屏蔽的
	EXTI->IMR |=(1<<3);//设置中断屏蔽使能 默认是不屏蔽的
	EXTI->IMR |=(1<<4);//设置中断屏蔽使能 默认是不屏蔽的
	EXTI->RTSR |=(1<<0);//设置称为上升沿触发
	EXTI->RTSR |=(1<<2);//设置称为上升沿触发
	EXTI->RTSR |=(1<<3);//设置称为上升沿触发
	EXTI->RTSR |=(1<<4);//设置称为上升沿触发
	*/
}

/*
void KEY_Nvic_Init(void)
{
	NVIC->ISER[0] |=(1<<6);//总的中断的屏蔽打开
	NVIC->ISER[0] |=(1<<8);//总的中断的屏蔽打开
	NVIC->ISER[0] |=(1<<9);//总的中断的屏蔽打开
	NVIC->ISER[0] |=(1<<10);//总的中断的屏蔽打开
}
*/

void KEY_Irq_Init(void)
{
	KEY_Gpio_Init();//GPIO口的初始化
	KEY_Exti_Init();//外部中断的初始化
	IRQ_Install(EXTI0_IRQn,EXTI0_IRQHandler);//安装中断
	IRQ_Install(EXTI2_IRQn,EXTI2_IRQHandler);//安装中断
	IRQ_Install(EXTI3_IRQn,EXTI3_IRQHandler);//安装中断
	IRQ_Install(EXTI4_IRQn,EXTI4_IRQHandler);//安装中断
	
	//KEY_Nvic_Init();//总的中断的初始化
}

//IRQ中断初始化
void IRQ_Init()
{
	int iCount=0;
	for(iCount=0;iCount<IRQMAX;iCount++)
	{
		IRQ_Events[iCount].IRQNum=(IRQn_Type)iCount;//将自定义终端数组的标号与系统中断标号同步
		IRQ_Events[iCount].IRQ_Heandle=0;//中断操作为空
	}	
}

void IRQ_Install(IRQn_Type IRQNum,IRQ_pHandle IRQHandle)
{
	
	if((IRQNum<I2C1_ER_IRQn )&& (IRQNum>=WWDG_IRQn))
	{
		IRQ_Events[IRQNum].IRQ_Heandle=IRQHandle;//安装操作
		NVIC->ISER[0] |=(1<<(IRQNum));
	}
	else if((IRQNum<IRQMAX )&& (IRQNum>=I2C1_ER_IRQn))
	{
		IRQ_Events[IRQNum].IRQ_Heandle=IRQHandle;//安装操作
		NVIC->ISER[1] |=(1<<(IRQNum-I2C1_ER_IRQn));
	}
	if((IRQNum>=EXTI0_IRQn)&&(IRQNum<=EXTI4_IRQn))
	{
		EXTI->IMR |=(1<<(IRQNum-6));
		EXTI->RTSR |=(1<<(IRQNum-6));
	}
}

void IRQ_Unload(IRQn_Type IRQNum,IRQ_pHandle IRQHandle)
{
	if((IRQNum<I2C1_ER_IRQn )&& (IRQNum>=WWDG_IRQn))
	{
		NVIC->ISER[0] &=~(1<<IRQNum);
	}
	else if((IRQNum>=I2C1_ER_IRQn)&&(IRQNum<=IRQMAX))
	{
		NVIC->ISER[1] &=~(1<<(IRQNum-IRQNum));
	}
}

void IRQ_PriorityGroup(short Group_Num)
{
	SCB->AIRCR &=~(0X7<<EXTI2_IRQn);//清空
	switch(Group_Num)//组别
	{
		case 0:
		{
			SCB->AIRCR |=(7<<EXTI2_IRQn);
		}break;
		case 1:
		{
			SCB->AIRCR |=(6<<EXTI2_IRQn);
		}break;
		case 2:
		{
			SCB->AIRCR |=(5<<EXTI2_IRQn);
		}break;
		case 3:
		{
			SCB->AIRCR |=(4<<EXTI2_IRQn);
		}break;
		case 4:
		{
			SCB->AIRCR |=(3<<EXTI2_IRQn);
		}break;
	}
}

//配置优先级
void IRQ_Priority(IRQn_Type IRQNum,short Num)//设置优先级，num为四位二进制数，前两位分配抢占位
{
	NVIC->IP[IRQNum] &=~(Num)<<4;//清空
	NVIC->IP[IRQNum] |=(Num<<4);//配置优先级
}


void IRQ_Desacth(void)//IRQ搜索，中断执行
{
	int iCount,IRQ_Num;
	for(iCount=0;iCount<60;iCount++)
	{
		if(((NVIC->IABR[0]>>iCount)&1)||((NVIC->IABR[1]>>(iCount-32))&1))
		{
				IRQ_Num=iCount;
				break;
		}
	}//将产生的中断编号赋值给IRQ_Num
	//根据产生的中断编号选择
	switch(IRQ_Num)
	{
		case EXTI0_IRQn:
		case EXTI2_IRQn:
		case EXTI3_IRQn:
		case EXTI4_IRQn:
		{
			IRQ_Events[IRQ_Num].IRQ_Heandle();
			EXTI->PR |=(1<<(IRQ_Num-6));
			NVIC->ICPR[0] |=(1<<IRQ_Num);
		}break;
		case TIM2_IRQn:
			{
			IRQ_Events[IRQ_Num].IRQ_Heandle();
			NVIC->ICPR[0] |=(1<<IRQ_Num);
			TIM2->SR &=~(1<<0);
		}break;
		case TIM3_IRQn:
			{
			IRQ_Events[IRQ_Num].IRQ_Heandle();
			NVIC->ICPR[0] |=(1<<IRQ_Num);
			TIM3->SR &=~(1<<0);
		}break;
		case TIM4_IRQn:
			{
			IRQ_Events[IRQ_Num].IRQ_Heandle();
			NVIC->ICPR[0] |=(1<<IRQ_Num);
			TIM4->SR &=~(1<<0);
		}break;
		case TIM5_IRQn:
		{
			IRQ_Events[IRQ_Num].IRQ_Heandle();
			NVIC->ICPR[0] |=(1<<IRQ_Num);
			TIM5->SR &=~(1<<0);
		}break;
		case USART1_IRQn:
		{
			IRQ_Events[IRQ_Num].IRQ_Heandle();
			NVIC->ICPR[1] |=(1<<IRQ_Num);
		}break;	
		case RTC_IRQn:
		{
			IRQ_Events[IRQ_Num].IRQ_Heandle();
			RTC->CRL &=~(1<<0);
			NVIC->ICPR[0] |=(1<<IRQ_Num);
			
		}break;	
	}
}



/*------------------------中断执行函数-------------------------------*/

void EXTI0_IRQHandler(void)
{
Direction=UP;
//EXTI->PR |=(1<<0);//外部中断的解挂
//NVIC->ICPR[0] |=(0x1<<6);//总的中断的解挂
}

void EXTI2_IRQHandler(void)
{
Direction=LEFT;
//EXTI->PR |=(1<<2);//外部中断的解挂
//NVIC->ICPR[0] |=(0x1<<8);//总的中断的解挂
}

void EXTI3_IRQHandler(void)
{
Direction=DOWN;
//EXTI->PR |=(1<<3);//外部中断的解挂
//NVIC->ICPR[0] |=(0x1<<9);//总的中断的解挂
}

void EXTI4_IRQHandler(void)
{
Direction=RIGHT;
//EXTI->PR |=(1<<4);//外部中断的解挂
//NVIC->ICPR[0] |=(0x1<<10);//总的中断的解挂
}



/*void TIM3_IRQHandler(void)
{
LED_ShowNumber(x);
x++;
}

void TIM4_IRQHandler(void)
{
LCD_Fill(10,10,20,20,RED);
//EXTI->PR |=(1<<4);//外部中断的解挂
//NVIC->ICPR[0] |=(0x1<<10);//总的中断的解挂
}

void TIM5_IRQHandler(void)
{
LCD_Fill(10,10,20,20,RED);
//EXTI->PR |=(1<<4);//外部中断的解挂
//NVIC->ICPR[0] |=(0x1<<10);//总的中断的解挂
}
*/


