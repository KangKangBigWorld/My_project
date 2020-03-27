#include "dht11.h"
#include "SysTick.h"
#include <stdio.h>
#include "usart1.h"
#include "My_Function.h"
void DHT11_Init(void)
{
	//ѡ��PA11��ΪDHT11����ͨ�ſ�
	RCC->APB2ENR |= (1<<2);
	GPIOA->CRH &= ~(0xF<<3*4);
	GPIOA->CRH |= (3<<3*4);//Ĭ������ͨ���������
	GPIOA->ODR |= (1<<11);//Ĭ�����øߵ�ƽ
}
void DHT11_SetMode(u8 mode)
{
	
	GPIOA->CRH &= ~(0xF<<3*4);//�Ĵ�������
	switch(mode)
	{
		case MODE_IN:
			GPIOA->CRH |= (8<<3*4);//����������
			break;
		case MODE_OUT:
			GPIOA->CRH |= (3<<3*4);//ͨ���������
			break;
		default:
				  USART1_PutStr("\r\nDTh11ģʽ���ô���!");
			 break;
	}
}
void DHT11_SetLever(u8 lever)
{
	switch(lever)
	{
		case LEVER_H:
			GPIOA->BSRR |= (1<<11);//�ߵ�ƽ���
			break;
		case LEVER_L:
			GPIOA->BRR |= (1<<11);//�͵�ƽ���
			break;
		default:
				  USART1_PutStr("\r\nDTh11�ߵ͵�ƽ���ô���!");
			 break;
	}
}
uint_16 DHT11_ReadLever(void)
{
	return ((GPIOA->IDR & (1<<11))>>11);//��ȡ�����ƽ
}
uint_16 DTH11_ReadBit(void)
{
	uint_16 time=0,bit_data;
	while(DHT11_ReadLever());//�ȴ��͵�ƽ����
	delay_us(50);//�͵�ƽ����50us
	while(!DHT11_ReadLever());//�ȴ��ߵ�ƽ����
	delay_us(1);
	while(DHT11_ReadLever())//��¼�ߵ�ƽά�ֵ�ʱ��
	{
		time++;
		delay_us(1);
	}
	if(time>27)
	{
		bit_data = 1;//����Ϊ1 
	}
	else
	{
		bit_data = 0;//����Ϊ0
	}
	return bit_data;
}
uint_16 DTH11_ReadByte(void)
{
	uint_16 i,dat=0;
	for(i=0;i<8;i++)//����ȡλת��Ϊ�ֽ�
	{
		dat<<=1;
		dat |= DTH11_ReadBit();
	}
	return dat;
}
void DHT11_Com_Agreement(void)
{
	DHT11_SetMode(MODE_OUT);//�������ģʽ
	DHT11_SetLever(LEVER_H);//���øߵ�ƽ
	delay_us(20);//�͵�ƽ����20us
	DHT11_SetLever(LEVER_L);//���õ͵�ƽ
	delay_ms(20);//�͵�ƽ����20ms
	DHT11_SetLever(LEVER_H);//���øߵ�ƽ
	delay_us(30);//�ߵ�ƽ����30us
	DHT11_SetMode(MODE_IN);//��������ģʽ
	while(DHT11_ReadLever());//�ȴ��͵�ƽ��Ӧ
	delay_us(80);//�͵�ƽ��Ӧ����80us
	while(!DHT11_ReadLever());//�ȴ��ߵ�ƽ��Ӧ
	delay_us(80);//�ߵ�ƽ��Ӧ����80us
}
uint_16 DHT11_ReadData(u16 *temperature,u16 *humidity)
{
	uint_16 date[5]={0},i=0,stu;
	DHT11_Com_Agreement();
	for(i=0;i<5;i++)	
	{
		date[i] = DTH11_ReadByte();
	}
	if(date[0]+date[1]+date[2]+date[3] == date[4])
	{
		*humidity = date[0];
		*temperature = date[2];
		stu=1;
	}	
	else 
	{
		stu=0;
	}
	return stu;
}
char T_H_acbuf[20];
char Tem[20];
char My_Tem[10];
char My_Hum[10];
void DHT11_Show_T_H(void)
{
	u16 temperature,humidity;
	u8 stu;
	Busy("����:������·������");
	stu=DHT11_ReadData(&temperature,&humidity);
	if(stu)
	{
		sprintf(T_H_acbuf,"\r\n�¶�:%d ʪ��:%d",temperature,humidity);
		//USART1_PutStr(T_H_acbuf);
		sprintf(Tem,"%d�� %d%%",temperature,humidity);
		sprintf(My_Tem,"�¶�:%d��",temperature);
		sprintf(My_Hum,"ʪ��:%d%%",humidity);
		LCD_ShowFont12Char(110,0,(uint8_t *)Tem,BLACK,CYAN);
		if(Wendu_Flag==1)
		{
				LCD_ShowFont12Char(80,100,(uint8_t *)My_Tem,BLACK,WHITE);
				LCD_ShowFont12Char(80,130,(uint8_t *)My_Hum,BLACK,WHITE);
		}
	}
	Free();
}
char DHT11_tem[10],DHT11_hum[10];

