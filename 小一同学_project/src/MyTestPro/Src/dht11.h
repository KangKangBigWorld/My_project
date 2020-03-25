
#ifndef __DHT11_H
#define __DHT11_H
#include "stm32f10x.h"
#include "font_show.h"
typedef short int uint_16;
extern char DHT11_tem[10],DHT11_hum[10];
#define MODE_OUT 1  //�����
#define MODE_IN 0		//�����
#define LEVER_H 1		//�ߵ�ƽ��
#define LEVER_L 0		//�͵�ƽ��
void DHT11_Init(void);//ͨ��GPIO��ʼ��
void DHT11_SetMode(u8 mode);//����ģʽ
void DHT11_SetLever(u8 lever);//���õ�ƽ
uint_16 DHT11_ReadLever(void);//��ȡ��ƽ
uint_16 DTH11_ReadBit(void);//��ȡλ
uint_16 DTH11_ReadByte(void);//��ȡ�ֽ�
void DHT11_Com_Agreement(void);//ͨѶЭ��
uint_16 DHT11_ReadData(u16 *temperature,u16 *humidity);//��ȡ����
void DHT11_Show_T_H(void);//������ʾ��ʪ��
void DHT11_Show_LCD_T_H(void);//��Ļ��ʾ��ʪ��
#endif


/*




#ifndef _DHT11_H_
#define _DHT11_H_
#include "STM32F10X.h"
#include "SysTick.h"
#include "stdio.h"
#include "tftlcd.h"
#include "string.h"
#include "usart1.h"
typedef  short  int int16;

#define MODE_INPUT 0
#define MODE_OUTPUT 1
#define LOW_LEVEL 0
#define HIGHT_LEVEL 1


//��ʼ��
void DHT11_Init(void);

//����ģʽ  1��� 0��ʾ����
void DHT11_SetMode(u8 mode);

//���øߵ͵�ƽ
void DHT11_SetLevel(u8 level);

//�жϸߵ͵�ƽ
int16 DHT11_JudgeLevel(void);

//��ȡλ
int16 DHT11_RdBit(void);

//��ȡ�ֽ�
int16 DHT11_RdByte(void);


//��λ
void DHT11_ReSet(void);

//��ȡ����
void DHT11_RdData(int16* temperature,int16* humidity );

//��ʾ�¶�
void DHT11_ShowTemperatureAndHumidity(void);
	
	



#endif 
*/


