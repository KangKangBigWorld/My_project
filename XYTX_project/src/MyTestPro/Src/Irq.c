#include "Irq.h"
#include "system.h"
#include "tftlcd.h"


IRQ_EVENT IRQ_Events[IRQMAX];


void KEY_Gpio_Init(void)
{   
	  RCC->APB2ENR |=(1<<2);//��λGPIOA
		RCC->APB2ENR |=(1<<6);//��λGPIOE
		GPIOA->CRL &=~(0xF<<0);//���GPIOA�µ�GPIOA0�ܽ�
		GPIOE->CRL &=~(0xFFF<<8);//���GPIOE��GPIOE2��3��4�ܽ�
		GPIOA->CRL |=(0x8<<0);//��GPIOA0�µĹܽ�����Ϊ����������ģʽ��10 00��
		GPIOE->CRL |=(0x888<<8);//��GPIOE2��3��4�µĹܽ�����Ϊ����������ģʽ��10 00��
	  GPIOA->ODR |=~(1<<0);//����Ĭ���ǵ͵�ƽ����
	  GPIOE->ODR |=(0x7<<2);//����Ĭ���Ǹߵ�ƽ����
		
}

void KEY_Exti_Init(void)
{
	RCC->APB2ENR |=(1<<0);//��λ��������
	AFIO->EXTICR[0] &=~(0xF<<0);//�ⲿ�ж����üĴ���
	AFIO->EXTICR[0] &=~(0xF<<8);//�ⲿ�ж����üĴ���
	AFIO->EXTICR[0] &=~(0xF<<12);//�ⲿ�ж����üĴ���
	AFIO->EXTICR[1] &=~(0xF<<0);//�ⲿ�ж����üĴ���
	AFIO->EXTICR[0] |=(0x4<<8);//���ⲿ�ж�����������ΪEXTI2����ΪPE2��0100��
	AFIO->EXTICR[0] |=(0x4<<12);//���ⲿ�ж�����������ΪEXTI3����ΪPE3��0100��
	AFIO->EXTICR[1] |=(0x4<<0);//���ⲿ�ж�����������ΪEXTI4����ΪPE4��0100��
	/*
	EXTI->IMR |=(1<<0);//�����ж�����ʹ�� Ĭ���ǲ����ε�
	EXTI->IMR |=(1<<2);//�����ж�����ʹ�� Ĭ���ǲ����ε�
	EXTI->IMR |=(1<<3);//�����ж�����ʹ�� Ĭ���ǲ����ε�
	EXTI->IMR |=(1<<4);//�����ж�����ʹ�� Ĭ���ǲ����ε�
	EXTI->RTSR |=(1<<0);//���ó�Ϊ�����ش���
	EXTI->RTSR |=(1<<2);//���ó�Ϊ�����ش���
	EXTI->RTSR |=(1<<3);//���ó�Ϊ�����ش���
	EXTI->RTSR |=(1<<4);//���ó�Ϊ�����ش���
	*/
}

/*
void KEY_Nvic_Init(void)
{
	NVIC->ISER[0] |=(1<<6);//�ܵ��жϵ����δ�
	NVIC->ISER[0] |=(1<<8);//�ܵ��жϵ����δ�
	NVIC->ISER[0] |=(1<<9);//�ܵ��жϵ����δ�
	NVIC->ISER[0] |=(1<<10);//�ܵ��жϵ����δ�
}
*/

void KEY_Irq_Init(void)
{
	KEY_Gpio_Init();//GPIO�ڵĳ�ʼ��
	KEY_Exti_Init();//�ⲿ�жϵĳ�ʼ��
	IRQ_Install(EXTI0_IRQn,EXTI0_IRQHandler);//��װ�ж�
	IRQ_Install(EXTI2_IRQn,EXTI2_IRQHandler);//��װ�ж�
	IRQ_Install(EXTI3_IRQn,EXTI3_IRQHandler);//��װ�ж�
	IRQ_Install(EXTI4_IRQn,EXTI4_IRQHandler);//��װ�ж�
	
	//KEY_Nvic_Init();//�ܵ��жϵĳ�ʼ��
}

