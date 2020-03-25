#ifndef _RECORD_LINKLIST_H_
#define _RECORD_LINKLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "Universal_Linklist.h"
#include "My_View.h"
/**********************************宏定义**************************************/
#define DEPOSIT    1
#define WITHDRAW   2
#define TURNOUT    3
#define TURNIN     4

/***********************************数据类型定义********************************/
typedef struct  My_times
{
	int iSec; /* 秒 – 取值区间为[0,59] */
	int iMin; /* 分 - 取值区间为[0,59] */
	int iHour; /* 时 - 取值区间为[0,23] */
	int iMDay; /* 一个月中的日期 - 取值区间为[1,31] */
	int iMon; /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] */
	int iYear; /* 年份，其值等于实际年份减去1900 */
	int iWDay; /* 星期 – 取值区间为[0,6]，其中0代表星期天，1代表星期一，以此类推 */
	int iYDay; /* 从每年的1月1日开始的天数 – 取值区间为[0,365]，其中0代表1月1日，1代表1月2日，以此类推 */
	int iIsDst; /* 夏令时标识符，实行夏令时的时候，tm_isdst为正。不实行夏令时的进候，tm_isdst为0；不了解情况时，tm_isdst()为负。*/
}TIME;

typedef struct Record_Link
{
	int iSourseID;//源ID号码
	int iAimID;//目标ID号码
	int iDateNum;//流水号前半段 日期
	int iTimeNum;//流水号后半段 时刻
	int iSec; /* 秒 – 取值区间为[0,59] */
	int iMin; /* 分 - 取值区间为[0,59] */
	int iHour; /* 时 - 取值区间为[0,23] */
	int iDay; /* 一个月中的日期 - 取值区间为[1,31] */
	int iMonth; /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] */
	int iYear; /* 年份，其值等于实际年份减去1900 */
	int iDealMoney;//交易金额
	int iDealType;//交易类型
	int iBeforeMoney;//交易前余额
	int iAfterMoney;//交易后余额

}Record;

typedef Record* PRecord;

/***************************函数原型*********************************************/

/************************************************************************/
/* 
   *函数名称:PRECORD RLink_Init();
   *功能描述:初始记录数据类型，并返回其首地址
   *参数说明: 
   *        无
   *返回值  :
   *        成功则返回：PRECORD       指向用户数据类型的指针变量
   *		失败则返回：NULL        空指针
   *修改记录: 日期：2019.8.19            修改人:何亚康
   *描述    :                                                             
                                                                        */
PRecord RLink_Init();

/************************************************************************/
/* 
   *函数名称:void Set_RecordTime(PRECORD pDate);
   *功能描述:写入当前时间到记录的结构体中
   *参数说明: 
   *         pDate                  指向记录的指针变量
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.19            修改人:何亚康
   *描述    :                                                             
                                                                        */
void Set_RecordTime(PRecord pDate);

/************************************************************************/
/* 
   *函数名称:void Set_RecordTime(PRECORD pDate);
   *功能描述:写入数据到记录的结构体中
   *参数说明: 
   *         pDate                  指向记录的指针变量
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.19            修改人:何亚康
   *描述    :                                                             
                                                                        */
void Set_RecordInfor(PRecord pDate,int iSourseID,int iAimID,int iDealMoney,int iDealType,int iBeforeMoney,int iAfterMoney);



/************************************************************************/
/*                                                                      
   *函数名称:int My_DateStrToInt(char* cYear,char* cMonth,char* cDay);
   *功能描述:传入时间字符串，返回对应的iDateNum
   *参数说明:
   *         cYear             年字符串首地址
   *         cMonth            月字符串首地址
   *         cDay              天字符串首地址
   *返回值  :
   *         iDateNum                时间代码      
   *修改记录: 日期：2019.8.19            修改人:何亚康
   *描述    :
　
                                                                        */
int My_DateStrToInt(char* cYear,char* cMonth,char* cDay);

/************************************************************************/
/*                                                                      
   *函数名称:int My_DateStrToInt(char* cYear,char* cMonth,char* cDay);
   *功能描述:传入时间字符串，返回对应的iDateNum
   *参数说明:
   *         cYear             年字符串首地址
   *         cMonth            月字符串首地址
   *         cDay              天字符串首地址
   *返回值  :
   *         iDateNum                时间代码      
   *修改记录: 日期：2019.8.19            修改人:何亚康
   *描述    :
　
                                                                        */
int Date_Comparison(int ForthDate,int BackDate);


/************************************************************************/
/*                                                                      
   *函数名称:int My_DealMoney(char* cDealMoney);
   *功能描述:传入时间字符串，返回对应的iDateNum
   *参数说明:
   *         cDealMoney              操作金额的字符串首地址
   *返回值  :
   *         iDateMoney              操作金额整型      
   *修改记录: 日期：2019.8.19            修改人:何亚康
   *描述    :
　
                                                                        */
int My_DealMoney(int x,int y,char* cDealMoney);


/************************************************************************/
/*                                                                      
   *函数名称:int My_TransferMoney(int x,int y,char* cDealMoney);
   *功能描述:传入时间字符串，返回对应的iDateNum(转账)
   *参数说明:
   *         cDealMoney              操作金额的字符串首地址
   *返回值  :
   *         iDateMoney              操作金额整型      
   *修改记录: 日期：2019.8.19            修改人:何亚康
   *描述    :
　
                                                                        */
int My_TransferMoney(int x,int y,char* cDealMoney);


/************************************************************************/
/*                                                                      
   *函数名称:int My_DateStrToInt(char* cYear,char* cMonth,char* cDay);
   *功能描述:传入时间字符串，返回对应的iDateNum
   *参数说明:
   *         cYear             年字符串首地址
   *         cMonth            月字符串首地址
   *         cDay              天字符串首地址
   *返回值  :
   *         iDateNum          时间代码      
   *修改记录: 日期：2019.8.19            修改人:何亚康
   *描述    :
　
                                                                        */
int Date_Effective(char* cYear,char* cMonth,char* cDay);

/************************************************************************/
/*                                                                      
   *函数名称:void My_Date(void);
   *功能描述:打印当前年月日
   *参数说明:
   *        无
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.13            修改人:何亚康
   *描述    :
　
                                                                        */
void My_Date(void);


/************************************************************************/
/*                                                                      
   *函数名称:void My_WeekDay(void);
   *功能描述:打印当前星期几
   *参数说明:
   *        无
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.13            修改人:何亚康
   *描述    :
　
                                                                        */
void My_WeekDay(void);

/************************************************************************/
/*                                                                      
   *函数名称:PULink Select_RLinkID(PULink pHead,int iID);
   *功能描述:根据iID的值返回一条数据域是pDate(Record)的通用链表头结点
   *参数说明:
   *          pHead              数据域是Record的通用链表头结点
   *          iID                要搜索的用户ID
   *返回值  :
   *          pTemp              存放要创建的通用链表首地址
   *修改记录: 日期：2019.8.19            修改人:何亚康
   *描述    :
　
                                                                        */
PULink Select_RLinkID(PULink pHead,int iID);

#endif