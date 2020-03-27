#ifndef _MY_FUNCTION_
#define _MY_FUNCTION_

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
#include "colock.h"
#include "My_Init.h"
typedef void (*pHandle)();

typedef struct Events
{
	u16 Key_X1;
	u16 Key_Y1;
	u16 Key_X2;
	u16 Key_Y2;
	u8 isEnable;
	u8 isOpen;
	pHandle Event_pHandle;
}EVENTS;

typedef EVENTS* pEVENTS;


#define SIZEOF_EVENTS sizeof(EVENTS)
//����¼�ֵ
#define MAX_EVENT 12
//�¼��Ƿ�ʹ��
#define EVENT_ENABLE 1 //�¼�����
#define EVENT_DISABLE 0 //�¼�������
//�¼��Ƿ���
#define EVENT_OPEN 1   //�¼�����
#define EVENT_ClOSE 0   //�¼��ر�

extern pEVENTS pMainEvents;

//�¼���ʼ��
void Event_Init(pEVENTS* pEvent);

//�¼����ִ�к���
void Event_Install(pEVENTS pEvent,u8 EventNum,u16 x1,u16 y1,u16 x2,u16 y2,pHandle EvevtpHandle);
//�¼���
void Event_Open(pEVENTS pEvent,u8 EventNum);
//�¼��ر�
void Event_Close(pEVENTS pEvent,u8 EventNum);
//�¼���������
void Event_Destory(pEVENTS pEvent,u8 EventNum);
//�¼�����
void Event_Manager(EVENTS Events[MAX_EVENT]);
//�¼���ʼ��
void My_Event_Init(void);
//���¼�
void Main_Event(void);
//���±��¼�
void Txt_Event(void);
//��ʪ���¼�
void temperature_Event(void);
//�����豸
void music_Event(void);
//����������
void Music_Rename(void);
//�����豸
void colock_Event(void);

void Eevent_Touch(pEVENTS pEvent);
//�˳��¼�
void Exit(void);


extern pEVENTS pMainEvents;
extern pEVENTS pTxt;
extern pEVENTS pTemperature;
extern pEVENTS pMusic;
extern pEVENTS pMusicRename;
extern pEVENTS pColock;
extern pEVENTS pChangeColock;
extern u8 Exit_Flag;
extern u8 Wendu_Flag;
#endif