void DHT11_Show_LCD_T_H(void)
{
	u16 temperature,humidity;
	u8 stu;
	stu=DHT11_ReadData(&temperature,&humidity);
	if(stu)
	{
		sprintf(DHT11_tem,":%d",temperature);
		sprintf(DHT11_hum,":%d",humidity);
	}
}


/*

#include "dht11.h"


void DHT11_Init(void)
{
	//GPIOA11
	RCC->APB2ENR |=(1<<2);
	//ģʽ���� ���ģʽ �ߵ�ƽ
	GPIOA->CRH &=~(0xF<<12);
	//����ʽ���
	GPIOA->CRH |=(3<<12); 
	//�ߵ�ƽ���
	GPIOA->ODR |=(1<<11);
}


void DHT11_SetMode(u8 mode)
{
	GPIOA->CRH &=~(0xF<<12);//�Ĵ�������
	switch(mode)
	{
		case MODE_INPUT:
		{
			GPIOA->CRH |=(8<<12); //������������
		}break;
		case MODE_OUTPUT:
		{
			GPIOA->CRH |=(3<<12);  //����ʽ���
		}break;
		default:
		{
			USART1_PutStr("\r\nDTh11ģʽ���ô���!");
		}
		 break;
	}
}


void DHT11_SetLevel(u8 level)
{
	switch(level)
	{
		case LOW_LEVEL:
		{
			GPIOA->BRR |=(1<<11);//�͵�ƽ���
		}break;
		case HIGHT_LEVEL:
		{
			GPIOA->BSRR |=(1<<11);//�ߵ�ƽ���
		}break;
		default:
		{
			USART1_PutStr("\r\nDTh11�ߵ͵�ƽ���ô���!");
		}
		break;
	}
}


int16 DHT11_JudgeLevel()
{
	return ((GPIOA->IDR & (1<<11))>>11);//��ȡ�����ƽ
}

int16 DHT11_RdBit()
{
	int16 iCount=0;
	//�ȴ��͵�ƽ����
	while(DHT11_JudgeLevel())
	{
		
	}
	//�͵�ƽ����50us
	delay_us(50);
	
	//�ж��Ƿ�����ߵ�ƽ
	while(!DHT11_JudgeLevel())
	{
		
	}
	while(DHT11_JudgeLevel())
	{
		iCount++;
		delay_us(1);
	}
	if(iCount>27)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int16 DHT11_RdByte()
{
	int16 iCount=0,data=0;
	data |=DHT11_RdBit();
	for(iCount=0;iCount<7;iCount++)
	{
		data<<=1;
		data |=DHT11_RdBit();
	}
	return data;
}

void DHT11_ReSet(void)
{
	//�������ģʽ
	DHT11_SetMode(MODE_OUTPUT);
	//���øߵ�ƽ
	DHT11_SetLevel(HIGHT_LEVEL);
	//��ʱ20us
	delay_us(20);
	//���õ͵�ƽ
	DHT11_SetLevel(LOW_LEVEL);
	//��ʱ20us
	delay_ms(20);
	//���øߵ�ƽ
	DHT11_SetLevel(HIGHT_LEVEL);
	delay_us(30);
	DHT11_SetMode(MODE_INPUT);
	
	//�ȴ��͵�ƽ
	while(DHT11_JudgeLevel())
	{
		
	}
	delay_us(80);
	//�ȴ��ߵ�ƽ
	while(!DHT11_JudgeLevel())
	{
		
	}
	delay_us(80);
}

void DHT11_RdDate(int16* temperature,int16* humidity)
{
	int16 value[5]={0},iCount=0;
	DHT11_ReSet();
	DHT11_RdByte();
	for(iCount=0;iCount<5;iCount++)
	{
		value[iCount]=DHT11_RdByte();
	}
	if(value[0]+value[1]+value[2]+value[3]==value[4])
	{
		*temperature=value[0];
		*humidity=value[2];
	}
}


char acbuf[32]={'\0'};

void DHT11_ShowTemperatureAndHumidity()
{
	int16 temperature,humidity;
	DHT11_RdDate(&temperature,&humidity);
	sprintf(acbuf,"�¶ȣ�%d ʪ�ȣ�%d\r\n",temperature,humidity);
	USART1_PutStr(acbuf);
	//LCD_ShowString(30,30,acbuf,24,RED,WHITE);
}
*/

