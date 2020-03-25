#ifndef _TIME_IRQ_H_
#define _TIME_IRQ_H_

#include "stm32f10x.h"
#include "Irq.h"

#define MAX_TS 5  //最大定时数目
#define TIME_IS_ENABLE 1 //定时器启动
#define TIME_IS_DISABLE 0 //定时器不启动
#define TIME_IS_OPEN 1   //定时器开启
#define TIME_IS_ClOSE 0   //定时器关闭

typedef enum
{
	TIME2,
	TIME3,
	TIME4,
	TIME5,
}MyTIMx;

extern SOFTM_TS SoftTime_Events[MAX_TS];

/*-------------------------定时器中断-----------------------------*/
//硬定时器TIM2-5初始化
void TIME_Init(void);
//硬定时器安装
void TIMEx_Install(MyTIMx TIMEx,int ms,IRQ_pHandle pHandle);


/*-------------------------软定时器-----------------------------*/


void TIMER_TS_Init(void);//软中断初始化

void TIMER_TS_Install(int RTIMEx,int count,IRQ_pHandle TmpHandle);//软中断添加执行函数

void TIMER_TS_Open(int RTIMEx);//软中断开启

void TIMER_TS_Close(int RTIMEx);//软中断停止
	


void TIMER_TS_Destory(int RTIMEx);//中断重新利用

//TIM2中断执行函数
void TIMER_TS_Manager(void);//软中断总管理

#endif

