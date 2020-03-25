#ifndef _UNIVERSAL_LINKLIST_H_
#define _UNIVERSAL_LINKLIST_H_
#include <stdlib.h>

/**********************************宏定义**************************************/
#define FREE_HEAD 1 //释放头结点的信号标志

/***********************************数据类型定义********************************/
typedef struct Universal_Link//定义通用链表
{
	void *pDate;//指向数据域的指针变量
	struct Universal_Link* pNext;//指向通用链表下一节点的指针变量
}ULink;

typedef ULink* PULink;//指向通用链表的指针变量

/***************************函数原型*********************************************/

/************************************************************************/
/* 
   *函数名称: PULink ULink_Init(void* pDate);
   *功能描述:初始化通用链表
   *参数说明: 
   *        pDate       数据域的指针变量实际参数
   *返回值  :
   *        成功则返回：PULink      指向通用链表头结点的指针变量
   *		失败则返回：NULL        空指针
   *修改记录: 日期：2019.8.9            修改人:何亚康
   *描述    :                                                             
                                                                        */
PULink ULink_Init(void* pDate);

/************************************************************************/
/* 
   *函数名称: void ULink_AddNode(PULink pHead,void* pDate);
   *功能描述:向通用链表尾部添加节点
   *参数说明:
   *        pHead       通用链表头结点的指针变量实际参数
   *        pDate       数据域的指针变量实际参数
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.9            修改人:何亚康
   *描述    :                                                             
                                                                        */
void ULink_AddNode(PULink pHead,void* pDate);

/************************************************************************/
/* 
*函数名称:void ULink_Print(PULink pHead,void (*pFun)(void *));
*功能描述:打印链表数据域里数据信息
*参数说明:
*        pHead                 通用链表头结点的指针变量实际参数
*        (*pFun)(void *)       函数指针Fun参数是数据域的首地址
*返回值  :
*        无
*修改记录: 日期：2019.8.10            修改人:何亚康
   *描述    :                                                                 
                                                                        */
void ULink_Print(PULink pHead,void (*pFun)(void *));


/************************************************************************/
/* 
*函数名称:PULink ULink_Cmp(PULink pHead,void *,void (*pFun)(void *,void*));
*功能描述:打印链表数据域里数据信息
*参数说明:
*        pHead                       通用链表头结点的指针变量实际参数
*        void *                      空指针
*        (*pFun)(void *,void*)       函数指针Fun参数是数据域的首地址
*返回值  :
*         成功则返回：pHead          头节点指针 
*		  失败则返回：NULL           空指针 
*修改记录: 日期：2019.8.14            修改人:何亚康
   *描述    :                                                                 
                                                                        */
PULink ULink_Strmp(PULink pHead,void *,int (*pFun)(void *,void*));

/************************************************************************/
/* 
*函数名称:PULink ULink_Cmp(PULink pHead,void *,void (*pFun)(void *,void*));
*功能描述:打印链表数据域里数据信息
*参数说明:
*        pHead                       通用链表头结点的指针变量实际参数
*        void *                      空指针
*        (*pFun)(void *,void*)       函数指针Fun参数是数据域的首地址
*返回值  :
*         成功则返回：pHead          头节点指针 
*		  失败则返回：NULL           空指针 
*修改记录: 日期：2019.8.14            修改人:何亚康
   *描述    :                                                                 
                                                                        */
PULink ULink_Cmp(PULink pHead,void * ch,int (*pFun)(void *,void*));

/************************************************************************/
/* 
   *函数名称: int ULink_Count(PULink pHead);
   *功能描述:获取通用链表的长度
   *参数说明:
   *        pHead       通用链表头结点的指针变量实际参数
   *返回值  :
   *        成功则返回：iCount      通用链表的长度
   *		失败则返回：0        
   *修改记录: 日期：2019.8.9            修改人:何亚康
   *描述    :                                                             
                                                                        */
int ULink_Count(PULink pHead);

/************************************************************************/
/* 
   *函数名称: PULink ULink_GetNode(PULink pHead,int iIndex);
   *功能描述:获取通用链表中的某个节点
   *参数说明:
   *        pHead       通用链表头结点的指针变量实际参数
   *        iIndex      需要获取的节点的顺序号
   *返回值  :
   *        成功则返回：pHead       指向目标节点的指针变量
   *        失败则返回：NULL        空指针
   *修改记录: 日期：2019.8.9            修改人:何亚康
   *描述    :                                                             
                                                                        */
PULink ULink_GetNode(PULink pHead,int iIndex);

/************************************************************************/
/* 
   *函数名称:ULink_Del(PULink pHead,int iIndex);
   *功能描述:释放通用链表中的某个节点
   *参数说明:
   *        pHead       通用链表头结点的指针变量实际参数
   *        iIndex      需要释放的节点的顺序号
   *返回值  :
   *        成功则返回：1       
   *        失败则返回：0        
   *修改记录: 日期：2019.8.9            修改人:何亚康
   *描述    :                                                             
                                                                        */
int ULink_Del(PULink pHead,int iIndex);

/************************************************************************/
/* 
   *函数名称:ULink_Free(PULink pHead,int iFreeHead);
   *功能描述:释放通用链表
   *参数说明:
   *        pHead       通用链表头结点的指针变量实际参数
   *        iFreeHead   是否释放头结点的信号参数 FREE_HEAD表示释放
   *返回值  :
   *        无
   *修改记录: 日期：2019.8.9            修改人:何亚康
   *描述    :                                                             
                                                                        */
void ULink_Free(PULink pHead,int iFreeHead);



#endif

