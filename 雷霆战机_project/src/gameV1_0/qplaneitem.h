#ifndef QPLANEITEM_H
#define QPLANEITEM_H

#include "qitem.h"
#include "qmybullet.h"
#include "qenemyBullet.h"
#include "qdeatheffect.h"

class QPlaneItem : public QItem
{
public:
    explicit QPlaneItem(QGraphicsScene *scene);

    //属性
    int blood();
    void setBlood(int blood);
    void dccBlood(int hurt);

    //死亡事件
    void deathEvent();

    //积分处理
    virtual void integralEvent(){}
private:
    int iBlood;//血量
};

#endif // QPLANEITEM_H
