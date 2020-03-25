#ifndef _LED_H_
#define _LED_H_
#include "stm32f10x.h"
#include "SysTick.h"
#include "tftlcd.h"



#define LED_OFF 0
#define LED_ON 1
//LED灯初始化
void LED_Init(void);

//开启特定x位置的LED灯
void LED_Open(int x);

//开启所有LED灯
void LED_OpenAll(void);

//关闭特点x位置的LED灯
void LED_Close(int x);

//关闭所有LED灯
void LED_CloseAll(void);

//LED灯显示数字
void LED_ShowNumber(int x);

//LED正数
void LED_Count(void);

//从x开始倒数计时
void LED_CountDown(int x);

//我的LED功能
void My_LED(void);
#endif

















