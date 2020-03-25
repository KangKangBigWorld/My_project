#include "Universal_Linklist.h"


PULink ULink_Init(void* pDate)
{
	PULink pNode;
	pNode=(PULink)calloc(1,sizeof(ULink));
	if (pNode==NULL)
	{
		return NULL;
	}
	pNode->pDate=pDate;
	pNode->pNext=NULL;
	return pNode;
}


void ULink_AddNode(PULink pHead,void* pDate)
{
	PULink pNode;
	pNode=(PULink)calloc(1,sizeof(ULink));
	if (pNode==NULL)
	{
		return;
	}
	while(pHead->pNext!=NULL)
	{
		pHead=pHead->pNext;
	}
	pHead->pNext=pNode;
	pNode->pDate=pDate;
	pNode->pNext=NULL;
}

void ULink_Print(PULink pHead,void (*pFun)(void *))
{
	if (pHead==NULL)
	{
		return;
	}
	pHead=pHead->pNext;
	while(pHead!=NULL)
	{
		pFun(pHead->pDate);
		pHead=pHead->pNext;
	}	
}

PULink ULink_Strmp(PULink pHead,void * ch,int (*pFun)(void *,void*))
{
	if (pHead==NULL)
	{
		return NULL;
	}
	pHead=pHead->pNext;
	while(pHead!=NULL)
	{
		if(pFun(pHead->pDate,ch))
		{
			return pHead;
		}
		pHead=pHead->pNext;
	}
	return NULL;
}

PULink ULink_Cmp(PULink pHead,void * ch,int (*pFun)(void *,void*))
{

	while(pHead!=NULL)
	{
		if(pFun(pHead->pDate,ch))
		{
			return pHead;
		}
		pHead=pHead->pNext;
	}
	return NULL;
}

int ULink_Count(PULink pHead)
{
	int iCount=0;
	if (pHead==NULL)
	{
		return 0;
	}
	while(pHead->pNext!=NULL)
	{
		pHead=pHead->pNext;
		iCount++;
	}
	return iCount;
}



PULink ULink_GetNode(PULink pHead,int iIndex)
{
	int iCount=-1;
	while(pHead!=NULL)
	{
		
		if (iCount==iIndex)
		{
			return pHead;
		}
		pHead=pHead->pNext;
		iCount++;
	}
	return NULL;
}



int ULink_Del(PULink pHead,int iIndex)
{
	PULink pTemp=NULL;
	pHead=ULink_GetNode(pHead,iIndex-1); //找到需要目标节点的前一个节点
	if (pHead==NULL||pHead->pNext==NULL) //前一个节点和目标节点不应该为空指针
	{
		return 0;
	}
	pTemp=pHead->pNext; //把目标节点的首地址保存，用于之后的释放。
	pHead->pNext=pHead->pNext->pNext; //让目标节点的前一个节点指向目标节点后一个节点
	free(pTemp->pDate);
	free(pTemp);
	return 1;
}

void ULink_Free(PULink pHead,int iFreeHead)
{
	PULink pTemp=pHead->pNext;
	if (iFreeHead==FREE_HEAD)//判断是否释放头结点
	{
		free(pHead);
	}
	while(pTemp!=NULL)//如果节点不为空则释放节点信息
	{   
		pHead=pTemp->pNext;//保存下一节点信息为头结点
		free(pTemp->pDate);
		free(pTemp);
		pTemp=pHead;
	}	
}


