#include "qwindowmanger.h"

QWindowManger* QWindowManger::intence=NULL;

QWindowManger::QWindowManger()
{
    //��ʼ����
    this->pStart=new QStartUi();
    //��¼����
    this->pLoginPopup=new  QLoginUi(pStart);
    //���а�
    this->pRankList=new QRankingList(pStart);
    //����
    this->pHelp=new QHelpPage(pStart);
    //����
    this->pAbout=new QAbout(pStart);
    //����
    this->pSetFrom=new QSetFrom(pStart);
    //ע��
    this->pRegister=new QMyRegister(pStart);
    //�޸�����
    this->ChangePassword=new QChangePassword(pStart);
//    //ע�ᵯ��
//    this->pRegisterPopup=new RegisterPopup(pLoginWidget);
//    //�޸����뵯��
//    this->pChangePwdPopup=new ChangePwdPopup(pLoginWidget);
//    //�˳�����
//    this->pExitTipPopup=new TipPopup("Exit",pLoginWidget);
    //ע������
    //this->pLogoutTipPopup=new TipPopup("Logout",pLoginWidget);
    //���ص���
    //this->pReturnTipPopup=new TipPopup("Return",pLoginWidget);
}


QWindowManger* QWindowManger::getIntence()
{
    if(QWindowManger::intence==NULL)
    {
        QWindowManger::intence=new QWindowManger;
    }
    return QWindowManger::intence;
}
