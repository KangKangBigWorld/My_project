#ifndef _MY_CONTROL_H_
#define _MY_CONTROL_H_
#include "My_View.h"
#include "My_ConIO.h"
#include "Get_KeyValue.h"
#include "User_LinkList.h"
#include "My_FileIO.h"
/**********************************宏定义**************************************/



/***********************************数据类型定义********************************/



/***************************函数原型*********************************************/

/************************************************************************/
/* 
   *函数名称:void MainWIN_Control(void);
   *功能描述:主界面跳转功能
   *参数说明: 
   *         无
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.13            修改人:何亚康
   *描述    :                                                             
                                                                        */
void MainWIN_Control(void);


/************************************************************************/
/* 
   *函数名称:void Login_Control(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PULink pRHead,FILE** pRFp,char* Name_Date_Record);
   *功能描述:登录功能
   *参数说明: 
   *         x,y              控制输入输出框左上角的x,y坐标
   *         pHead            用户链表头结点指针变量
   *         pFp              存放用户文件指针的指针变量
   *         Name_Date_User   存放用文件名字符串的指针
   *         pRHead           记录链表头结点指针变量
   *         pRFp             存放记录文件指针的指针变量
   *         Name_Date_Record 存放记录文件名字符串的指针
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.13            修改人:何亚康
   *描述    :                                                             
                                                                        */
void Login_Control(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PULink pRHead,FILE** pRFp,char* Name_Date_Record);

/************************************************************************/
/* 
   *函数名称: void SignOut_control(void);
   *功能描述:退出功能
   *参数说明: 
   *         无
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.13            修改人:何亚康
   *描述    :                                                             
                                                                        */
void SignOut_Control(void);

/************************************************************************/
/* 
   *函数名称:int FormIO_Control(int x,int y,char* pTips,char* cStr,int iMaxLen,int iPutType,int isPlaintext);
   *功能描述:控制输入输出，配合控制输入框Draw_FormIO();使用
   *参数说明: 
   *         x,y              控制输入输出框左上角的x,y坐标
   *         pTips            控制输入输出框提示词字符串首地址
   *         cStr             控制的字符串首地址
   *         iMaxLen          允许输入的最大长度
   *         iPutType         允许输入的字符类型
   *         isPlaintext      明文或者暗文显示
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.13            修改人:何亚康
   *描述    :                                                             
                                                                        */
int FormIO_Control(int x,int y,char* pTips,char* cStr,int iMaxLen,int iPutType,int isPlaintext);

/************************************************************************/
/* 
   *函数名称:void Register_Control(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User);
   *功能描述:注册功能
   *参数说明: 
   *         x              注册框左上角的x坐标
   *         y              注册框右上角的y坐标
   *         pHead          通用链表头指针
   *         pFp            存放文件头指针的指针变量
   *         Name_Date_User 存放文件名的字符指针
   *         iIDentity      身份
   *返回值  :
   *         pFp             存放文件头指针的指针变量
   *修改记录: 日期：2019.8.13            修改人:何亚康
   *描述    :                                                             
                                                                        */
void Register_Control(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,int iIDentity);

/************************************************************************/
/* 
   *函数名称:void User_Control(PULink pHead,PUser pDate,FILE** pFp,char* Name_Date_User,PULink pRHead,FILE** pRFp,char* Name_Date_Record);
   *功能描述:用户控制模块
   *参数说明: 
   *         pHead            用户链表头结点指针变量
   *         pDate            当前登录用户的数据域
   *         pFp              存放用户文件指针的指针变量
   *         Name_Date_User   存放用文件名字符串的指针
   *         pRHead           记录链表头结点指针变量
   *         pRFp             存放记录文件指针的指针变量
   *         Name_Date_Record 存放记录文件名字符串的指针
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.13            修改人:何亚康
   *描述    :                                                             
                                                                        */
