#include "qplaneitem.h"

QPlaneItem::QPlaneItem(QGraphicsScene *scene) :
    QItem(scene)
{

}

int QPlaneItem::blood()
{
    return iBlood;
}

void QPlaneItem::setBlood(int blood)
{
    iBlood = blood;
}

void QPlaneItem::dccBlood(int hurt)
{
    iBlood -= hurt;
    if(iBlood <= 0)
    {
        setDeath();
    }
}

void QPlaneItem::deathEvent()
{
    QDeathEffect *deathEffect = new QDeathEffect(scene());
    deathEffect->setPos(x(),y());
    //积分处理
    integralEvent();
}
