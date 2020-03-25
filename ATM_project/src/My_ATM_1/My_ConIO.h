#ifndef _MY_CONIO_H_
#define _MY_CONIO_H_
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Universal_Linklist.h"
#include "GoTo_XY.h"

/******************************宏定义***************************************/
#define NUMBER     1  //数字
#define LETTER     2  //字母
#define NUMANDLET  3  //数字与字母
#define DARKTEXT   0  //暗文显示
#define PLAINTEXT  1  //明文显示
#define BACKSPACE  8  //BACKSPACE键键值
#define TAB        9  //换行键键值
#define ENTER     13  //回车键键值
#define ESC       27  //ESC键键值
#define KEY_UP    72  //↑键键值
#define KEY_LEFT  75  //←键键值
#define KEY_RIGHT 77  //→键键值
#define KEY_DOWN  80  //↓键键值


/******************************结构体定义***************************************/
typedef struct CLink
{
char ch;
struct CLink * pNext;
}CLink;

typedef CLink* PCLink;//指向CLink链表的指针变量


/******************************函数原型***************************************/


/************************************************************************/
/* 
   *函数名称:int My_ConIO(char *cStr,int iMaxLen,int iPutType,int isPlaintext,int x,int y);
   *功能描述:控制输入函数
   *参数说明: 
   *          cStr               数组首地址参数
   *          iMaxLen            最大允许输入长度参数
   *          iPutType           允许输入的字符类型标志参数
   *          isPlaintext        是否明文输出控制标志参数
   *          x,y                开始显示的光标位置
   *返回值  :
   *          退出时按键的键值
   *修改记录: 日期：2019.8.13            修改人:何亚康
   *描述    :                                                             
                                                                        */
int My_ConIO(char *cStr,int iMaxLen,int iPutType,int isPlaintext,int x,int y);

/************************************************************************/
/* 
   *函数名称:PCLink CLink_Init(void);
   *功能描述:初始化CLink链表
   *参数说明: 
   *        无
   *返回值  :
   *        成功则返回：PCLink      指向通用链表头结点的指针变量
   *		失败则返回：NULL        空指针
   *修改记录: 日期：2019.8.11            修改人:何亚康
   *描述    :                                                             
                                                                        */
PCLink CLink_Init(void);

/************************************************************************/
/* 
   *函数名称:PCLink CLink_GetNode(PCLink pHead,int index);
   *功能描述:获取CLink链表中的某个节点
   *参数说明:
   *        pHead       通用链表头结点的指针变量实际参数
   *        iIndex      需要获取的节点的顺序号
   *返回值  :
   *        成功则返回：pHead       指向目标节点的指针变量
   *        失败则返回：NULL        空指针
   *修改记录: 日期：2019.8.11            修改人:何亚康
   *描述    :                                                             
                                                                        */
PCLink CLink_GetNode(PCLink pHead,int index);

/************************************************************************/
/* 
*函数名称:PCLink CLink_AddNode(PCLink pHead,int iIndex,char ch);
*功能描述:向CLink链表中第iIndex-1节点后加入节点
*参数说明:
*        pHead       通用链表头结点的指针变量实际参数
*        iIndex      需要插入的节点的顺序号
*返回值  :
*        成功则返回：pHead       指向目标节点的指针变量
*        失败则返回：NULL        空指针
*修改记录: 日期：2019.8.11            修改人:何亚康
   *描述    :                                                                 
                                                                        */
PCLink CLink_AddNode(PCLink pHead,int iIndex,char ch);

/************************************************************************/
/* 
   *函数名称:int CLink_DelNode(PCLink pHead,int iIndex);
   *功能描述:释放通用链表中的某个节点
   *参数说明:
   *        pHead       通用链表头结点的指针变量实际参数
   *        iIndex      需要释放的节点的顺序号
   *返回值  :
   *        成功则返回：1       
   *        失败则返回：0        
   *修改记录: 日期：2019.8.11            修改人:何亚康
   *描述    :                                                             
                                                                        */
int CLink_DelNode(PCLink pHead,int iIndex);

/************************************************************************/
/* 
   *函数名称:void CLink_SetArr(PCLink pHead,char* cStr);
   *功能描述:将CLink链表里面的数据全部放到数组里
   *参数说明:
   *        pHead       通用链表头结点的指针变量实际参数
   *        cStr        数组首地址
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.11            修改人:何亚康
   *描述    :                                                             
                                                                        */
void CLink_SetArr(PCLink pHead,char* cStr);

/************************************************************************/
/* 
   *函数名称:void Arr_Pri(char* cStr,int isPlaintext);
   *功能描述:按明文或者暗文打印数组
   *参数说明:
   *         cStr            数组首地址
   *         isPlaintext     明文或者暗文的标志
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.11            修改人:何亚康
   *描述    :                                                             
                                                                        */
void Arr_Pri(char* cStr,int isPlaintext);

/************************************************************************/
/* 
   *函数名称:int Arr_SetCLink(char* cStr,PCLink pHead);
   *功能描述:将数组的数据放到链表里
   *参数说明:
   *         cStr            数组首地址
   *         pHead           链表头结点
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.11            修改人:何亚康
   *          日期：2019.8.14            修改人:何亚康
   *描述    :                                                             
                                                                        */
int Arr_SetCLink(char* cStr,PCLink pHead);

/************************************************************************/
/* 
   *函数名称:ULink_Free(PULink pHead);
   *功能描述:释放通用链表
   *参数说明:
   *        pHead       通用链表头结点的指针变量实际参数
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.11            修改人:何亚康
   *描述    :                                                             
                                                                        */
void CLink_Free(PCLink pHead);


/************************************************************************/
/* 
   *函数名称:int PutType(char ch,int iPutType);
   *功能描述:判断字符的类型是否正确
   *参数说明:
   *        ch         字符
   *        iPutType   需要的字符类型
   *返回值  :
   *        成功则返回：1       
   *        失败则返回：0  
   *修改记录: 日期：2019.8.11            修改人:何亚康
   *描述    :                                                             
                                                                        */
int PutType(char ch,int iPutType);


/************************************************************************/
/* 
   *函数名称:int PutType(char ch,int iPutType);
   *功能描述:判断字符的类型是否正确
   *参数说明:
   *        无
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.11            修改人:何亚康
   *描述    :                                                             
                                                                        */
void hide_cursor(void);

/************************************************************************/
/* 
   *函数名称:void show_cursor(void);
   *功能描述:隐藏光标
   *参数说明:
   *        无
   *返回值  :
   *        无 
   *修改记录: 日期：2019.8.11            修改人:何亚康
   *描述    :                                                             
                                                                        */
void show_cursor(void);


#endif