void User_Control(PULink pHead,PUser pDate,FILE** pFp,char* Name_Date_User,PULink pRHead,FILE** pRFp,char* Name_Date_Record);

/************************************************************************/
/* 
   *函数名称:void User_Control(PULink pHead,PUser pDate,FILE** pFp,char* Name_Date_User,PULink pRHead,FILE** pRFp,char* Name_Date_Record);
   *功能描述:管理员控制模块
   *参数说明: 
   *         pHead            用户链表头结点指针变量
   *         pDate            当前登录用户的数据域
   *         pFp              存放用户文件指针的指针变量
   *         Name_Date_User   存放用文件名字符串的指针
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.13            修改人:何亚康
   *描述    :                                                             
                                                                        */
void Admin_Control(PULink pHead,PUser pDate,FILE** pFp,char* Name_Date_User);


/************************************************************************/
/* 
   *函数名称:void Admin_Search_Control(PULink pHead);
   *功能描述:查询功能
   *参数说明: 
   *         pHead          通用链表头指针
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.17            修改人:何亚康
   *描述    :                                                             
                                                                        */
void Admin_Search_Control(PULink pHead);

/************************************************************************/
/* 
   *函数名称:void Page_Print(int x,int y,PULink pHead,int iPage,int iFlag);
   *功能描述:按页数打印用户信息
   *参数说明: 
   *         x              注册框左上角的x坐标
   *         y              注册框右上角的y坐标
   *         pHead          通用链表头指针
   *         iPage          打印的是第几页数
   *         int iFlag      标记的行数
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.17            修改人:何亚康
   *描述    :                                                             
                                                                        */
void Page_Print(int x,int y,PULink pHead,int iPage,int iFlag);


/************************************************************************/
/* 
   *函数名称:void Page_Turning(int x,int y,PULink pHead,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int));
   *功能描述:翻页功能
   *参数说明: 
   *         x              注册框左上角的x坐标
   *         y              注册框右上角的y坐标
   *         pHead          通用链表头指针
   *         My_Print       打印数据的方法的函数指针
   *         Page           打印表格的方法的函数指针
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.17            修改人:何亚康
   *描述    :                                                             
                                                                        */
void Page_Turning(int x,int y,PULink pHead,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int));

/************************************************************************/
/* 
   *函数名称:PULink Select_Identity(PULink pHead,int iIdentity);
   *功能描述:选择链表内的身份，返回新链表头结点指针
   *参数说明: 
   *         pHead          通用链表头指针
   *         iIdentity      需要选择的身份（用户:0 管理员:1）
   *返回值  :
   *         返回新链表头节点指针
   *修改记录: 日期：2019.8.17            修改人:何亚康
   *描述    :                                                             
                                                                        */
PULink Select_Identity(PULink pHead,int iIdentity);


/************************************************************************/
/* 
   *函数名称:PULink Select_UserName(PULink pHead,char* SearchName);
   *功能描述:模糊查询用户名，返回新链表头结点指针
   *参数说明: 
   *         pHead          通用链表头指针
   *         SearchName     需要查询的字符串
   *返回值  :
   *         返回新链表头节点指针
   *修改记录: 日期：2019.8.17            修改人:何亚康
   *描述    :                                                             
                                                                        */
PULink Select_UserName(PULink pHead,char* SearchName);

/************************************************************************/
/* 
   *函数名称:void Fuzzy_Search(PULink pHead);
   *功能描述:模糊查询
   *参数说明: 
   *         pHead          通用链表头指针
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.17            修改人:何亚康
   *描述    :                                                             
                                                                        */
void Fuzzy_Search(PULink pHead);

/************************************************************************/
/* 
   *函数名称:void Admin_Register(PULink pHead,FILE** pFp,char* Name_Date_User);
   *功能描述:管理员注册功能
   *参数说明: 
   *         pHead          通用链表头指针
   *         pFp            存放文件指针的指针变量
   *         Name_Date_User 存放文件名的字符串指针
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.17            修改人:何亚康
   *描述    :                                                             
                                                                        */
