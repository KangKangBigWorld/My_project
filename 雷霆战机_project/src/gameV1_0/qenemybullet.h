#ifndef QENEMYBULLET_H
#define QENEMYBULLET_H

#include "qitem.h"

class QEnemyBullet : public QItem
{
public:
    QEnemyBullet( QGraphicsScene *scene );
    void moveRouteEvent();
    int type() const{return ENEMYBULLET_I;}
    int hurt;
};

#define ENEMYBULLET_NAME "EnemyBullet0"
#endif // QENEMYBULLET_H
