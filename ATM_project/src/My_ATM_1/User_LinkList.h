#ifndef _USER_LINKLIST_H_
#define _USER_LINKLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Record_LinkLIst.h"

/******************************宏定义******************************************/
#define USER ((int)0)  //身份是用户
#define ADMIN ((int)1) //身份是管理员
#define SUPERADMIN ((int)2) //身份是超级管理员
#define FROZEN ((int)0)  //用户为冻结状态
#define ACTIVE ((int)1)  //用户为活跃状态                                                                    

/***********************************数据类型定义********************************/
typedef struct user//定义用户数据类型
{
	int iID;//用户Id号
    int iIdentity;//用户身份信息
	int iCondition;//账户状态
	char cAccount[12];//英文姓名作为账号
	char cPasswod[8];//密码
	int  iBalance;//账户余额
	int iYear;
	int iMonth;
	int iDay;
}User;

typedef User* PUser;//指向用户数据类型的指针变量

/***************************函数原型*********************************************/

/************************************************************************/
/* 
   *函数名称: PUser User_Init(void);
   *功能描述:初始用户数据类型，并返回其首地址
   *参数说明: 
   *        无
   *返回值  :
   *        成功则返回：PUser       指向用户数据类型的指针变量
   *		失败则返回：NULL        空指针
   *修改记录: 日期：2019.8.9            修改人:何亚康
   *描述    :                                                             
                                                                        */
PUser User_Init(void);

/************************************************************************/
/* 
   *函数名称: void User_SetID(PUser *pDate);
   *功能描述:给一个用户的ID号码重新赋值
   *参数说明: 
   *         pDate        目标用户首地址
   *         iID          ID号码
   *         iIdentity    身份信息
   *         iCondition   状态
   *         pAccount     账号
   *         pPassword    密码
   *         iBalance     余额
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.14            修改人:何亚康
   *描述    :                                                           
                                                                         */
void User_SetAll(PUser pDate,int iID,int iIdentity,int iCondition,char* pAccount,char* pPassword,int iBalance);

