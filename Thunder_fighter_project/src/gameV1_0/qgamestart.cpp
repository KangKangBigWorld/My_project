#include "qgamestart.h"

#include "qsingleton.h"
QGameStart::QGameStart(QWidget *parent)
    : QWidget(parent)
{
    QSingleTon *single = QSingleTon::GetInstance();
    if(single->name.isEmpty())
    {//游客模式

    }
    else
    {//用户模式

    }

}

void QGameStart::guide()
{
    QGuide *w = new QGuide(this);
    w->show();
}
