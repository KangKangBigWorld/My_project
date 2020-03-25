#include "Record_LinkLIst.h"


PRecord RLink_Init()
{
	PRecord pDate;//数据域结构体首地址
	pDate=(PRecord)calloc(1,sizeof(Record));
	if (pDate==NULL)
	{
		return NULL;
	}
	return pDate;
}


void Set_RecordTime(PRecord pDate)
{
	time_t Time;
    TIME *pT ;	
	time(&Time);
	pT=(TIME*)localtime(&Time);
	pDate->iYear=pT->iYear+1900;
	pDate->iMonth=pT->iMon+1;
	pDate->iDay=pT->iMDay;
	pDate->iHour=pT->iHour;
	pDate->iMin=pT->iMin;
	pDate->iSec=pT->iSec;
	pDate->iDateNum=(((pDate->iYear)*10000)+((pDate->iMonth)*100)+((pDate->iDay)*1));
	pDate->iTimeNum=(((pDate->iHour)*10000)+((pDate->iMin)*100)+((pDate->iSec)*1));
}

void Set_RecordInfor(PRecord pDate,int iSourseID,int iAimID,int iDealMoney,int iDealType,int iBeforeMoney,int iAfterMoney)
{
		pDate->iSourseID=iSourseID;
		pDate->iAimID=iAimID;
		pDate->iDealMoney=iDealMoney;
		pDate->iDealType=iDealType;
		pDate->iBeforeMoney=iBeforeMoney;
		pDate->iAfterMoney=iAfterMoney;
}

int My_DealMoney(int x,int y,char* cDealMoney)
{
  int iDealMoney=0;
  iDealMoney=atoi(cDealMoney);
  if (iDealMoney==0)
  {
	  Draw_Warning(x,y+13,LGREEN);
      printf("操作金额不能为零,回车继续!^-^");
	  Clear_FormIO(x,y+9,cDealMoney);
	  color(BLUE,BLACK);
      return 0;
  }
  else if(iDealMoney>100)
  {
	  Draw_Warning(x,y+13,LGREEN);
      printf("操作金额不超过一万元,回车继续");
	  Clear_FormIO(x,y+9,cDealMoney);
	  color(BLUE,BLACK);
	  return 0;
  }
  else
  {
      iDealMoney=iDealMoney*100;
	  return iDealMoney;
  }
}

int My_TransferMoney(int x,int y,char* cDealMoney)
{
	int iDealMoney=0;
	iDealMoney=atoi(cDealMoney);
	if (iDealMoney==0)
	{
		Draw_Warning(x,y+13,LGREEN);
		printf("操作金额不能为零,回车继续!^-^");
		Clear_FormIO(x,y+9,cDealMoney);
		color(BLUE,BLACK);
		return 0;
	}
	else if(iDealMoney>100)
	{
		Draw_Warning(x,y+13,LGREEN);
		printf("操作金额不超过一万元,回车继续");
		Clear_FormIO(x,y+9,cDealMoney);
		color(BLUE,BLACK);
		return 0;
	}
	else
	{
		iDealMoney=iDealMoney*100;
		return iDealMoney;
	}
}

int Date_Comparison(int ForthDate,int BackDate)
{
	int iDiffer=0;
  if (ForthDate<BackDate)
  {
	  iDiffer=BackDate-ForthDate;
	  if (((0<=iDiffer)&&(iDiffer<=100))||((8870<=iDiffer)&&(iDiffer<=8900)))
	  {
		  return 1;//正确
	  }
	  else
	  {
		  return 100;//时间跨度太长了
	  }
  }
  else if (ForthDate>BackDate)
  {
    return-1;//起始时间大于终止时间错误
  }
  else if ((ForthDate==BackDate))
  {
	  return 1;//正确
  }
  return -1;//其它返回值
}



int My_DateStrToInt(char* cYear,char* cMonth,char* cDay)
{
	int iYear=atoi(cYear);//将时间字符串转为整型
	int iMonth=atoi(cMonth);//将时间字符串转为整型
	int iDay=atoi(cDay);//将时间字符串转为整型	
	int iDateNum=iYear*10000+iMonth*100+iDay;
	return iDateNum;
}

int Date_Effective(char* cYear,char* cMonth,char* cDay)
{
	int iYear=atoi(cYear);//将时间字符串转为整型
	int iMonth=atoi(cMonth);//将时间字符串转为整型
	int iDay=atoi(cDay);//将时间字符串转为整型	
   
	if (iMonth>12||iMonth==0)
	{
        return 0;
	}
	else if(iDay>31||iDay==0)
	{
        return 0;
	}
	else if((iMonth==2||iMonth==4||iMonth==6||iMonth==11)&&iDay==31)
	{
		return 0;
	}
	else if (iMonth==2&&iDay==30)
	{
		return 0;
	}
	else if (iMonth==2&&iDay==29)
	{
       if((iYear%4==0)&&(iYear%100!=0)||(iYear%400==0))//判断平润
		{//这一年是闰年
		   return My_DateStrToInt(cYear,cMonth,cDay);
		}
		else
		{//这一年不是闰年
			return 0;
		}
	}
	else
	{
		   return My_DateStrToInt(cYear,cMonth,cDay);
	}
		
           return My_DateStrToInt(cYear,cMonth,cDay);
}













void My_Date()
{
	time_t Time;
    TIME *pT ;	
	time(&Time);
	pT=(TIME*)localtime(&Time);
	printf("%d-%d-%d", pT->iYear+1900,pT->iMon+1,pT->iMDay);
}



void My_WeekDay()
{
	time_t Time;
    TIME *pT ;	
	time(&Time);
	pT=(TIME*)localtime(&Time);
	switch(pT->iWDay)
	{
	case 0:{
		printf("Sunday");
		   }break;
	case 1:{
		printf("Monday");
		   }break;
	case 2:{
		printf("Tuesday");
		   }break;
	case 3:{
		printf("Wednesday");
		   }break;
	case 4:{
		printf("Thursday");
		   }break;
	case 5:{
		printf("Friday");
		   }break;
	case 6:{
		printf("Saturday");
		   }break;
	}
}


PULink Select_RLinkID(PULink pHead,int iID)
{
	PULink pTemp=NULL;
	PRecord pDate=NULL;
	if(!(pTemp=ULink_Init(NULL)))
	{
		return NULL;
	}
	pHead=pHead->pNext;
	pDate=RLink_Init();
	while(pHead!=NULL)
	{
		if (((PRecord)pHead->pDate)->iSourseID==iID)
		{
			memcpy(pDate,pHead->pDate,sizeof(Record));
			ULink_AddNode(pTemp,pDate);
			pDate=RLink_Init();
		}
		pHead=pHead->pNext;
	}
	free(pDate);
	return pTemp;
}