#include "qmyedit.h"

QMyEdit::QMyEdit(QWidget *parent) :
    QLineEdit(parent)
{
    mySianalValue = 0;
    //����Ϊ͸��
    this->setStyleSheet("color:white;background:transparent;border-width:0;border-style:outset");
    //��������
    this->setFont(QFont("KaiTi_GB2312",15, QFont::Bold));
}

void QMyEdit::keyPressEvent(QKeyEvent *event)
{
    QLineEdit::keyPressEvent(event);
    event->accept();
}

int QMyEdit::MySianalValue()
{
    return mySianalValue;
}

void QMyEdit::setMySignalValue(int tpye)
{
    mySianalValue = tpye;
}
