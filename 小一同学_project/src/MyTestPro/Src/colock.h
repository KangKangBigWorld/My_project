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
	u8 isRepeat;//是否重复
	u8 isEnable;//是否使能
	u8 isOpen;//是否打开
	u8 Ring;
	u8 isRing;
	pHandle Event_pHandle;
}CLOCKS;

typedef CLOCKS* pCLOCKS;


//定义闹钟的数量
#define CLOCKNUM 3
//结构体的大小
#define SIZEOFCLOCKS sizeof(CLOCKS)
//闹钟是否重复
#define CLOCK_REPEAT 1 //闹钟重复
#define CLOCK_NOREPEAT  0 //闹钟不重复
//闹钟是否使能
#define CLOCK_ENABLE 1 //闹钟启动
#define CLOCK_DISABLE 0 //闹钟不启动
//闹钟是否开启
#define CLOCK_OPEN 1   //闹钟开启
#define CLOCK_CLOSE 0   //闹钟关闭
//闹钟是否响过
#define CLOCK_RING 1   //闹钟响过
#define CLOCK_NORING 0   //闹钟没响过

extern CLOCKS My_Colock[CLOCKNUM];


//闹钟初始化
void Colock_Init(CLOCKS My_Clock[CLOCKNUM]);
//闹钟安装
void Clock_Install(CLOCKS My_Clock[CLOCKNUM],u8 ClockNum,u8 hour,u8 min,u8 isRepeat,pHandle EvevtpHandle);
//闹钟开启
void Clock_Open(CLOCKS My_Clock[CLOCKNUM],u8 ClockNum);
//闹钟关闭
void Clock_Close(CLOCKS My_Clock[CLOCKNUM],u8 ClockNum);
//闹钟重新利用
void Clock_Destory(CLOCKS My_Clock[CLOCKNUM],u8 ClockNum);
//闹钟管理
void CLock_Manager(void);

void Show_Clock(u16 x,u16 y,pCLOCKS My_Colock);
//显示所有闹钟
void My_Show_Clock(void);




void Change_Clock_Background(void);

void Add_Clock(void);

void Change_Clock(pCLOCKS My_Colock);
//修改闹钟
void My_ChangeClock(void);
//打开/关闭闹钟
void My_OpenClock(void);
//删除
void My_DeleteClock(void);

//修改闹钟界面的打开闹钟
void My_OpenClock2(void);
//修改闹钟界面的删除闹钟
void My_DeleteClock2(void);

//修改闹钟界面的小时上升
void My_ChangeHour_Up(void);
//修改闹钟界面的小时下降
void My_ChangeHour_Down(void);
//修改闹钟界面的分钟上升
void My_ChangeMin_Up(void);
//修改闹钟界面的分钟下降
void My_ChangeMin_Down(void);

//修改闹钟界面的改变重复为每天
void My_ChangeRepeat_Daily(void);
//修改闹钟界面的改变重复为一次
void My_ChangeRepeat_OnlyOne(void);
//修改闹钟界面的铃声为开场
void My_ChangeRing_KC(void);
//修改闹钟界面的铃声为仲夏
void My_ChangeRing_ZX(void);
//修改闹钟界面的取消修改
void My_Cancel(void);
//修改闹钟界面的保存修改
void My_Save(void);
//闹钟删除后向上对齐
void Clock_UpLine(void);
//闹钟的响起的其它功能
void Clock_Sound(void);

#endif






