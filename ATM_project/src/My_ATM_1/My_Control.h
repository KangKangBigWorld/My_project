#ifndef _MY_CONTROL_H_
#define _MY_CONTROL_H_
#include "My_View.h"
#include "My_ConIO.h"
#include "Get_KeyValue.h"
#include "User_LinkList.h"
#include "My_FileIO.h"
/**********************************�궨��**************************************/



/***********************************�������Ͷ���********************************/



/***************************����ԭ��*********************************************/

/************************************************************************/
/* 
   *��������:void MainWIN_Control(void);
   *��������:��������ת����
   *����˵��: 
   *         ��
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.13            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void MainWIN_Control(void);


/************************************************************************/
/* 
   *��������:void Login_Control(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PULink pRHead,FILE** pRFp,char* Name_Date_Record);
   *��������:��¼����
   *����˵��: 
   *         x,y              ����������������Ͻǵ�x,y����
   *         pHead            �û�����ͷ���ָ�����
   *         pFp              ����û��ļ�ָ���ָ�����
   *         Name_Date_User   ������ļ����ַ�����ָ��
   *         pRHead           ��¼����ͷ���ָ�����
   *         pRFp             ��ż�¼�ļ�ָ���ָ�����
   *         Name_Date_Record ��ż�¼�ļ����ַ�����ָ��
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.13            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void Login_Control(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PULink pRHead,FILE** pRFp,char* Name_Date_Record);

/************************************************************************/
/* 
   *��������: void SignOut_control(void);
   *��������:�˳�����
   *����˵��: 
   *         ��
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.13            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void SignOut_Control(void);

/************************************************************************/
/* 
   *��������:int FormIO_Control(int x,int y,char* pTips,char* cStr,int iMaxLen,int iPutType,int isPlaintext);
   *��������:���������������Ͽ��������Draw_FormIO();ʹ��
   *����˵��: 
   *         x,y              ����������������Ͻǵ�x,y����
   *         pTips            ���������������ʾ���ַ����׵�ַ
   *         cStr             ���Ƶ��ַ����׵�ַ
   *         iMaxLen          �����������󳤶�
   *         iPutType         ����������ַ�����
   *         isPlaintext      ���Ļ��߰�����ʾ
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.13            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
int FormIO_Control(int x,int y,char* pTips,char* cStr,int iMaxLen,int iPutType,int isPlaintext);

/************************************************************************/
/* 
   *��������:void Register_Control(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User);
   *��������:ע�Ṧ��
   *����˵��: 
   *         x              ע������Ͻǵ�x����
   *         y              ע������Ͻǵ�y����
   *         pHead          ͨ������ͷָ��
   *         pFp            ����ļ�ͷָ���ָ�����
   *         Name_Date_User ����ļ������ַ�ָ��
   *         iIDentity      ���
   *����ֵ  :
   *         pFp             ����ļ�ͷָ���ָ�����
   *�޸ļ�¼: ���ڣ�2019.8.13            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void Register_Control(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,int iIDentity);

/************************************************************************/
/* 
   *��������:void User_Control(PULink pHead,PUser pDate,FILE** pFp,char* Name_Date_User,PULink pRHead,FILE** pRFp,char* Name_Date_Record);
   *��������:�û�����ģ��
   *����˵��: 
   *         pHead            �û�����ͷ���ָ�����
   *         pDate            ��ǰ��¼�û���������
   *         pFp              ����û��ļ�ָ���ָ�����
   *         Name_Date_User   ������ļ����ַ�����ָ��
   *         pRHead           ��¼����ͷ���ָ�����
   *         pRFp             ��ż�¼�ļ�ָ���ָ�����
   *         Name_Date_Record ��ż�¼�ļ����ַ�����ָ��
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.13            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void User_Control(PULink pHead,PUser pDate,FILE** pFp,char* Name_Date_User,PULink pRHead,FILE** pRFp,char* Name_Date_Record);

/************************************************************************/
/* 
   *��������:void User_Control(PULink pHead,PUser pDate,FILE** pFp,char* Name_Date_User,PULink pRHead,FILE** pRFp,char* Name_Date_Record);
   *��������:����Ա����ģ��
   *����˵��: 
   *         pHead            �û�����ͷ���ָ�����
   *         pDate            ��ǰ��¼�û���������
   *         pFp              ����û��ļ�ָ���ָ�����
   *         Name_Date_User   ������ļ����ַ�����ָ��
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.13            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void Admin_Control(PULink pHead,PUser pDate,FILE** pFp,char* Name_Date_User);


/************************************************************************/
/* 
   *��������:void Admin_Search_Control(PULink pHead);
   *��������:��ѯ����
   *����˵��: 
   *         pHead          ͨ������ͷָ��
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.17            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void Admin_Search_Control(PULink pHead);

/************************************************************************/
/* 
   *��������:void Page_Print(int x,int y,PULink pHead,int iPage,int iFlag);
   *��������:��ҳ����ӡ�û���Ϣ
   *����˵��: 
   *         x              ע������Ͻǵ�x����
   *         y              ע������Ͻǵ�y����
   *         pHead          ͨ������ͷָ��
   *         iPage          ��ӡ���ǵڼ�ҳ��
   *         int iFlag      ��ǵ�����
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.17            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void Page_Print(int x,int y,PULink pHead,int iPage,int iFlag);


/************************************************************************/
/* 
   *��������:void Page_Turning(int x,int y,PULink pHead,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int));
   *��������:��ҳ����
   *����˵��: 
   *         x              ע������Ͻǵ�x����
   *         y              ע������Ͻǵ�y����
   *         pHead          ͨ������ͷָ��
   *         My_Print       ��ӡ���ݵķ����ĺ���ָ��
   *         Page           ��ӡ���ķ����ĺ���ָ��
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.17            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void Page_Turning(int x,int y,PULink pHead,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int));

/************************************************************************/
/* 
   *��������:PULink Select_Identity(PULink pHead,int iIdentity);
   *��������:ѡ�������ڵ���ݣ�����������ͷ���ָ��
   *����˵��: 
   *         pHead          ͨ������ͷָ��
   *         iIdentity      ��Ҫѡ�����ݣ��û�:0 ����Ա:1��
   *����ֵ  :
   *         ����������ͷ�ڵ�ָ��
   *�޸ļ�¼: ���ڣ�2019.8.17            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
PULink Select_Identity(PULink pHead,int iIdentity);


/************************************************************************/
/* 
   *��������:PULink Select_UserName(PULink pHead,char* SearchName);
   *��������:ģ����ѯ�û���������������ͷ���ָ��
   *����˵��: 
   *         pHead          ͨ������ͷָ��
   *         SearchName     ��Ҫ��ѯ���ַ���
   *����ֵ  :
   *         ����������ͷ�ڵ�ָ��
   *�޸ļ�¼: ���ڣ�2019.8.17            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
PULink Select_UserName(PULink pHead,char* SearchName);

/************************************************************************/
/* 
   *��������:void Fuzzy_Search(PULink pHead);
   *��������:ģ����ѯ
   *����˵��: 
   *         pHead          ͨ������ͷָ��
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.17            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void Fuzzy_Search(PULink pHead);

/************************************************************************/
/* 
   *��������:void Admin_Register(PULink pHead,FILE** pFp,char* Name_Date_User);
   *��������:����Աע�Ṧ��
   *����˵��: 
   *         pHead          ͨ������ͷָ��
   *         pFp            ����ļ�ָ���ָ�����
   *         Name_Date_User ����ļ������ַ���ָ��
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.17            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void Admin_Register(PULink pHead,FILE** pFp,char* Name_Date_User);

/************************************************************************/
/* 
   *��������:void User_Delect(PULink pHead,PUser pDate,FILE** pFp,char* pFilename);
   *��������:�û�ɾ��
   *����˵��: 
   *         pHead          ͨ������ͷָ��
   *         pFp            ����ļ�ָ���ָ�����
   *         Name_Date_User ����ļ������ַ���ָ��
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.21            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void User_Delect(PULink pHead,PUser pDate,FILE** pFp,char* pFilename);


/************************************************************************/
/* 
   *��������:void User_DelectControl(int x,int y,FILE** pFp,char* pFilename,PULink pHead,PUser pDate,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int));
   *��������:ɾ�����ƺ���
   *����˵��: 
   *         x,y            ����λ������
   *         pHead          �û�ͨ�������׵�ַ
   *         pFp            ����û��ļ�ָ���ָ�뺯��
   *         Name_Date_User �û��ļ����ַ����׵�ַ
   *         pDate          �û�����
   *         pRHead          ��¼ͨ�������׵�ַ
   *         pRFp            ��ż�¼�ļ�ָ���ָ�뺯��
   *         Name_Date_Record ��¼�ļ����ַ����׵�ַ
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.21            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void User_DelectControl(int x,int y,FILE** pFp,char* pFilename,PULink pHead,PUser pDate,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int));

/************************************************************************/
/* 
   *��������:int Control_Cancell(int x,int y);
   *��������:�û�ɾ��
   *����˵��: 
   *         pHead          ͨ������ͷָ��
   *         pFp            ����ļ�ָ���ָ�����
   *         Name_Date_User ����ļ������ַ���ָ��
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.21            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
int Control_Cancell(int x,int y);

/************************************************************************/
/* 
   *��������:void User_ChangePassword(PULink pHead,PUser pDate,FILE** pFp,char* pFilename);
   *��������:�޸��û�����
   *����˵��: 
   *         pHead          ͨ������ͷָ��
   *         pDate          �û�����
   *         pFp            �ļ���
   *         Name_Date_User ����ļ������ַ���ָ��
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.21            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void User_ChangePassword(PULink pHead,PUser pDate,FILE** pFp,char* pFilename);

/************************************************************************/
/* 
   *��������:void User_ChangePasswordControl(int x,int y,FILE** pFp,char* pFilename,PULink pHead,PUser pDate,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int));
   *��������:������������
   *����˵��: 
   *         x,y            ����λ������
   *         pHead          �û�ͨ�������׵�ַ
   *         pFp            ����û��ļ�ָ���ָ�뺯��
   *         Name_Date_User �û��ļ����ַ����׵�ַ
   *         pDate          �û�����
   *         pRHead          ��¼ͨ�������׵�ַ
   *         pRFp            ��ż�¼�ļ�ָ���ָ�뺯��
   *         Name_Date_Record ��¼�ļ����ַ����׵�ַ
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.21            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void User_ChangePasswordControl(int x,int y,FILE** pFp,char* pFilename,PULink pHead,PUser pDate,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int));


/************************************************************************/
/* 
   *��������:int My_ChangePassword(int x,int y,PUser pDate);
   *��������:�û��޸����빦��
   *����˵��: 
   *         x,y            ����λ������
   *         pDate          �û�����
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.21            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
int My_ChangePassword(int x,int y,PUser pDate);


/************************************************************************/
/* 
   *��������:int My_BalanceQueryControl(int x,int y,PUser pDate);
   *��������:�û���ѯ���
   *����˵��: 
   *         x,y            ����λ������
   *         pDate          �û�����
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.21            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
int My_BalanceQueryControl(int x,int y,PUser pDate);


/************************************************************************/
/* 
   *��������:int My_DepositControl(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PUser pDate,PULink pRHead,FILE** pRFp,char* Name_Date_Record);
   *��������:����
   *����˵��: 
   *         x,y            ����λ������
   *         pHead          �û�ͨ�������׵�ַ
   *         pFp            ����û��ļ�ָ���ָ�뺯��
   *         Name_Date_User �û��ļ����ַ����׵�ַ
   *         pDate          �û�����
   *         pRHead          ��¼ͨ�������׵�ַ
   *         pRFp            ��ż�¼�ļ�ָ���ָ�뺯��
   *         Name_Date_Record ��¼�ļ����ַ����׵�ַ
   *����ֵ  :
   *         �ɹ�����:1
   *         ʧ�ܷ���:0
   *�޸ļ�¼: ���ڣ�2019.8.21            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
int My_DepositControl(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PUser pDate,PULink pRHead,FILE** pRFp,char* Name_Date_Record);



/************************************************************************/
/* 
   *��������:int My_WithdrawControl(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PUser pDate,PULink pRHead,FILE** pRFp,char* Name_Date_Record);
   *��������:ȡ���
   *����˵��: 
   *         x,y            ����λ������
   *         pHead          �û�ͨ�������׵�ַ
   *         pFp            ����û��ļ�ָ���ָ�뺯��
   *         Name_Date_User �û��ļ����ַ����׵�ַ
   *         pDate          �û�����
   *         pRHead          ��¼ͨ�������׵�ַ
   *         pRFp            ��ż�¼�ļ�ָ���ָ�뺯��
   *         Name_Date_Record ��¼�ļ����ַ����׵�ַ
   *����ֵ  :
   *         �ɹ�����:1
   *         ʧ�ܷ���:0
   *�޸ļ�¼: ���ڣ�2019.8.21            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
int My_WithdrawControl(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PUser pDate,PULink pRHead,FILE** pRFp,char* Name_Date_Record);


/************************************************************************/
/* 
   *��������:int My_TransferControl(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PUser pDate,PULink pRHead,FILE** pRFp,char* Name_Date_Record);
   *��������:ת�˹���
   *����˵��: 
   *         x,y            ����λ������
   *         pHead          �û�ͨ�������׵�ַ
   *         pFp            ����û��ļ�ָ���ָ�뺯��
   *         Name_Date_User �û��ļ����ַ����׵�ַ
   *         pDate          �û�����
   *         pRHead          ��¼ͨ�������׵�ַ
   *         pRFp            ��ż�¼�ļ�ָ���ָ�뺯��
   *         Name_Date_Record ��¼�ļ����ַ����׵�ַ
   *����ֵ  :
   *         �ɹ�����:1
   *         ʧ�ܷ���:0
   *�޸ļ�¼: ���ڣ�2019.8.21            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
int My_TransferControl(int x,int y,PULink pHead,FILE** pFp,char* Name_Date_User,PUser pDate,PULink pRHead,FILE** pRFp,char* Name_Date_Record);


/************************************************************************/
/* 
   *��������:int My_ChangePasswordControl(int x,int y,PULink pHead,PUser pDate,FILE** pFp,char* Name_Date_User);
   *��������:�û��޸�������ƺ���
   *����˵��: 
   *         x,y            ����λ������
   *         pHead          �û�ͨ�������׵�ַ
   *         pFp            ����û��ļ�ָ���ָ�뺯��
   *         Name_Date_User �û��ļ����ַ����׵�ַ
   *         pDate          �û�����
   *����ֵ  :
   *         �ɹ�����:1
   *         ʧ�ܷ���:0
   *�޸ļ�¼: ���ڣ�2019.8.21            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
int My_ChangePasswordControl(int x,int y,PULink pHead,PUser pDate,FILE** pFp,char* Name_Date_User);

/************************************************************************/
/* 
   *��������:void User_RecordControl(PULink pHead,PUser pDate);
   *��������:�û���¼��ѯ����ģ��
   *����˵��: 
   *         pHead          �û�ͨ�������׵�ַ
   *         pDate          �û�����
   *����ֵ  :
   *         �ɹ�����:1
   *         ʧ�ܷ���:0
   *�޸ļ�¼: ���ڣ�2019.8.21            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void User_RecordControl(PULink pHead,PUser pDate);

/************************************************************************/
/* 
   *��������:void User_Record(int x,int y,PULink pHead,PUser pDate,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int));
   *��������:ת�˹���
   *����˵��: 
   *         x,y            ����λ������
   *         pHead          �û�ͨ�������׵�ַ
   *         pFp            ����û��ļ�ָ���ָ�뺯��
   *         Name_Date_User �û��ļ����ַ����׵�ַ
   *         pDate          �û�����
   *         pRHead          ��¼ͨ�������׵�ַ
   *         pRFp            ��ż�¼�ļ�ָ���ָ�뺯��
   *         Name_Date_Record ��¼�ļ����ַ����׵�ַ
   *����ֵ  :
   *         �ɹ�����:1
   *         ʧ�ܷ���:0
   *�޸ļ�¼: ���ڣ�2019.8.20            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void User_Record(int x,int y,PULink pHead,PUser pDate,void (*My_Print)(int,int,PULink,int,int),void (*Page)(int,int));


/************************************************************************/
/* 
   *��������:void Page_RecordPrint(int x,int y,PULink pHead,int iPage,int iFlag);
   *��������:��ӡ��¼��Ϣ
   *����˵��: 
   *         x,y            ����λ������
   *         pHead          �û�ͨ�������׵�ַ
   *         pFp            ����û��ļ�ָ���ָ�뺯��
   *         Name_Date_User �û��ļ����ַ����׵�ַ
   *         pDate          �û�����
   *����ֵ  :
   *         ��
   *�޸ļ�¼: ���ڣ�2019.8.21            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
void Page_RecordPrint(int x,int y,PULink pHead,int iPage,int iFlag);


/************************************************************************/
/* 
   *��������:PULink Select_RecordID(PULink pHead,int iAimID);
   *��������:��IDѡ�񣬷���ͨ������
   *����˵��: 
   *         pHead          �û�ͨ�������׵�ַ

   *����ֵ  :
   *         �ɹ��򷵻�ͨ������ͷ���
   *         ʧ���򷵻ؿ�
   *�޸ļ�¼: ���ڣ�2019.8.21            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
PULink Select_RecordID(PULink pHead,int iAimID);


/************************************************************************/
/* 
   *��������:int My_DateIO(int x,int y,char * cTitle,int iFlag,int ForthDate);
   *��������:�������ڵ��������
   *����˵��: 
   *         cTitle             ����
   *         iFlag              ��־λ
   *         ForthDate          ǰ������
   *����ֵ  :
   *         �ɹ��򷵻�1
   *         ʧ���򷵻�0
   *�޸ļ�¼: ���ڣ�2019.8.21            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
int My_DateIO(int x,int y,char * cTitle,int iFlag,int ForthDate);

/************************************************************************/
/* 
   *��������:PULink My_DateControl(int x,int y,PULink pHead,PUser pDate);
   *��������:���ڿ��ƺ���
   *����˵��: 
   *         x,y            ����λ������
   *         pHead          �û�ͨ�������׵�ַ
   *         pDate          �û�������ͷ���
   *����ֵ  :
   *         �ɹ��򷵻�ͨ������ͷ���
   *         ʧ���򷵻ؿ�
   *�޸ļ�¼: ���ڣ�2019.8.21            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
PULink My_DateControl(int x,int y,PULink pHead,PUser pDate);

/************************************************************************/
/* 
   *��������:PULink Select_RecordTIME(PULink pHead,int ForthDate,int BackDate);
   *��������:ѡ���¼��ʱ���
   *����˵��: 
   *         pHead          �û�ͨ�������׵�ַ
   *         ForthDate      ��ʼ����
   *         BackDate       ��ֹ����
   *����ֵ  :
   *         �ɹ��򷵻�ͨ������ͷ���
   *         ʧ���򷵻ؿ�
   *�޸ļ�¼: ���ڣ�2019.8.21            �޸���:���ǿ�
   *����    :                                                             
                                                                        */
PULink Select_RecordTIME(PULink pHead,int ForthDate,int BackDate);

#endif