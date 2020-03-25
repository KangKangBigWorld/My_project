#include "LED.h"
u8 x=0;

u8 LED_Flag=0;

void LED_Init(void)
{
	//打开GIOPCEN端口的时钟使能
	RCC->APB2ENR |=(1<<4);
	//将GPIOC端口配置低寄存器中32位都置0
	GPIOC->CRL &=~(0xFFFFFFFF);
	//将八个灯都配置成为通用推挽输出模式下的最大速度输出模式（50MHZ）
	GPIOC->CRL |=(0x33333333);
	//关闭八盏灯
	GPIOC->ODR |=(0xFF);
}

void LED_Open(int x)
{
	GPIOC->ODR &=~(1<<x);
}

void LED_OpenAll(void)
{
	GPIOC->ODR &=~(0xFF);
}

void LED_Close(int x)
{
	GPIOC->ODR |=(1<<x);
}

void LED_CloseAll(void)
{
	GPIOC->ODR |=(0xFF);
}

void LED_ShowNumber(int x)
{
	switch (x%10)
	{
		case 0:
		{
			LED_CloseAll();
			LED_Open(0);
			LED_Open(1);
			LED_Open(2);
			LED_Open(3);
			LED_Open(4);
			LED_Open(5);
		}break;	
		case 1:
		{
			LED_CloseAll();
			LED_Open(1);
			LED_Open(2);
		}break;	
		case 2:
		{
			LED_CloseAll();
			LED_Open(0);
			LED_Open(1);
			LED_Open(3);
			LED_Open(4);
			LED_Open(6);
		}break;	
		case 3:
		{
			LED_CloseAll();
			LED_Open(0);
			LED_Open(1);
			LED_Open(2);
			LED_Open(3);
			LED_Open(6);
		}break;	
		case 4:
		{
			LED_CloseAll();
			LED_Open(1);
			LED_Open(2);
			LED_Open(5);
			LED_Open(6);
		}break;	
		case 5:
		{
			LED_CloseAll();
			LED_Open(0);
			LED_Open(2);
			LED_Open(3);
			LED_Open(5);
			LED_Open(6);
		}break;	
		case 6:
		{
			LED_CloseAll();
			LED_Open(0);
			LED_Open(2);
			LED_Open(3);
			LED_Open(4);
			LED_Open(5);
			LED_Open(6);
		}break;	
		case 7:
		{
			LED_CloseAll();
			LED_Open(0);
			LED_Open(1);
			LED_Open(2);
		}break;	
		case 8:
		{
			LED_CloseAll();
			LED_Open(0);
			LED_Open(1);
			LED_Open(2);
			LED_Open(3);
			LED_Open(4);
			LED_Open(5);
			LED_Open(6);
		}break;	
		case 9:
		{
			LED_CloseAll();
			LED_Open(0);
			LED_Open(1);
			LED_Open(2);
			LED_Open(3);
			LED_Open(5);
			LED_Open(6);
		}break;	
	}
}

void LED_Count(void)
{
	if(x!=9)
	{
		LED_ShowNumber(x);
		x++;
	}
	else
	{
		LED_ShowNumber(x);
		x=0;
	}
}

void LED_CountDown(int x)
{
	SysTick_Init(72);
	LED_ShowNumber(x);
	for(;x>0;)
		{
			x--;
			delay_ms(1000);
			LED_ShowNumber(x);
		}
}


void My_LED()
{
	if(LED_Flag==LED_OFF)
	{
		LED_OpenAll();
		Busy("LED灯已开启！");
		LED_Flag=LED_ON;
	}
	else if(LED_Flag==LED_ON)
	{
		LED_CloseAll();
		Busy("LED灯已关闭！");
		LED_Flag=LED_OFF;
	}
	delay_ms(500);
}
