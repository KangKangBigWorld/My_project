#ifndef _RRTC_H_
#define _RRTC_H_

#include "stm32f10x.h"
#include "irq.h"
#include "tftlcd.h"
#include "stm32f10x_rtc.h"
#include "stm32f10x_rcc.h"
#include <string.h>


typedef struct MyTime
{
	uint16_t w_year;
	u8 w_month;
	u8 w_date;
	u8 hour;
	u8 min;
	u8 sec;
	u8 week;
}MY_TIME;

u8 RTC_Get(void);//��������
/*
����ԭ��:u8 RTC_Get_Week(u16 year,u8 month,u8 day)
��������:���������ջ�ȡ����
��    ��:u16 year,���
u8 month,�·�
u8 day   ��
�� �� ֵ:���ں�
*/
u8 RTC_Get_Week(u16 year,u8 month,u8 day);

//�����ж�
u8 Is_Leap_Year(u16 year);
/****************************************************************
* ������: RTC_Alarm_Set
* �������� : RTC ��������ʱ��(1970 1 1Ϊ��׼ �����ʱ��ת��Ϊ����)
1970~2099 Ϊ�Ϸ����
* ����: syear,smon,sday,hour,min,sec�����ӵ�������ʱ����  
* ��� : 0,�ɹ� 1,ʧ��
*****************************************************************/
u8 RTC_Alarm_Set(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec);
/****************************************************************
* ������: RTC_Set
* �������� : RTC ��������ʱ��(1970 1 1Ϊ��׼ �����ʱ��ת��Ϊ����)
1970~2099 Ϊ�Ϸ����
* ����: syear:�� smon:�� sday:�� hour:ʱ min:�� sec:��
* ��� : 0,�ɹ� 1,ʧ��
*****************************************************************/
u8 RTC_Set(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec);
void RTC_ShowTime(void);

void RTC_Init(void);

void itoa(int i,char* str);

void RTC_pHandle(void);


extern MY_TIME calendar;

#endif

