#ifndef _COLOCK_H_
#define _COLOCK_H_

#include "My_view.h"
#include "tftlcd.h"
#include "font_show.h"
#include "picture.h"

#include "touch.h"
#include <stdlib.h>
#include "stm32f10x.h"
#include "SysTick.h"

#include "Time_IRQ.h"
#include "LED.h"
#include "Rrtc.h"

#include "Buzzer.h"
#include "My_Function.h"


typedef void (*pHandle)();
typedef struct Clock
{
	u8 hour;
	u8 min;
	u8 isRepeat;//�Ƿ��ظ�
	u8 isEnable;//�Ƿ�ʹ��
	u8 isOpen;//�Ƿ��
	u8 Ring;
	u8 isRing;
	pHandle Event_pHandle;
}CLOCKS;

typedef CLOCKS* pCLOCKS;


//�������ӵ�����
#define CLOCKNUM 3
//�ṹ��Ĵ�С
#define SIZEOFCLOCKS sizeof(CLOCKS)
//�����Ƿ��ظ�
#define CLOCK_REPEAT 1 //�����ظ�
#define CLOCK_NOREPEAT  0 //���Ӳ��ظ�
//�����Ƿ�ʹ��
#define CLOCK_ENABLE 1 //��������
#define CLOCK_DISABLE 0 //���Ӳ�����
//�����Ƿ���
#define CLOCK_OPEN 1   //���ӿ���
#define CLOCK_CLOSE 0   //���ӹر�
//�����Ƿ����
#define CLOCK_RING 1   //�������
#define CLOCK_NORING 0   //����û���

extern CLOCKS My_Colock[CLOCKNUM];


//���ӳ�ʼ��
void Colock_Init(CLOCKS My_Clock[CLOCKNUM]);
//���Ӱ�װ
void Clock_Install(CLOCKS My_Clock[CLOCKNUM],u8 ClockNum,u8 hour,u8 min,u8 isRepeat,pHandle EvevtpHandle);
//���ӿ���
void Clock_Open(CLOCKS My_Clock[CLOCKNUM],u8 ClockNum);
//���ӹر�
void Clock_Close(CLOCKS My_Clock[CLOCKNUM],u8 ClockNum);
//������������
void Clock_Destory(CLOCKS My_Clock[CLOCKNUM],u8 ClockNum);
//���ӹ���
void CLock_Manager(void);

void Show_Clock(u16 x,u16 y,pCLOCKS My_Colock);
//��ʾ��������
void My_Show_Clock(void);




void Change_Clock_Background(void);

void Add_Clock(void);

void Change_Clock(pCLOCKS My_Colock);
//�޸�����
void My_ChangeClock(void);
//��/�ر�����
void My_OpenClock(void);
//ɾ��
void My_DeleteClock(void);

//�޸����ӽ���Ĵ�����
void My_OpenClock2(void);
//�޸����ӽ����ɾ������
void My_DeleteClock2(void);

//�޸����ӽ����Сʱ����
void My_ChangeHour_Up(void);
//�޸����ӽ����Сʱ�½�
void My_ChangeHour_Down(void);
//�޸����ӽ���ķ�������
void My_ChangeMin_Up(void);
//�޸����ӽ���ķ����½�
void My_ChangeMin_Down(void);

//�޸����ӽ���ĸı��ظ�Ϊÿ��
void My_ChangeRepeat_Daily(void);
//�޸����ӽ���ĸı��ظ�Ϊһ��
void My_ChangeRepeat_OnlyOne(void);
//�޸����ӽ��������Ϊ����
void My_ChangeRing_KC(void);
//�޸����ӽ��������Ϊ����
void My_ChangeRing_ZX(void);
//�޸����ӽ����ȡ���޸�
void My_Cancel(void);
//�޸����ӽ���ı����޸�
void My_Save(void);
//����ɾ�������϶���
void Clock_UpLine(void);
//���ӵ��������������
void Clock_Sound(void);

#endif






