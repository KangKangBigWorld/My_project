#include "Buzzer.h"

void Buzzer_Init(void)
{
	//��GPIOBEN�˿ڵ�ʱ��ʹ��
	RCC->APB2ENR |=(1<<3);
	//��GPIOB�˿����õͼĴ�����32λ����0
	GPIOB->CRL &=~(0xFFFFFFFF);
	//���˸������ó�Ϊͨ����ʽ���ģʽ�µ�����ٶ����ģʽ��50MHZ��
	GPIOB->CRL |=(0x3<<20);
	//�رշ�����
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





















