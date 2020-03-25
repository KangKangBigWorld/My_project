#ifndef _USART1_H_
#define _USART1_H_
#include <string.h>
#include "irq.h"
#include "stm32f10x.h"
#include "LED.h"

#define MAX_STR 200

typedef struct my_Time
{
	uint16_t w_year;
	u8 w_month;
	u8 w_date;
	u8 hour;
	u8 min;
	u8 sec;
}my_TIME;


void USART1_Init(void);

void USART1_pHandle(void);

u8 USART1_GetChar(void);

void USART1_GetStr(char* str);

void USART1_PutChar(char ch);

void USART1_PutStr(char* str);

void Soft_Reset(void);

//写内存
void Write_Mem(char *CmdStr);
//读内存
void Read_Mem(char *CmdStr);
//获取时间
void My_GetTime(char* Str);
#endif

