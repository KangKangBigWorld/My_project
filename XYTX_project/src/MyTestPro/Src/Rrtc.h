#ifndef _RRTC_H_
#define _RRTC_H_

#include "stm32f10x.h"
#include "irq.h"
#include "tftlcd.h"
#include "stm32f10x_rtc.h"
#include "stm32f10x_rcc.h"
#include <string.h>


typedef struct MyTime
{
	uint16_t w_year;
	u8 w_month;
	u8 w_date;
	u8 hour;
	u8 min;
	u8 sec;
	u8 week;
}MY_TIME;

u8 RTC_Get(void);//设置闹钟
/*
函数原型:u8 RTC_Get_Week(u16 year,u8 month,u8 day)
函数功能:根据年月日获取星期
参    数:u16 year,年份
u8 month,月份
u8 day   日
返 回 值:星期号
*/
u8 RTC_Get_Week(u16 year,u8 month,u8 day);

//闰年判断
u8 Is_Leap_Year(u16 year);
/****************************************************************
* 函数名: RTC_Alarm_Set
* 函数功能 : RTC 设置日期时间(1970 1 1为基准 输入的时间转化为秒数)
1970~2099 为合法年份
* 参数: syear,smon,sday,hour,min,sec：闹钟的年月日时分秒  
* 输出 : 0,成功 1,失败
*****************************************************************/
u8 RTC_Alarm_Set(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec);
/****************************************************************
* 函数名: RTC_Set
* 函数功能 : RTC 设置日期时间(1970 1 1为基准 输入的时间转化为秒数)
1970~2099 为合法年份
* 参数: syear:年 smon:月 sday:日 hour:时 min:分 sec:秒
* 输出 : 0,成功 1,失败
*****************************************************************/
u8 RTC_Set(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec);
void RTC_ShowTime(void);

void RTC_Init(void);

void itoa(int i,char* str);

void RTC_pHandle(void);


extern MY_TIME calendar;

#endif

