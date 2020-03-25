#ifndef QMYBULLET_H
#define QMYBULLET_H

#include "qitem.h"

class QMyBullet : public QItem
{
public:
    QMyBullet( QGraphicsScene *scene );

    void moveRouteEvent();
    int type() const{return OURBULLET_I;}

    int hurt;//…À∫¶
    static int dgree;
};

#define MYBULLET_NAME "MyBullet"

#endif // QMYBULLET_H
