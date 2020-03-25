#ifndef QWINDOWMANGER_H
#define QWINDOWMANGER_H


#include "qmywidget.h"
#include "qstartui.h"
#include "qloginui.h"//��¼����
#include "qrankinglist.h"//���а����
#include "qhelppage.h"//��������
#include "qabout.h"//���ڽ���
#include "qsetfrom.h"//���ý���
#include "qmyregister.h"//ע�����
#include "qchangepassword.h"//�޸�����
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