void Admin_Register(PULink pHead,FILE** pFp,char* Name_Date_User);

/************************************************************************/
/* 
   *函数名称:void User_Delect(PULink pHead,PUser pDate,FILE** pFp,char* pFilename);
   *功能描述:用户删除
   *参数说明: 
   *         pHead          通用链表头指针
   *         pFp            存放文件指针的指针变量
   *         Name_Date_User 存放文件名的字符串指针
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.21            修改人:何亚康
   *描述    :                                                             
                                                                        */
void User_Delect(PULink pHead,PUser pDate,FILE** pFp,char* pFilename);


/************************************************************************/
/* 
   *函数名称:void User_DelectControl(int x,int y,FILE** pFp,char* pFilename,PULink pHead,PUser pDate,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int));
   *功能描述:删除控制函数
   *参数说明: 
   *         x,y            出现位置坐标
   *         pHead          用户通用链表首地址
   *         pFp            存放用户文件指针的指针函数
   *         Name_Date_User 用户文件名字符串首地址
   *         pDate          用户数据
   *         pRHead          记录通用链表首地址
   *         pRFp            存放记录文件指针的指针函数
   *         Name_Date_Record 记录文件名字符串首地址
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.21            修改人:何亚康
   *描述    :                                                             
                                                                        */
void User_DelectControl(int x,int y,FILE** pFp,char* pFilename,PULink pHead,PUser pDate,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int));

/************************************************************************/
/* 
   *函数名称:int Control_Cancell(int x,int y);
   *功能描述:用户删除
   *参数说明: 
   *         pHead          通用链表头指针
   *         pFp            存放文件指针的指针变量
   *         Name_Date_User 存放文件名的字符串指针
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.21            修改人:何亚康
   *描述    :                                                             
                                                                        */
int Control_Cancell(int x,int y);

/************************************************************************/
/* 
   *函数名称:void User_ChangePassword(PULink pHead,PUser pDate,FILE** pFp,char* pFilename);
   *功能描述:修改用户密码
   *参数说明: 
   *         pHead          通用链表头指针
   *         pDate          用户数据
   *         pFp            文件名
   *         Name_Date_User 存放文件名的字符串指针
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.21            修改人:何亚康
   *描述    :                                                             
                                                                        */
void User_ChangePassword(PULink pHead,PUser pDate,FILE** pFp,char* pFilename);

/************************************************************************/
/* 
   *函数名称:void User_ChangePasswordControl(int x,int y,FILE** pFp,char* pFilename,PULink pHead,PUser pDate,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int));
   *功能描述:控制输入密码
   *参数说明: 
   *         x,y            出现位置坐标
   *         pHead          用户通用链表首地址
   *         pFp            存放用户文件指针的指针函数
   *         Name_Date_User 用户文件名字符串首地址
   *         pDate          用户数据
   *         pRHead          记录通用链表首地址
   *         pRFp            存放记录文件指针的指针函数
   *         Name_Date_Record 记录文件名字符串首地址
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.21            修改人:何亚康
   *描述    :                                                             
                                                                        */
void User_ChangePasswordControl(int x,int y,FILE** pFp,char* pFilename,PULink pHead,PUser pDate,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int));


/************************************************************************/
/* 
   *函数名称:int My_ChangePassword(int x,int y,PUser pDate);
   *功能描述:用户修改密码功能
   *参数说明: 
   *         x,y            出现位置坐标
   *         pDate          用户数据
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.21            修改人:何亚康
   *描述    :                                                             
                                                                        */
int My_ChangePassword(int x,int y,PUser pDate);


/************************************************************************/
/* 
   *函数名称:int My_BalanceQueryControl(int x,int y,PUser pDate);
   *功能描述:用户查询余额
   *参数说明: 
   *         x,y            出现位置坐标
   *         pDate          用户数据
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.21            修改人:何亚康
   *描述    :                                                             
                                                                        */
