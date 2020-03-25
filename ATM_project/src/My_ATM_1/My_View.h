#ifndef _MY_VIEW_H_
#define _MY_VIEW_H_
#include <stdio.h>
#include <windows.h>
#include "GoTo_XY.h"
#include "User_LinkList.h"

/******************************�궨��***************************************/
#define BLACK   0   //��ɫ
#define DBLUE   1   //��ɫ 
#define DGREEN  2   //��ɫ
#define BLUE    3   //����ɫ
#define RED     4   //��ɫ
#define VIOLET  5   //��ɫ 
#define YELLOW  6   //��ɫ
#define WHITE   7   //��ɫ
#define GRAY    8   //��ɫ 
#define LBLUE   9   //����ɫ
#define GREEN   10  //����ɫ
#define LGREEN  11  //��ǳ��ɫ
#define LRED    12  //����ɫ
#define LVIOLET 13  //����ɫ
#define LYELLOW 14  //����ɫ
#define LWHITE  15  //����ɫ

/***********************************�������Ͷ���********************************/




/******************************����ԭ��***************************************/

/************************************************************************/
/*                                                                      
   *��������:void color(int iFore,int iBack);
   *��������:�ͷ�ͨ������
   *����˵��:
   *        iFore       ǰ��ɫ���ֵ���ɫ��
   *        iBack       ����ɫ����������ɫ��
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.11            �޸���:���ǿ�
   *����    :
����0=��ɫ                8=��ɫ����
��  1=��ɫ                9=����ɫ        ʮ������        ����                        
����2=��ɫ                10=����ɫ       0xa        ����
����3=����ɫ              11=��ǳ��ɫ     0xb��
����4=��ɫ                12=����ɫ       0xc����
����5=��ɫ                13=����ɫ       0xd        ����
����6=��ɫ                14=����ɫ       0xe        ����
����7=��ɫ                15=����ɫ       0xf 
����Ҳ���԰���Щֵ���óɳ�����
                                                                        */
void color(int iFore,int iBack);

/************************************************************************/
/*                                                                      
   *��������:void Draw_line(int x,int y,int iLen);
   *��������:����
   *����˵��:
   *        x           ������Ͻǳ��ֵĺ�����
   *        y           ������Ͻǳ��ֵ�������
   *        iLen         ����
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.12            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Draw_line(int x,int y,int iLen);

/************************************************************************/
/*                                                                      
   *��������:void Draw_Button(int x,int y,int iSelect,int iSColor,int iNSColor));
   *��������:���ư�����򣬲�������������ڣ�ѡ�񰴼���ı���ʽ
   *����˵��:
   *        x           ������Ͻǳ��ֵĺ�����
   *        y           ������Ͻǳ��ֵ�������
   *        iSelect     �Ƿ�ѡ�񰴼��ı�־
   *        iSColor     ѡ�񰴼�ʱ��������ɫ
   *        iNSColor    δѡ�񰴼�ʱ��������ɫ
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.12            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Draw_Button(int x,int y,int iSelect,int iSColor,int iNSColor);

/************************************************************************/
/*                                                                      
   *��������:void Draw_Warning(int x,int y,int iColor);
   *��������:���ƾ�����򣬲�������������ڣ�ѡ�񰴼���ı���ʽ
   *����˵��:
   *        x           ������Ͻǳ��ֵĺ�����
   *        y           ������Ͻǳ��ֵ�������
   *        iSelect     �Ƿ�ѡ�񰴼��ı�־
   *        iSColor     ѡ�񰴼�ʱ��������ɫ
   *        iNSColor    δѡ�񰴼�ʱ��������ɫ
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.14            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Draw_Warning(int x,int y,int iColor);

/************************************************************************/
/*                                                                      
   *��������:void Clear_Waring(int x,int y);
   *��������:�������
   *����˵��:
   *        x           ������Ͻǳ��ֵĺ�����
   *        y           ������Ͻǳ��ֵ�������
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.14            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Clear_Warning(int x,int y);

/************************************************************************/
/*                                                                      
   *��������:void Draw_Popup(int x,int y,int hight,int iColor,char* sTitle);
   *��������:���������
   *����˵��:
   *        x           ������Ͻǳ��ֵĺ�����
   *        y           ������Ͻǳ��ֵ�������
   *        hight       ���ĸ߶�
   *        iColor      ������ɫ
   *        Title       �����ı���
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.14            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Draw_Popup(int x,int y,int hight,int iColor,char* sTitle);


/************************************************************************/
/*                                                                      
   *��������:void Draw_FormIO(int x,int y);
   *��������:����һ��һ�ж��б��񣬲��ѹ���ƶ��������һ����
   *����˵��:
   *        x           �������Ͻǳ��ֵĺ�����
   *        y           �������Ͻǳ��ֵ�������
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.12            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Draw_FormIO(int x,int y);

/************************************************************************/
/*                                                                      
   *��������:void Clear_FormIO(int x,int y,char* cStr);
   *��������:��������ڵ��������ݲ��������롣
   *����˵��:
   *        x           �������Ͻǳ��ֵĺ�����
   *        y           �������Ͻǳ��ֵ�������
   *        cStr        ������ַ����׵�ַ
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.15            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Clear_FormIO(int x,int y,char* cStr);

/************************************************************************/
/*                                                                      
*��������:void Draw_Background(int iWide,int iHight);
   *��������:���Ʊ�������ӡ����������½���Ϣ
   *����˵��:
   *        iWide       ��������Ϊ2*iWide
   *        iHight      �����߶�ΪiHight
   *        sTitle      �����ַ����׵�ַ
   *        sLowLeft    ���½��ַ����׵�ַ
   *        sLowRight   ���½��ַ����׵�ַ
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.13            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Draw_Background(int iWide,int iHight);

/************************************************************************/
/*                                                                      
*��������:void Pritf_Tile(int iWide,int iHight,char* sTitle,char* sLowLeft,char* sLowRight);
   *��������:��ӡ����������½���Ϣ
   *����˵��:
   *        iWide       ��������Ϊ2*iWide
   *        iHight      �����߶�ΪiHight
   *        sTitle      �����ַ����׵�ַ
   *        sLowLeft    ���½��ַ����׵�ַ
   *        sLowRight   ���½��ַ����׵�ַ
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.13            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Pritf_Tile(int iWide,int iHight,char* sTitle,char* sLowLeft,char* sLowRight);


/************************************************************************/
/*                                                                      
   *��������:void My_Date();
   *��������:���������
   *����˵��:
   *        ��
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.13            �޸���:���ǿ�
   *����    :
��
                                                                        */
