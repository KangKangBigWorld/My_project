#include "qgamestart.h"

#include "qsingleton.h"
QGameStart::QGameStart(QWidget *parent)
    : QWidget(parent)
{
    QSingleTon *single = QSingleTon::GetInstance();
    if(single->name.isEmpty())
    {//�ο�ģʽ

    }
    else
    {//�û�ģʽ

    }

}

void QGameStart::guide()
{
    QGuide *w = new QGuide(this);
    w->show();
}
