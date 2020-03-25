#include "User_LinkList.h"


PUser User_Init()
{
  PUser pDate;//数据域结构体首地址
  pDate=(PUser)calloc(1,sizeof(User));
  if (pDate==NULL)
  {
	  return NULL;
  }
  pDate->iCondition=ACTIVE;
  return pDate;
}

/************************************************************************/
/*                 修改账户属性                                                     */

void User_SetAll(PUser pDate,int iID,int iIdentity,int iCondition,char* pAccount,char* pPassword,int iBalance)
{
  pDate->iID=iID;
  pDate->iIdentity=iIdentity;
  pDate->iCondition=iCondition;
  memcpy(pDate->cAccount,pAccount,12);
  memcpy(pDate->cPasswod,pPassword,8);
  pDate->iBalance=iBalance;
  SetRegister_Date(pDate);
}

void User_SetID(int iID,PUser pDate)
{
 pDate->iID=iID;
}


void User_SetIdentity(int iIdentity,PUser pDate)
{
	pDate->iIdentity=iIdentity;
}



void User_SetCondition(int iCondition,PUser pDate)
{
	pDate->iCondition=iCondition;
}



void User_SetAccount(char* pAccount,PUser pDate)
{
	memcpy(pDate->cAccount,pAccount,12);
}



void User_SetPassword(char* pPassword,PUser pDate)
{
	memcpy(pDate->cPasswod,pPassword,8);
}



void User_SetBalance(int iBalance,PUser pDate)
{
	pDate->iBalance=iBalance;
}

/************************************************************************/
/*                 获取账户属性                                                     */

int User_GetID(PUser pDate)
{
	return pDate->iID;
}



int User_GetIdentity(PUser pDate)
{
	return pDate->iIdentity;
}



int User_GetCondition(PUser pDate)
{
	return pDate->iCondition;
}



char* User_GetAccount(PUser pDate)
{
	return pDate->cAccount;
}



char* User_GetPassword(PUser pDate)
{
	return pDate->cPasswod;
}



int User_GetBalance(PUser pDate)
{
	return pDate->iBalance;
}

/************************************************************************/
/*                 打印账户信息                                                     */

void User_PrtID(void* pDate)
{
	printf("%d",((PUser)pDate)->iID);
}

void User_PrtIdentity(void* pDate)
{
	if(((PUser)pDate)->iIdentity==USER)
	{	
		printf("USER");
	}
	else if (((PUser)pDate)->iIdentity==ADMIN)
	{
		printf("ADMIN");
	}	
	else if (((PUser)pDate)->iIdentity==SUPERADMIN)
	{
		printf("SUPERADMIN");
	}
	else
	{
		printf("NOT FOUND");
	}

}

void User_PrtCondition(void* pDate)
{                                                                    
	if(((PUser)pDate)->iCondition==FROZEN)
		
	{
		printf("FROZEN");
	}
	else if(((PUser)pDate)->iCondition==ACTIVE) ;
	{
		printf("ACTIVE");
	}
	
}

void User_PrtAccount(void* pDate)
{
	printf("%s",((PUser)pDate)->cAccount);
}

void User_PrtPassword(void* pDate)
{
	printf("%s",((PUser)pDate)->cPasswod);
}

void User_PrtBalance(void* pDate)
{
	printf("%d",((PUser)pDate)->iBalance);
}

int User_Accountcmp(void* pDate,void* ch)
{
	if(!(strcmp(((PUser)pDate)->cAccount,(char*)ch)))
	{
		return 1;
	}
	else
	{
return 0;
	}
	
}

int User_Passwordcmp(void* pDate,void* ch)
{
	if(!(strcmp(((PUser)pDate)->cPasswod,(char*)ch)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

int User_IDcmp(void* pDate,void* ch)
{
	int iNumber=atoi(ch);
	if(((PUser)pDate)->iID==iNumber)
	{
		return 1;
	}
	return 0;
}

void SetRegister_Date(PUser pDate)
{
	time_t Time;
    TIME *pT;	
	time(&Time);
	pT=(TIME*)localtime(&Time);
	pDate->iYear=pT->iYear+1900;
	pDate->iMonth=pT->iMon+1;
	pDate->iDay=pT->iMDay;
}
