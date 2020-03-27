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
//void returnPressed(); //������б༭����ʱ������س��������ź�.
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
    void nextFromslots();//ע����ɵ�ҳ��
    void nameslots();//�û�����Ҫ���������
    void pwdTureOpenslots();//ȷ�����뿪��������

    void namefinishslot();
    void pwdfinishslot();
    void pwdTurefinishslot();
    void Answerfinishslot();
};

#endif // QMYREGISTER_H