//IRQ�жϳ�ʼ��
void IRQ_Init()
{
	int iCount=0;
	for(iCount=0;iCount<IRQMAX;iCount++)
	{
		IRQ_Events[iCount].IRQNum=(IRQn_Type)iCount;//���Զ����ն�����ı����ϵͳ�жϱ��ͬ��
		IRQ_Events[iCount].IRQ_Heandle=0;//�жϲ���Ϊ��
	}	
}

void IRQ_Install(IRQn_Type IRQNum,IRQ_pHandle IRQHandle)
{
	
	if((IRQNum<I2C1_ER_IRQn )&& (IRQNum>=WWDG_IRQn))
	{
		IRQ_Events[IRQNum].IRQ_Heandle=IRQHandle;//��װ����
		NVIC->ISER[0] |=(1<<(IRQNum));
	}
	else if((IRQNum<IRQMAX )&& (IRQNum>=I2C1_ER_IRQn))
	{
		IRQ_Events[IRQNum].IRQ_Heandle=IRQHandle;//��װ����
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
	SCB->AIRCR &=~(0X7<<EXTI2_IRQn);//���
	switch(Group_Num)//���
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

//�������ȼ�
void IRQ_Priority(IRQn_Type IRQNum,short Num)//�������ȼ���numΪ��λ����������ǰ��λ������ռλ
{
	NVIC->IP[IRQNum] &=~(Num)<<4;//���
	NVIC->IP[IRQNum] |=(Num<<4);//�������ȼ�
}


void IRQ_Desacth(void)//IRQ�������ж�ִ��
{
	int iCount,IRQ_Num;
	for(iCount=0;iCount<60;iCount++)
	{
		if(((NVIC->IABR[0]>>iCount)&1)||((NVIC->IABR[1]>>(iCount-32))&1))
		{
				IRQ_Num=iCount;
				break;
		}
	}//���������жϱ�Ÿ�ֵ��IRQ_Num
	//���ݲ������жϱ��ѡ��
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



/*------------------------�ж�ִ�к���-------------------------------*/

void EXTI0_IRQHandler(void)
{
Direction=UP;
//EXTI->PR |=(1<<0);//�ⲿ�жϵĽ��
//NVIC->ICPR[0] |=(0x1<<6);//�ܵ��жϵĽ��
}

void EXTI2_IRQHandler(void)
{
Direction=LEFT;
//EXTI->PR |=(1<<2);//�ⲿ�жϵĽ��
//NVIC->ICPR[0] |=(0x1<<8);//�ܵ��жϵĽ��
}

void EXTI3_IRQHandler(void)
{
Direction=DOWN;
//EXTI->PR |=(1<<3);//�ⲿ�жϵĽ��
//NVIC->ICPR[0] |=(0x1<<9);//�ܵ��жϵĽ��
}

void EXTI4_IRQHandler(void)
{
Direction=RIGHT;
//EXTI->PR |=(1<<4);//�ⲿ�жϵĽ��
//NVIC->ICPR[0] |=(0x1<<10);//�ܵ��жϵĽ��
}



/*void TIM3_IRQHandler(void)
{
LED_ShowNumber(x);
x++;
}

void TIM4_IRQHandler(void)
{
LCD_Fill(10,10,20,20,RED);
//EXTI->PR |=(1<<4);//�ⲿ�жϵĽ��
//NVIC->ICPR[0] |=(0x1<<10);//�ܵ��жϵĽ��
}

void TIM5_IRQHandler(void)
{
LCD_Fill(10,10,20,20,RED);
//EXTI->PR |=(1<<4);//�ⲿ�жϵĽ��
//NVIC->ICPR[0] |=(0x1<<10);//�ܵ��жϵĽ��
}
*/


