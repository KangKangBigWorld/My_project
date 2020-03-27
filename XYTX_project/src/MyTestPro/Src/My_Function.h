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
//最大事件值
#define MAX_EVENT 12
//事件是否使能
#define EVENT_ENABLE 1 //事件启动
#define EVENT_DISABLE 0 //事件不启动
//事件是否开启
#define EVENT_OPEN 1   //事件开启
#define EVENT_ClOSE 0   //事件关闭

extern pEVENTS pMainEvents;

//事件初始化
void Event_Init(pEVENTS* pEvent);

//事件添加执行函数
void Event_Install(pEVENTS pEvent,u8 EventNum,u16 x1,u16 y1,u16 x2,u16 y2,pHandle EvevtpHandle);
//事件打开
void Event_Open(pEVENTS pEvent,u8 EventNum);
//事件关闭
void Event_Close(pEVENTS pEvent,u8 EventNum);
//事件重新利用
void Event_Destory(pEVENTS pEvent,u8 EventNum);
//事件管理
void Event_Manager(EVENTS Events[MAX_EVENT]);
//事件初始化
void My_Event_Init(void);
//主事件
void Main_Event(void);
//记事本事件
void Txt_Event(void);
//温湿度事件
void temperature_Event(void);
//音乐设备
void music_Event(void);
//音乐重命名
void Music_Rename(void);
//闹钟设备
void colock_Event(void);

void Eevent_Touch(pEVENTS pEvent);
//退出事件
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
