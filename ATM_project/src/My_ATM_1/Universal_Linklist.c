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
	pHead=ULink_GetNode(pHead,iIndex-1); //�ҵ���ҪĿ��ڵ��ǰһ���ڵ�
	if (pHead==NULL||pHead->pNext==NULL) //ǰһ���ڵ��Ŀ��ڵ㲻Ӧ��Ϊ��ָ��
	{
		return 0;
	}
	pTemp=pHead->pNext; //��Ŀ��ڵ���׵�ַ���棬����֮����ͷš�
	pHead->pNext=pHead->pNext->pNext; //��Ŀ��ڵ��ǰһ���ڵ�ָ��Ŀ��ڵ��һ���ڵ�
	free(pTemp->pDate);
	free(pTemp);
	return 1;
}

void ULink_Free(PULink pHead,int iFreeHead)
{
	PULink pTemp=pHead->pNext;
	if (iFreeHead==FREE_HEAD)//�ж��Ƿ��ͷ�ͷ���
	{
		free(pHead);
	}
	while(pTemp!=NULL)//����ڵ㲻Ϊ�����ͷŽڵ���Ϣ
	{   
		pHead=pTemp->pNext;//������һ�ڵ���ϢΪͷ���
		free(pTemp->pDate);
		free(pTemp);
		pTemp=pHead;
	}	
}


