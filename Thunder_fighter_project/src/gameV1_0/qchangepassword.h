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
    //用户名输入     changeEdit
    //回车键       顺序判断
    //获得焦点      做判断

    void nextFromslots();
    void nameMatchingslot();//用户名匹配
    void pwdfinishslot();
    void namefinishslot();
    void Answerfinishslot();
};

#endif // QCHANGEPASSWORD_H
