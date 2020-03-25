#ifndef _RECORD_LINKLIST_H_
#define _RECORD_LINKLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "Universal_Linklist.h"
#include "My_View.h"
/**********************************�궨��**************************************/
#define DEPOSIT    1
#define WITHDRAW   2
#define TURNOUT    3
#define TURNIN     4

/***********************************�������Ͷ���********************************/
typedef struct  My_times
{
	int iSec; /* �� �C ȡֵ����Ϊ[0,59] */
	int iMin; /* �� - ȡֵ����Ϊ[0,59] */
	int iHour; /* ʱ - ȡֵ����Ϊ[0,23] */
	int iMDay; /* һ�����е����� - ȡֵ����Ϊ[1,31] */
	int iMon; /* �·ݣ���һ�¿�ʼ��0����һ�£� - ȡֵ����Ϊ[0,11] */
	int iYear; /* ��ݣ���ֵ����ʵ����ݼ�ȥ1900 */
	int iWDay; /* ���� �C ȡֵ����Ϊ[0,6]������0���������죬1��������һ���Դ����� */
	int iYDay; /* ��ÿ���1��1�տ�ʼ������ �C ȡֵ����Ϊ[0,365]������0����1��1�գ�1����1��2�գ��Դ����� */
	int iIsDst; /* ����ʱ��ʶ����ʵ������ʱ��ʱ��tm_isdstΪ������ʵ������ʱ�Ľ���tm_isdstΪ0�����˽����ʱ��tm_isdst()Ϊ����*/
}TIME;

typedef struct Record_Link
{
	int iSourseID;//ԴID����
	int iAimID;//Ŀ��ID����
	int iDateNum;//��ˮ��ǰ��� ����
	int iTimeNum;//��ˮ�ź��� ʱ��
	int iSec; /* �� �C ȡֵ����Ϊ[0,59] */
	int iMin; /* �� - ȡֵ����Ϊ[0,59] */
	int iHour; /* ʱ - ȡֵ����Ϊ[0,23] */
	int iDay; /* һ�����е����� - ȡֵ����Ϊ[1,31] */
	int iMonth; /* �·ݣ���һ�¿�ʼ��0����һ�£� - ȡֵ����Ϊ[0,11] */
	int iYear; /* ��ݣ���ֵ����ʵ����ݼ�ȥ1900 */
	int iDealMoney;//���׽��
	int iDealType;//��������
	int iBeforeMoney;//����ǰ���
	int iAfterMoney;//���׺����

}Record;

typedef Record* PRecord;

/***************************����ԭ��*********************************************/

/************************************************************************/
/* 
   *��������:PRECORD RLink_Init();
   *��������:��ʼ��¼�������ͣ����������׵�ַ
   *����˵��: 
   *        ��
   *����ֵ  :
   *        �ɹ��򷵻أ�PRECORD       ָ���û��������͵�ָ�����
   *		ʧ���򷵻أ�NULL        ��ָ��
   *�޸ļ�¼: ���ڣ�2019.8.19            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
PRecord RLink_Init();

/************************************************************************/
/* 
   *��������:void Set_RecordTime(PRECORD pDate);
   *��������:д�뵱ǰʱ�䵽��¼�Ľṹ����
   *����˵��: 
   *         pDate                  ָ���¼��ָ�����
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.19            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void Set_RecordTime(PRecord pDate);

/************************************************************************/
/* 
   *��������:void Set_RecordTime(PRECORD pDate);
   *��������:д�����ݵ���¼�Ľṹ����
   *����˵��: 
   *         pDate                  ָ���¼��ָ�����
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.19            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void Set_RecordInfor(PRecord pDate,int iSourseID,int iAimID,int iDealMoney,int iDealType,int iBeforeMoney,int iAfterMoney);



/************************************************************************/
/*                                                                      
   *��������:int My_DateStrToInt(char* cYear,char* cMonth,char* cDay);
   *��������:����ʱ���ַ��������ض�Ӧ��iDateNum
   *����˵��:
   *         cYear             ���ַ����׵�ַ
   *         cMonth            ���ַ����׵�ַ
   *         cDay              ���ַ����׵�ַ
   *����ֵ  :
   *         iDateNum                ʱ�����      
   *�޸ļ�¼: ���ڣ�2019.8.19            �޸���:���ǿ�
   *����    :
��
                                                                        */