int My_BalanceQueryControl(int x,int y,PUser pDate);


/************************************************************************/
/* 
   *函数名称:int My_DepositControl(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PUser pDate,PULink pRHead,FILE** pRFp,char* Name_Date_Record);
   *功能描述:存款功能
   *参数说明: 
   *         x,y            出现位置坐标
   *         pHead          用户通用链表首地址
   *         pFp            存放用户文件指针的指针函数
   *         Name_Date_User 用户文件名字符串首地址
   *         pDate          用户数据
   *         pRHead          记录通用链表首地址
   *         pRFp            存放记录文件指针的指针函数
   *         Name_Date_Record 记录文件名字符串首地址
   *返回值  :
   *         成功返回:1
   *         失败返回:0
   *修改记录: 日期：2019.8.21            修改人:何亚康
   *描述    :                                                             
                                                                        */
int My_DepositControl(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PUser pDate,PULink pRHead,FILE** pRFp,char* Name_Date_Record);



/************************************************************************/
/* 
   *函数名称:int My_WithdrawControl(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PUser pDate,PULink pRHead,FILE** pRFp,char* Name_Date_Record);
   *功能描述:取款功能
   *参数说明: 
   *         x,y            出现位置坐标
   *         pHead          用户通用链表首地址
   *         pFp            存放用户文件指针的指针函数
   *         Name_Date_User 用户文件名字符串首地址
   *         pDate          用户数据
   *         pRHead          记录通用链表首地址
   *         pRFp            存放记录文件指针的指针函数
   *         Name_Date_Record 记录文件名字符串首地址
   *返回值  :
   *         成功返回:1
   *         失败返回:0
   *修改记录: 日期：2019.8.21            修改人:何亚康
   *描述    :                                                             
                                                                        */
int My_WithdrawControl(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PUser pDate,PULink pRHead,FILE** pRFp,char* Name_Date_Record);


/************************************************************************/
/* 
   *函数名称:int My_TransferControl(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PUser pDate,PULink pRHead,FILE** pRFp,char* Name_Date_Record);
   *功能描述:转账功能
   *参数说明: 
   *         x,y            出现位置坐标
   *         pHead          用户通用链表首地址
   *         pFp            存放用户文件指针的指针函数
   *         Name_Date_User 用户文件名字符串首地址
   *         pDate          用户数据
   *         pRHead          记录通用链表首地址
   *         pRFp            存放记录文件指针的指针函数
   *         Name_Date_Record 记录文件名字符串首地址
   *返回值  :
   *         成功返回:1
   *         失败返回:0
   *修改记录: 日期：2019.8.21            修改人:何亚康
   *描述    :                                                             
                                                                        */
int My_TransferControl(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PUser pDate,PULink pRHead,FILE** pRFp,char* Name_Date_Record);


/************************************************************************/
/* 
   *函数名称:int My_ChangePasswordControl(int x,int y,PULink pHead,PUser pDate,FILE** pFp,char* Name_Date_User);
   *功能描述:用户修改密码控制函数
   *参数说明: 
   *         x,y            出现位置坐标
   *         pHead          用户通用链表首地址
   *         pFp            存放用户文件指针的指针函数
   *         Name_Date_User 用户文件名字符串首地址
   *         pDate          用户数据
   *返回值  :
   *         成功返回:1
   *         失败返回:0
   *修改记录: 日期：2019.8.21            修改人:何亚康
   *描述    :                                                             
                                                                        */
int My_ChangePasswordControl(int x,int y,PULink pHead,PUser pDate,FILE** pFp,char* Name_Date_User);

/************************************************************************/
/* 
   *函数名称:void User_RecordControl(PULink pHead,PUser pDate);
   *功能描述:用户记录查询控制模块
   *参数说明: 
   *         pHead          用户通用链表首地址
   *         pDate          用户数据
   *返回值  :
   *         成功返回:1
   *         失败返回:0
   *修改记录: 日期：2019.8.21            修改人:何亚康
   *描述    :                                                             
                                                                        */
