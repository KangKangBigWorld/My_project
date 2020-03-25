#include "My_ConIO.h"

int My_AccountIO(int x,int y,char *cStr)
{
   printf(" 英文姓名 ");
   return My_ConIO(cStr,7,LETTER,PLAINTEXT,x+12,y);
}


int My_ConIO(char *cStr,int iMaxLen,int iPutType,int isPlaintext,int x,int y)
{
	
	char ch='\0';
	int iCount=0;//控制字符位数
	int iCursor=0;//控制光标位置
	int iPrintCon=1;
	int iDirectin=0;
	PCLink pTemp=NULL;
    PCLink pHead=NULL;//存放头结点的PCLink指针变量
	show_cursor();//显示光标
	pHead=CLink_Init();//初始化节点
	iCount=iCursor=Arr_SetCLink(cStr,pHead);    //将数组里数据导入链表
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
 		Arr_Pri(cStr,isPlaintext);    //打印数据
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
			hide_cursor();//隐藏光标
			return ESC;
		}
		else if(ch==ENTER)
		{
			hide_cursor();//隐藏光标
			return ENTER;
		}
		else if(iCount<iMaxLen&&PutType(ch,iPutType)&&iDirectin!=1)
		{
			
			CLink_AddNode(pHead,iCursor,ch);//加入新的节点
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
  Node=calloc(1,sizeof(CLink));//建立新的节点
  if (Node==NULL)
  {
	  return NULL;
  }
  Node->ch=ch;
  Node->pNext=NULL;
  pHead=CLink_GetNode(pHead,iIndex-1);//找到目标节点的前一个节点
  if (pHead!=NULL)//如果节点不为空，则插入目标节点
  {
	  Node->pNext=pHead->pNext;
      pHead->pNext=Node;
      return Node;
  } 
  free(Node);//释放目标节点
  return NULL;//返回空值表示插入失败
}

int CLink_DelNode(PCLink pHead,int iIndex)
{
	PCLink pTemp=NULL;
	pHead=CLink_GetNode(pHead,iIndex-1); //找到需要目标节点的前一个节点
	if (pHead==NULL||pHead->pNext==NULL) //前一个节点和目标节点不应该为空指针
	{
		return 0;
	}
	pTemp=pHead->pNext; //把目标节点的首地址保存，用于之后的释放。
	pHead->pNext=pHead->pNext->pNext; //让目标节点的前一个节点指向目标节点后一个节点
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
	free(pHead);//释放头结点
	while(pHead!=NULL)//如果节点不为空则释放节点信息
	{   
		pHead=pTemp->pNext;//保存下一节点信息为头结点
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