int My_DateStrToInt(char* cYear,char* cMonth,char* cDay);

/************************************************************************/
/*                                                                      
   *��������:int My_DateStrToInt(char* cYear,char* cMonth,char* cDay);
   *��������:����ʱ���ַ��������ض�Ӧ��iDateNum
   *����˵��:
   *         cYear             ���ַ����׵�ַ
   *         cMonth            ���ַ����׵�ַ
   *         cDay              ���ַ����׵�ַ
   *����ֵ  :
   *         iDateNum                ʱ�����      
   *�޸ļ�¼: ���ڣ�2019.8.19            �޸���:���ǿ�
   *����    :
��
                                                                        */
int Date_Comparison(int ForthDate,int BackDate);


/************************************************************************/
/*                                                                      
   *��������:int My_DealMoney(char* cDealMoney);
   *��������:����ʱ���ַ��������ض�Ӧ��iDateNum
   *����˵��:
   *         cDealMoney              ���������ַ����׵�ַ
   *����ֵ  :
   *         iDateMoney              �����������      
   *�޸ļ�¼: ���ڣ�2019.8.19            �޸���:���ǿ�
   *����    :
��
                                                                        */
int My_DealMoney(int x,int y,char* cDealMoney);


/************************************************************************/
/*                                                                      
   *��������:int My_TransferMoney(int x,int y,char* cDealMoney);
   *��������:����ʱ���ַ��������ض�Ӧ��iDateNum(ת��)
   *����˵��:
   *         cDealMoney              ���������ַ����׵�ַ
   *����ֵ  :
   *         iDateMoney              �����������      
   *�޸ļ�¼: ���ڣ�2019.8.19            �޸���:���ǿ�
   *����    :
��
                                                                        */
int My_TransferMoney(int x,int y,char* cDealMoney);


/************************************************************************/
/*                                                                      
   *��������:int My_DateStrToInt(char* cYear,char* cMonth,char* cDay);
   *��������:����ʱ���ַ��������ض�Ӧ��iDateNum
   *����˵��:
   *         cYear             ���ַ����׵�ַ
   *         cMonth            ���ַ����׵�ַ
   *         cDay              ���ַ����׵�ַ
   *����ֵ  :
   *         iDateNum          ʱ�����      
   *�޸ļ�¼: ���ڣ�2019.8.19            �޸���:���ǿ�
   *����    :
��
                                                                        */
int Date_Effective(char* cYear,char* cMonth,char* cDay);

/************************************************************************/
/*                                                                      
   *��������:void My_Date(void);
   *��������:��ӡ��ǰ������
   *����˵��:
   *        ��
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.13            �޸���:���ǿ�
   *����    :
��
                                                                        */
void My_Date(void);


/************************************************************************/
/*                                                                      
   *��������:void My_WeekDay(void);
   *��������:��ӡ��ǰ���ڼ�
   *����˵��:
   *        ��
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.13            �޸���:���ǿ�
   *����    :
��
                                                                        */
void My_WeekDay(void);

/************************************************************************/
/*                                                                      
   *��������:PULink Select_RLinkID(PULink pHead,int iID);
   *��������:����iID��ֵ����һ����������pDate(Record)��ͨ������ͷ���
   *����˵��:
   *          pHead              ��������Record��ͨ������ͷ���
   *          iID                Ҫ�������û�ID
   *����ֵ  :
   *          pTemp              ���Ҫ������ͨ�������׵�ַ
   *�޸ļ�¼: ���ڣ�2019.8.19            �޸���:���ǿ�
   *����    :
��
                                                                        */
PULink Select_RLinkID(PULink pHead,int iID);

#endif