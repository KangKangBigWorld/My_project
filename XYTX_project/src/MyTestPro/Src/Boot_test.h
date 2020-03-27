#ifndef _BOOT_TEST_H
#define _BOOT_TEST_H
#include "tftlcd.h"
#include "System_Init.h"
#include "Buzzer.h"


void Boot_test(void);

//开机自检背景
void Boot_BackGraound(void);

/*自定义检测*/
void My_test(u16 x,u16 y);

/*等待并打印点*/
void Delay_point(u16 x,u16 y,u8 size,u16 iTime,u32 delay,u16 FG_Color,u16 BG_Color);


void NandFlash(u16 x,u16 y);

#endif




