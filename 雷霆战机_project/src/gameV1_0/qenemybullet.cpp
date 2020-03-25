#include "qenemybullet.h"

QEnemyBullet::QEnemyBullet( QGraphicsScene *scene ) :
    QItem(scene)
{
    hurt = 1;
}

void QEnemyBullet::moveRouteEvent()
{
    moveBy(0,3);
}
