
#ifndef __DHT11_H
#define __DHT11_H
#include "stm32f10x.h"
#include "font_show.h"
typedef short int uint_16;
extern char DHT11_tem[10],DHT11_hum[10];
#define MODE_OUT 1  //输出宏
#define MODE_IN 0		//输入宏
#define LEVER_H 1		//高电平宏
#define LEVER_L 0		//低电平宏
void DHT11_Init(void);//通信GPIO初始化
void DHT11_SetMode(u8 mode);//设置模式
void DHT11_SetLever(u8 lever);//设置电平
uint_16 DHT11_ReadLever(void);//读取电平
uint_16 DTH11_ReadBit(void);//读取位
uint_16 DTH11_ReadByte(void);//读取字节
void DHT11_Com_Agreement(void);//通讯协议
uint_16 DHT11_ReadData(u16 *temperature,u16 *humidity);//读取数据
void DHT11_Show_T_H(void);//串口显示温湿度
void DHT11_Show_LCD_T_H(void);//屏幕显示温湿度
#endif


/*




#ifndef _DHT11_H_
#define _DHT11_H_
#include "STM32F10X.h"
#include "SysTick.h"
#include "stdio.h"
#include "tftlcd.h"
#include "string.h"
#include "usart1.h"
typedef  short  int int16;

#define MODE_INPUT 0
#define MODE_OUTPUT 1
#define LOW_LEVEL 0
#define HIGHT_LEVEL 1


//初始化
void DHT11_Init(void);

//设置模式  1输出 0表示输入
void DHT11_SetMode(u8 mode);

//设置高低电平
void DHT11_SetLevel(u8 level);

//判断高低电平
int16 DHT11_JudgeLevel(void);

//获取位
int16 DHT11_RdBit(void);

//获取字节
int16 DHT11_RdByte(void);


//复位
void DHT11_ReSet(void);

//获取数据
void DHT11_RdData(int16* temperature,int16* humidity );

//显示温度
void DHT11_ShowTemperatureAndHumidity(void);
	
	



#endif 
*/


