#ifndef _BUZZER_H_
#define _BUZZER_H_

#include "stm32f10x.h"
#include "SysTick.h"

//��ʼ��������
void Buzzer_Init(void);
//�򿪷�����
void Buzzer_Open(void);
//�رշ�����
void Buzzer_Close(void);

void Buzzer_Lien(void);

void Buzzer_Lien2(void);
#endif