void My_ClearBG();




/************************************************************************/
/*                                                                      
*��������:void Draw_Main(void);
   *��������:
   *����˵��:
   *        ��
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.13            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Draw_Main(void);

/************************************************************************/
/*                                                                      
*��������:void Draw_Main_Button(int iFlag);
   *��������:���������水��
   *����˵��:
   *        iFlag       ����ѡ�񰴼��ź�
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.13            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Draw_Main_Button(int iFlag);


/************************************************************************/
/*                                                                      
*��������:void Draw_SignOut(int iFlag);
   *��������:�����˳�����
   *����˵��:
   *        iFlag       ����ѡ�񰴼��ź�
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.13            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Draw_SignOut(int iFlag);

/************************************************************************/
/*                                                                      
*��������:void Draw_UserWin();
   *��������:�û�����
   *����˵��:
   *        ��
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.16            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Draw_UserWin();

/************************************************************************/
/*                                                                      
*��������:void Draw_AdminWin();
   *��������:����Ա����
   *����˵��:
   *        ��
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.16            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Draw_AdminWin();

/************************************************************************/
/*                                                                      
*��������:void Draw_User_Button(int iFlag);
   *��������:�û�����
   *����˵��:
   *        iFlag       ����ѡ�񰴼��ź�
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.16            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Draw_User_Button(int iFlag);

/************************************************************************/
/*                                                                      
*��������:void Draw_Admin_Button(int iFlag);
   *��������:����Ա����
   *����˵��:
   *        iFlag       ����ѡ�񰴼��ź�
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.16            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Draw_Admin_Button(int iFlag);

/************************************************************************/
/*                                                                      
*��������:void Draw_Page(int x,int y);
   *��������:��ҳ����
   *����˵��:
   *        x           �������Ͻǳ��ֵĺ�����
   *        y           �������Ͻǳ��ֵ�������
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.16            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Draw_Page(int x,int y);


/************************************************************************/
/*                                                                      
*��������:void Draw_RecordPage(int x,int y);
   *��������:��¼�ı���
   *����˵��:
   *        x           �������Ͻǳ��ֵĺ�����
   *        y           �������Ͻǳ��ֵ�������
   *����ֵ  :
   *        ��
   *�޸ļ�¼: ���ڣ�2019.8.16            �޸���:���ǿ�
   *����    :
��
                                                                        */
void Draw_RecordPage(int x,int y);


#endif