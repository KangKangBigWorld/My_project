#ifndef _BOOT_TEST_H
#define _BOOT_TEST_H
#include "tftlcd.h"
#include "System_Init.h"
#include "Buzzer.h"


void Boot_test(void);

//�����Լ챳��
void Boot_BackGraound(void);

/*�Զ�����*/
void My_test(u16 x,u16 y);

/*�ȴ�����ӡ��*/
void Delay_point(u16 x,u16 y,u8 size,u16 iTime,u32 delay,u16 FG_Color,u16 BG_Color);


void NandFlash(u16 x,u16 y);

#endif