void User_RecordControl(PULink pHead,PUser pDate);

/************************************************************************/
/* 
   *函数名称:void User_Record(int x,int y,PULink pHead,PUser pDate,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int));
   *功能描述:转账功能
   *参数说明: 
   *         x,y            出现位置坐标
   *         pHead          用户通用链表首地址
   *         pFp            存放用户文件指针的指针函数
   *         Name_Date_User 用户文件名字符串首地址
   *         pDate          用户数据
   *         pRHead          记录通用链表首地址
   *         pRFp            存放记录文件指针的指针函数
   *         Name_Date_Record 记录文件名字符串首地址
   *返回值  :
   *         成功返回:1
   *         失败返回:0
   *修改记录: 日期：2019.8.20            修改人:何亚康
   *描述    :                                                             
                                                                        */
void User_Record(int x,int y,PULink pHead,PUser pDate,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int));


/************************************************************************/
/* 
   *函数名称:void Page_RecordPrint(int x,int y,PULink pHead,int iPage,int iFlag);
   *功能描述:打印记录信息
   *参数说明: 
   *         x,y            出现位置坐标
   *         pHead          用户通用链表首地址
   *         pFp            存放用户文件指针的指针函数
   *         Name_Date_User 用户文件名字符串首地址
   *         pDate          用户数据
   *返回值  :
   *         无
   *修改记录: 日期：2019.8.21            修改人:何亚康
   *描述    :                                                             
                                                                        */
void Page_RecordPrint(int x,int y,PULink pHead,int iPage,int iFlag);


/************************************************************************/
/* 
   *函数名称:PULink Select_RecordID(PULink pHead,int iAimID);
   *功能描述:按ID选择，返回通用链表
   *参数说明: 
   *         pHead          用户通用链表首地址

   *返回值  :
   *         成功则返回通用链表头结点
   *         失败则返回空
   *修改记录: 日期：2019.8.21            修改人:何亚康
   *描述    :                                                             
                                                                        */
PULink Select_RecordID(PULink pHead,int iAimID);


/************************************************************************/
/* 
   *函数名称:int My_DateIO(int x,int y,char * cTitle,int iFlag,int ForthDate);
   *功能描述:控制日期的输入输出
   *参数说明: 
   *         cTitle             标题
   *         iFlag              标志位
   *         ForthDate          前置日期
   *返回值  :
   *         成功则返回1
   *         失败则返回0
   *修改记录: 日期：2019.8.21            修改人:何亚康
   *描述    :                                                             
                                                                        */
int My_DateIO(int x,int y,char * cTitle,int iFlag,int ForthDate);

/************************************************************************/
/* 
   *函数名称:PULink My_DateControl(int x,int y,PULink pHead,PUser pDate);
   *功能描述:日期控制函数
   *参数说明: 
   *         x,y            出现位置坐标
   *         pHead          用户通用链表首地址
   *         pDate          用户数据域头结点
   *返回值  :
   *         成功则返回通用链表头结点
   *         失败则返回空
   *修改记录: 日期：2019.8.21            修改人:何亚康
   *描述    :                                                             
                                                                        */
PULink My_DateControl(int x,int y,PULink pHead,PUser pDate);

/************************************************************************/
/* 
   *函数名称:PULink Select_RecordTIME(PULink pHead,int ForthDate,int BackDate);
   *功能描述:选择记录的时间段
   *参数说明: 
   *         pHead          用户通用链表首地址
   *         ForthDate      起始日期
   *         BackDate       终止日期
   *返回值  :
   *         成功则返回通用链表头结点
   *         失败则返回空
   *修改记录: 日期：2019.8.21            修改人:何亚康
   *描述    :                                                             
                                                                        */
PULink Select_RecordTIME(PULink pHead,int ForthDate,int BackDate);

#endif