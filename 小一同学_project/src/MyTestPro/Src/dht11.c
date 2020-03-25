#include "dht11.h"
#include "SysTick.h"
#include <stdio.h>
#include "usart1.h"
#include "My_Function.h"
void DHT11_Init(void)
{
	//选择PA11作为DHT11数据通信口
	RCC->APB2ENR |= (1<<2);
	GPIOA->CRH &= ~(0xF<<3*4);
	GPIOA->CRH |= (3<<3*4);//默认设置通用推挽输出
	GPIOA->ODR |= (1<<11);//默认设置高电平
}
void DHT11_SetMode(u8 mode)
{
	
	GPIOA->CRH &= ~(0xF<<3*4);//寄存器清零
	switch(mode)
	{
		case MODE_IN:
			GPIOA->CRH |= (8<<3*4);//上下拉输入
			break;
		case MODE_OUT:
			GPIOA->CRH |= (3<<3*4);//通用推挽输出
			break;
		default:
				  USART1_PutStr("\r\nDTh11模式设置错误!");
			 break;
	}
}
void DHT11_SetLever(u8 lever)
{
	switch(lever)
	{
		case LEVER_H:
			GPIOA->BSRR |= (1<<11);//高电平输出
			break;
		case LEVER_L:
			GPIOA->BRR |= (1<<11);//低电平输出
			break;
		default:
				  USART1_PutStr("\r\nDTh11高低电平设置错误!");
			 break;
	}
}
uint_16 DHT11_ReadLever(void)
{
	return ((GPIOA->IDR & (1<<11))>>11);//读取输入电平
}
uint_16 DTH11_ReadBit(void)
{
	uint_16 time=0,bit_data;
	while(DHT11_ReadLever());//等待低电平产生
	delay_us(50);//低电平保持50us
	while(!DHT11_ReadLever());//等待高电平产生
	delay_us(1);
	while(DHT11_ReadLever())//记录高电平维持的时间
	{
		time++;
		delay_us(1);
	}
	if(time>27)
	{
		bit_data = 1;//数据为1 
	}
	else
	{
		bit_data = 0;//数据为0
	}
	return bit_data;
}
uint_16 DTH11_ReadByte(void)
{
	uint_16 i,dat=0;
	for(i=0;i<8;i++)//将获取位转化为字节
	{
		dat<<=1;
		dat |= DTH11_ReadBit();
	}
	return dat;
}
void DHT11_Com_Agreement(void)
{
	DHT11_SetMode(MODE_OUT);//设置输出模式
	DHT11_SetLever(LEVER_H);//设置高电平
	delay_us(20);//低电平保持20us
	DHT11_SetLever(LEVER_L);//设置低电平
	delay_ms(20);//低电平保持20ms
	DHT11_SetLever(LEVER_H);//设置高电平
	delay_us(30);//高电平保持30us
	DHT11_SetMode(MODE_IN);//设置输入模式
	while(DHT11_ReadLever());//等待低电平响应
	delay_us(80);//低电平响应保持80us
	while(!DHT11_ReadLever());//等待高电平响应
	delay_us(80);//高电平响应保持80us
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
	Busy("错误:请检查线路并重置");
	stu=DHT11_ReadData(&temperature,&humidity);
	if(stu)
	{
		sprintf(T_H_acbuf,"\r\n温度:%d 湿度:%d",temperature,humidity);
		//USART1_PutStr(T_H_acbuf);
		sprintf(Tem,"%d℃ %d%%",temperature,humidity);
		sprintf(My_Tem,"温度:%d℃",temperature);
		sprintf(My_Hum,"湿度:%d%%",humidity);
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
	//模式设置 输出模式 高电平
	GPIOA->CRH &=~(0xF<<12);
	//推挽式输出
	GPIOA->CRH |=(3<<12); 
	//高电平输出
	GPIOA->ODR |=(1<<11);
}


void DHT11_SetMode(u8 mode)
{
	GPIOA->CRH &=~(0xF<<12);//寄存器清零
	switch(mode)
	{
		case MODE_INPUT:
		{
			GPIOA->CRH |=(8<<12); //上拉下拉输入
		}break;
		case MODE_OUTPUT:
		{
			GPIOA->CRH |=(3<<12);  //推挽式输出
		}break;
		default:
		{
			USART1_PutStr("\r\nDTh11模式设置错误!");
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
			GPIOA->BRR |=(1<<11);//低电平输出
		}break;
		case HIGHT_LEVEL:
		{
			GPIOA->BSRR |=(1<<11);//高电平输出
		}break;
		default:
		{
			USART1_PutStr("\r\nDTh11高低电平设置错误!");
		}
		break;
	}
}


int16 DHT11_JudgeLevel()
{
	return ((GPIOA->IDR & (1<<11))>>11);//读取输入电平
}

int16 DHT11_RdBit()
{
	int16 iCount=0;
	//等待低电平产生
	while(DHT11_JudgeLevel())
	{
		
	}
	//低电平保持50us
	delay_us(50);
	
	//判断是否产生高电平
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
	//设置输出模式
	DHT11_SetMode(MODE_OUTPUT);
	//设置高电平
	DHT11_SetLevel(HIGHT_LEVEL);
	//延时20us
	delay_us(20);
	//设置低电平
	DHT11_SetLevel(LOW_LEVEL);
	//延时20us
	delay_ms(20);
	//设置高电平
	DHT11_SetLevel(HIGHT_LEVEL);
	delay_us(30);
	DHT11_SetMode(MODE_INPUT);
	
	//等待低电平
	while(DHT11_JudgeLevel())
	{
		
	}
	delay_us(80);
	//等待高电平
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
	sprintf(acbuf,"温度：%d 湿度：%d\r\n",temperature,humidity);
	USART1_PutStr(acbuf);
	//LCD_ShowString(30,30,acbuf,24,RED,WHITE);
}
*/

