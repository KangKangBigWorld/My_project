#ifndef _LED_H_
#define _LED_H_
#include "stm32f10x.h"
#include "SysTick.h"
#include "tftlcd.h"



#define LED_OFF 0
#define LED_ON 1
//LED�Ƴ�ʼ��
void LED_Init(void);

//�����ض�xλ�õ�LED��
void LED_Open(int x);

//��������LED��
void LED_OpenAll(void);

//�ر��ص�xλ�õ�LED��
void LED_Close(int x);

//�ر�����LED��
void LED_CloseAll(void);

//LED����ʾ����
void LED_ShowNumber(int x);

//LED����
void LED_Count(void);

//��x��ʼ������ʱ
void LED_CountDown(int x);

//�ҵ�LED����
void My_LED(void);
#endif

















