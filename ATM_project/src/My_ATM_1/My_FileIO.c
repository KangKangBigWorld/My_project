#include "My_FileIO.h"


FILE* File_Open(const char* pFilename)
{
	FILE* fp=fopen(pFilename,"r+");
	if(fp==NULL)
	{
		fp=fopen(pFilename,"w+");
	}
	return fp;
}

FILE* File_Write(PULink pHead,char* pFilename,int iSize)
{
	int count=0;
	FILE* fp;
    fp=fopen(pFilename,"w+");
	pHead=pHead->pNext;
	while (pHead!=NULL)
	{
		fwrite(pHead->pDate,iSize,1,fp);
		pHead=pHead->pNext;
		count++;
	}
	fflush(fp);
	return fp;
}

PULink File_Read(FILE*pFilename,int iSize)
{
    PULink head=NULL;
	void *pdata=NULL;
	head=ULink_Init(NULL);
    pdata=calloc(1,iSize);
    while(fread(pdata,iSize,1,pFilename)>0)
	{
		ULink_AddNode(head,pdata);
        pdata=calloc(1,iSize);
	}
    free(pdata);
	return head;
}