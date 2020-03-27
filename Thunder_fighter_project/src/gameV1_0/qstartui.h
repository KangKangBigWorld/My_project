#ifndef QSTARTUI_H
#define QSTARTUI_H


#include "qmywidget.h"

#include <QFont>
#include <QPalette>
//������ʾ
#include <QDesktopWidget>//��ȡ�ֱ���
#include <QApplication>//

class QStartUi : public QMyWidget
{
    Q_OBJECT
public:
    explicit QStartUi(QMyWidget *parent = 0);
private:
    //������С
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
    void nextslots();//�����¼����
    void helpslots();//�����������
    void rankslots();//�������а����
    void relslots();//������ڽ���
    void segslots();//����ҳ��
};

#endif // QSTARTUI_H
