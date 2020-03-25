#ifndef QWINDOWMANGER_H
#define QWINDOWMANGER_H


#include "qmywidget.h"
#include "qstartui.h"
#include "qloginui.h"//登录界面
#include "qrankinglist.h"//排行版界面
#include "qhelppage.h"//帮助界面
#include "qabout.h"//关于界面
#include "qsetfrom.h"//设置界面
#include "qmyregister.h"//注册界面
#include "qchangepassword.h"//修改密码
class QWindowManger
{
public:
    static QWindowManger* getIntence();
    static QWindowManger* intence;
    QStartUi *pStart;
    QLoginUi *pLoginPopup;
    QRankingList* pRankList;
    QHelpPage *pHelp;
    QAbout *pAbout;
    QSetFrom *pSetFrom;
    QMyRegister *pRegister;
    QChangePassword *ChangePassword;
//    RegisterPopup* pRegisterPopup;
//    ChangePwdPopup* pChangePwdPopup;
//    TipPopup* pExitTipPopup;
//    TipPopup* pLogoutTipPopup;
//    TipPopup* pReturnTipPopup;
private:

    QWindowManger();
    //~QWindowManger();
};

#endif // QWINDOWMANGER_H
