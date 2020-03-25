#include "qwindowmanger.h"

QWindowManger* QWindowManger::intence=NULL;

QWindowManger::QWindowManger()
{
    //¿ªÊ¼½çÃæ
    this->pStart=new QStartUi();
    //µÇÂ¼µ¯´°
    this->pLoginPopup=new  QLoginUi(pStart);
    //ÅÅÐÐ°ñ
    this->pRankList=new QRankingList(pStart);
    //°ïÖú
    this->pHelp=new QHelpPage(pStart);
    //¹ØÓÚ
    this->pAbout=new QAbout(pStart);
    //ÉèÖÃ
    this->pSetFrom=new QSetFrom(pStart);
    //×¢²á
    this->pRegister=new QMyRegister(pStart);
    //ÐÞ¸ÄÃÜÂë
    this->ChangePassword=new QChangePassword(pStart);
//    //×¢²áµ¯´°
//    this->pRegisterPopup=new RegisterPopup(pLoginWidget);
//    //ÐÞ¸ÄÃÜÂëµ¯´°
//    this->pChangePwdPopup=new ChangePwdPopup(pLoginWidget);
//    //ÍË³öµ¯´°
//    this->pExitTipPopup=new TipPopup("Exit",pLoginWidget);
    //×¢Ïúµ¯¿ò
    //this->pLogoutTipPopup=new TipPopup("Logout",pLoginWidget);
    //·µ»Øµ¯¿ò
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
