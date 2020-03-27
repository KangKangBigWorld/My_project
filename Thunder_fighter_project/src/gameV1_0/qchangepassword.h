#ifndef QCHANGEPASSWORD_H
#define QCHANGEPASSWORD_H

#include "qmywidget.h"
#include "qsingleton.h"
#include <QRegExpValidator>
#include <QRegExp>
#include <QValidator>
#include "qmyedit.h"
#include "qmytip.h"

class QChangePassword : public QMyWidget
{
    Q_OBJECT
public:
    explicit QChangePassword(QMyWidget *parent = 0);
private:
    void setbtn();
    void setedit();
    QMyEdit *name;
    QMyEdit *pwd;
    QMyEdit *pwdTure;
    QMyEdit *Question;
    QMyEdit *Answer;
    QMyWidget* pParent;

    QMyButton *pEnsureBtn;
    QMyButton *PCancelBtn;
    bool cmpPwd();
signals:

public slots:
    //�û�������     changeEdit
    //�س���       ˳���ж�
    //��ý���      ���ж�

    void nextFromslots();
    void nameMatchingslot();//�û���ƥ��
    void pwdfinishslot();
    void namefinishslot();
    void Answerfinishslot();
};

#endif // QCHANGEPASSWORD_H
