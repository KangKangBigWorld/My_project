#ifndef QMYREGISTER_H
#define QMYREGISTER_H

#include "qmywidget.h"
#include "qmyedit.h"
#include <QList>
#include <QComboBox>
#include <QRegExpValidator>
#include <QRegExp>
#include <QValidator>
#include "qmytip.h"
#include "qsingleton.h"
//void returnPressed(); //光标在行编辑框内时，点击回车即发出信号.
class QMyRegister : public QMyWidget
{
    Q_OBJECT
public:
    QMyRegister(QMyWidget *parent = 0);
private:
    void setbg();
    void setbtn();
    void setedit();

    QMyEdit *name;
    QMyEdit *pwd;
    QMyEdit *pwdTure;
    QComboBox *Question;
    QMyEdit *Answer;
    QMyWidget* pParent;

    QMyButton *pEnsureBtn;
    QMyButton *PCancelBtn;

signals:

public slots:
    void nextFromslots();//注册完成的页面
    void nameslots();//用户名需要满足的条件
    void pwdTureOpenslots();//确认密码开启的条件

    void namefinishslot();
    void pwdfinishslot();
    void pwdTurefinishslot();
    void Answerfinishslot();
};

#endif // QMYREGISTER_H
