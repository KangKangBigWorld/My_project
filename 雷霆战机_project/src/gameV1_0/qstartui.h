#ifndef QSTARTUI_H
#define QSTARTUI_H


#include "qmywidget.h"

#include <QFont>
#include <QPalette>
//居中显示
#include <QDesktopWidget>//获取分辨率
#include <QApplication>//

class QStartUi : public QMyWidget
{
    Q_OBJECT
public:
    explicit QStartUi(QMyWidget *parent = 0);
private:
    //按键大小
    QSize btnSize;
    QPoint btnBase;
    QPoint btnBps;
    QDesktopWidget *pDesktop;
    QLabel *pIconLTZJ;
    QLabel *pLabel;
    QLabel *pStar;
    QLabel *pPeole;
    QLabel *pCloud;
    QLabel *pCloud2;
    QLabel *pLight;
    QMyButton *pLoginBtn;
    QMyButton *pHelpBtn;
    QMyButton *pRankBtn;
    QMyButton *pAboutBtn;
    QMyButton *pExitBtn;
    QMyButton *pSetBtn;
    void setbg();
    void setlab();
    void setbtn();
    void AllButtonHide();
    void AllButtonShow();
signals:

public slots:
    void nextslots();//进入登录界面
    void helpslots();//进入帮助界面
    void rankslots();//进入排行榜界面
    void relslots();//进入关于界面
    void segslots();//设置页面
};

#endif // QSTARTUI_H