/************************************************************************/
/* 
   *函数名称: void User_SetID(int iID,PUser *pDate);
   *功能描述:给一个用户的ID号码重新赋值
   *参数说明: 
   *         iID           新ID号码
   *         pDate        目标用户首地址 
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
void User_SetID(int iID,PUser pDate);

/************************************************************************/
/* 
   *函数名称:void User_SetIdentity(int iIdentity,PUser pDate);
   *功能描述:给一个用户的身份重新赋值
   *参数说明: 
   *         iIdentity     新身份信息
   *         pDate        目标用户首地址 
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
void User_SetIdentity(int iIdentity,PUser pDate);

/************************************************************************/
/* 
   *函数名称:void User_SetCondition(int iCondition,PUser pDate);
   *功能描述:给一个用户的状态信息重新赋值
   *参数说明: 
   *         iCondition   新的账号状态
   *         pDate        目标用户首地址 
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
void User_SetCondition(int iCondition,PUser pDate);

/************************************************************************/
/* 
   *函数名称:void User_SetAccount(char* pAccoount,PUser pDate);
   *功能描述:给一个用户的账号重新赋值
   *参数说明: 
   *         pAccoount     新账号的首地址
   *         *pDate        目标用户首地址 
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
void User_SetAccount(char* pAccoount,PUser pDate);

/************************************************************************/
/* 
   *函数名称:void User_SetPassword(char* pPassword,PUser pDate);
   *功能描述:给一个用户的密码重新赋值
   *参数说明: 
   *         pPassword     新密码首地址
   *         *pDate        目标用户首地址 
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
void User_SetPassword(char* pPassword,PUser pDate);

/************************************************************************/
/* 
   *函数名称:void User_SetBalance(int iBalance,PUser pDate);
   *功能描述:给一个用户的余额重新赋值
   *参数说明: 
   *         iBalance      新的余额数据
   *         *pDate        目标用户首地址 
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
void User_SetBalance(int iBalance,PUser pDate);

/************************************************************************/
/* 
   *函数名称:int User_GetID(PUser pDate);
   *功能描述:获取目标用户ID
   *参数说明: 
   *         pDate        目标用户首地址 
   *返回值  :
   *         iID          目标用户ID
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
int User_GetID(PUser pDate);

/************************************************************************/
/* 
   *函数名称:int User_GetIdentity(PUser pDate);
   *功能描述:获取目标用户身份信息
   *参数说明: 
   *         pDate        目标用户首地址 
   *返回值  :
   *         iIdentity    目标用户身份信息
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
int User_GetIdentity(PUser pDate);

/************************************************************************/
/* 
   *函数名称:int User_GetCondition(PUser pDate);
   *功能描述:获取目标用户身份信息
   *参数说明: 
   *         pDate        目标用户首地址 
   *返回值  :
   *         iIdentity    目标用户身份信息
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
int User_GetCondition(PUser pDate);

/************************************************************************/
/* 
   *函数名称:char* User_GetAccount(PUser pDate);
   *功能描述:获取目标用户状态信息
   *参数说明: 
   *         pDate        目标用户首地址 
   *返回值  :
   *         cAccount     目标用户状态信息
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
char* User_GetAccount(PUser pDate);

/************************************************************************/
/* 
   *函数名称:char* User_GetPassword(PUser pDate);
   *功能描述:获取目标用户密码信息
   *参数说明: 
   *         pDate        目标用户首地址 
   *返回值  :
   *         cPassword    目标用户密码信息
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
char* User_GetPassword(PUser pDate);

/************************************************************************/
/* 
   *函数名称:int User_GetBalance(PUser pDate);
   *功能描述:获取目标用户余额信息
   *参数说明: 
   *         pDate        目标用户首地址 
   *返回值  :
   *         iBalance     目标用户余额信息
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
int User_GetBalance(PUser pDate);

/************************************************************************/
/* 
   *函数名称:void User_PrtID(void pDate);
   *功能描述:打印目标用户ID信息
   *参数说明: 
   *         pDate        目标用户首地址 
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
void User_PrtID(void* pDate);

/************************************************************************/
/* 
   *函数名称:void User_PrtIdentity(void pDate);
   *功能描述:打印目标用户身份信息
   *参数说明: 
   *         pDate        目标用户首地址 
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
void User_PrtIdentity(void* pDate);

/************************************************************************/
/* 
   *函数名称:void User_PrtCondition(void pDate);
   *功能描述:打印目标用户状态信息
   *参数说明: 
   *         pDate        目标用户首地址 
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
void User_PrtCondition(void* pDate);

/************************************************************************/
/* 
   *函数名称:void User_PrtAccount(void pDate);
   *功能描述:打印目标用户账号信息
   *参数说明: 
   *         pDate        目标用户首地址 
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
void User_PrtAccount(void* pDate);

/************************************************************************/
/* 
   *函数名称:void User_PrtPassword(void pDate);
   *功能描述:打印目标用户密码信息
   *参数说明: 
   *         pDate        目标用户首地址 
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
void User_PrtPassword(void* pDate);

/************************************************************************/
/* 
   *函数名称:void User_PrtBalance(void pDate);
   *功能描述:打印目标用户余额信息
   *参数说明: 
   *         pDate        目标用户首地址 
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                           
                                                                         */
void User_PrtBalance(void* pDate);

/************************************************************************/
/* 
   *函数名称:int User_Accountcmp(void* pDate,void* ch);
   *功能描述:判断账号字符串是否出现在结构体中
   *参数说明: 
   *         pDate        目标用户首地址 
   *         ch           要比较的字符串首地址
   *返回值  :
   *         成功则返回：1
   *         失败则返回：0
   *修改记录: 日期：2019.8.14            修改人:何亚康
   *描述    :                                                           
                                                                         */
int User_Accountcmp(void* pDate,void* ch);

/************************************************************************/
/* 
   *函数名称:int User_Passwordcmp(void* pDate,void* ch);int User_Accountcmp(void* pDate,void* ch);
   *功能描述:判断密码字符串是否出现在结构体中
   *参数说明: 
   *         pDate        目标用户首地址 
   *         ch           要比较的字符串首地址
   *返回值  :
   *         成功则返回：1
   *         失败则返回：0
   *修改记录: 日期：2019.8.14            修改人:何亚康
   *描述    :                                                           
                                                                         */
int User_Passwordcmp(void* pDate,void* ch);

/************************************************************************/
/* 
   *函数名称:int User_IDcmp(void* pDate,void* ch);
   *功能描述:比较ID
   *参数说明: 
   *         pDate        目标用户首地址 
   *         ch           要比较的字符串首地址
   *返回值  :
   *         成功则返回：1
   *         失败则返回：0
   *修改记录: 日期：2019.8.14            修改人:何亚康
   *描述    :                                                           
                                                                         */
int User_IDcmp(void* pDate,void* ch);


/************************************************************************/
/*                                                                      
   *函数名称:void SetRegister_Date(PUser pDate);
   *功能描述:设置注册的时间
   *参数说明:
   *        pDate     设置当前登录时间
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.18            修改人:何亚康
   *描述    :
　
                                                                        */
void SetRegister_Date(PUser pDate);

#endif