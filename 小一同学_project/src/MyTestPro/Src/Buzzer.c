#include "Buzzer.h"

void Buzzer_Init(void)
{
	//打开GPIOBEN端口的时钟使能
	RCC->APB2ENR |=(1<<3);
	//将GPIOB端口配置低寄存器中32位都置0
	GPIOB->CRL &=~(0xFFFFFFFF);
	//将八个都配置成为通推挽式输出模式下的最大速度输出模式（50MHZ）
	GPIOB->CRL |=(0x3<<20);
	//关闭蜂鸣器
	GPIOB->ODR |=(1<<5);
}

void Buzzer_Open(void)
{
	GPIOB->ODR &=~(1<<5);
}

void Buzzer_Close(void)
{
	GPIOB->ODR |=(1<<5);
}

void Buzzer_Lien(void)
{
	u32 i=1000;
	SysTick_Init(72);
	while(i--)
	{
	  Buzzer_Open();
		delay_us(i);
		Buzzer_Close();
		delay_us(i--);
	}
}

void Buzzer_Lien2(void)
{
	int x;
	SysTick_Init(72);
	for(x=0;x<1000;x++)
	{
	GPIOB->ODR |=(1<<5);
	delay_ms(1);
	GPIOB->ODR &=(0<<5);
	delay_ms(1);	
	}
}





















