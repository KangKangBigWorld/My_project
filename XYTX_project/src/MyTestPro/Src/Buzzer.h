#ifndef _BUZZER_H_
#define _BUZZER_H_

#include "stm32f10x.h"
#include "SysTick.h"

//初始化蜂鸣器
void Buzzer_Init(void);
//打开蜂鸣器
void Buzzer_Open(void);
//关闭蜂鸣器
void Buzzer_Close(void);

void Buzzer_Lien(void);

void Buzzer_Lien2(void);
#endif
