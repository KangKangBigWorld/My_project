#include "qmyedit.h"

QMyEdit::QMyEdit(QWidget *parent) :
    QLineEdit(parent)
{
    mySianalValue = 0;
    //设置为透明
    this->setStyleSheet("color:white;background:transparent;border-width:0;border-style:outset");
    //设置字体
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
