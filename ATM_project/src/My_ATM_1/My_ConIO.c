#include "My_ConIO.h"

int My_AccountIO(int x,int y,char *cStr)
{
   printf(" Ӣ������ ");
   return My_ConIO(cStr,7,LETTER,PLAINTEXT,x+12,y);
}


int My_ConIO(char *cStr,int iMaxLen,int iPutType,int isPlaintext,int x,int y)
{
	
	char ch='\0';
	int iCount=0;//�����ַ�λ��
	int iCursor=0;//���ƹ��λ��
	int iPrintCon=1;
	int iDirectin=0;
	PCLink pTemp=NULL;
    PCLink pHead=NULL;//���ͷ����PCLinkָ�����
	show_cursor();//��ʾ���
	pHead=CLink_Init();//��ʼ���ڵ�
	iCount=iCursor=Arr_SetCLink(cStr,pHead);    //�����������ݵ�������
	while(1)
	{   
		if((iCursor>0&&iCount<iMaxLen)||iPrintCon)
		{
			if (iCount==iMaxLen)
			{
				iPrintCon=0;
			}
        GoTo_XY(x,y);
		printf("              ");
 		GoTo_XY(x,y);
 		Arr_Pri(cStr,isPlaintext);    //��ӡ����
		}
 		
 		GoTo_XY(x+iCursor,y);
		ch=getch();
		if (ch==-32||ch==224||ch==0)
		{
			iDirectin=1;
			continue;
		}
		else if (ch==KEY_UP&&iDirectin==1)
		{
			iDirectin=0;
			return KEY_UP;
		}
		else if (ch==KEY_DOWN&&iDirectin==1)
		{
			iDirectin=0;
			return KEY_DOWN;
		}
		else if (ch==KEY_LEFT&&iDirectin==1)
		{
			iDirectin=0;
			if (iCursor>0)
			{
			printf("\b");
			iCursor--;
			}
			
		}
		else if (ch==KEY_RIGHT&&iDirectin==1)
		{
			iDirectin=0;
			if (iCursor<iCount)
			{
				iCursor++;
			}	
		}
		else if(ch==BACKSPACE&&iCursor>0)
		{    iCount--;
		    iCursor--;
			iPrintCon=1;
			CLink_DelNode(pHead,iCursor);
			
		}
		else if(ch==ESC)
		{
			hide_cursor();//���ع��
			return ESC;
		}
		else if(ch==ENTER)
		{
			hide_cursor();//���ع��
			return ENTER;
		}
		else if(iCount<iMaxLen&&PutType(ch,iPutType)&&iDirectin!=1)
		{
			
			CLink_AddNode(pHead,iCursor,ch);//�����µĽڵ�
			iCount++;
			iCursor++;
		}
		iDirectin=0;
		CLink_SetArr(pHead,cStr);	
	}
}

PCLink CLink_Init()
{
	PCLink head=NULL;
	head=calloc(1,sizeof(CLink));
	if (head==NULL)
	{
		return NULL;
	}
	head->pNext=NULL;
	return head;
}

PCLink CLink_GetNode(PCLink pHead,int iIndex)
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

PCLink CLink_AddNode(PCLink pHead,int iIndex,char ch)
{
  PCLink Node=NULL;
  int iCount=0;
  Node=calloc(1,sizeof(CLink));//�����µĽڵ�
  if (Node==NULL)
  {
	  return NULL;
  }
  Node->ch=ch;
  Node->pNext=NULL;
  pHead=CLink_GetNode(pHead,iIndex-1);//�ҵ�Ŀ��ڵ��ǰһ���ڵ�
  if (pHead!=NULL)//����ڵ㲻Ϊ�գ������Ŀ��ڵ�
  {
	  Node->pNext=pHead->pNext;
      pHead->pNext=Node;
      return Node;
  } 
  free(Node);//�ͷ�Ŀ��ڵ�
  return NULL;//���ؿ�ֵ��ʾ����ʧ��
}

int CLink_DelNode(PCLink pHead,int iIndex)
{
	PCLink pTemp=NULL;
	pHead=CLink_GetNode(pHead,iIndex-1); //�ҵ���ҪĿ��ڵ��ǰһ���ڵ�
	if (pHead==NULL||pHead->pNext==NULL) //ǰһ���ڵ��Ŀ��ڵ㲻Ӧ��Ϊ��ָ��
	{
		return 0;
	}
	pTemp=pHead->pNext; //��Ŀ��ڵ���׵�ַ���棬����֮����ͷš�
	pHead->pNext=pHead->pNext->pNext; //��Ŀ��ڵ��ǰһ���ڵ�ָ��Ŀ��ڵ��һ���ڵ�
	free(pTemp);
    return 1;
}

void CLink_SetArr(PCLink pHead,char* cStr)
{
	if (pHead!=NULL)
	{
		pHead=pHead->pNext;
	}
	while(pHead!=NULL)
	{
        *cStr=pHead->ch;
		cStr++;
		pHead=pHead->pNext;
	}
	*cStr='\0';
}

void Arr_Pri(char* cStr,int isPlaintext)
{
 if (isPlaintext)
 {
	 puts(cStr);
 }
 else
 {
   while(*cStr!='\0')
   {
   printf("*");
   cStr++;
   }
 }
}

int Arr_SetCLink(char* cStr,PCLink pHead)
{
int iCount=0;
while(*cStr!='\0')
{
	CLink_AddNode(pHead,iCount,*cStr);
	iCount++;
	cStr++;
}
return iCount;
}


void CLink_Free(PCLink pHead)
{
	PCLink pTemp=pHead->pNext;
	free(pHead);//�ͷ�ͷ���
	while(pHead!=NULL)//����ڵ㲻Ϊ�����ͷŽڵ���Ϣ
	{   
		pHead=pTemp->pNext;//������һ�ڵ���ϢΪͷ���
		free(pTemp);
		pTemp=pHead;
	}	
}


int PutType(char ch,int iPutType)
{
	switch (iPutType)
	{
	case NUMBER :
		{
			if(ch>='0'&&ch<='9')
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
		}	
	case LETTER:
		{
			if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
		}
	case NUMANDLET :
		{
			if((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z'))
			{
				return 1;
			}
			else
			{
				return 0;
			}			
		}
	default :
		{
			return 0;	
		}
	}
}

void hide_cursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void show_cursor()
{
	 HANDLE h_GAME =GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME,&cursor_info);
	cursor_info.bVisible=1;
	SetConsoleCursorInfo(h_GAME,&cursor_info);
}