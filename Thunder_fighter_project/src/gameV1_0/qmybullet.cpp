#include "qmybullet.h"

int QMyBullet::dgree = 1;
QMyBullet::QMyBullet( QGraphicsScene *scene ) :
    QItem(scene)
{
    QString name(MYBULLET_NAME);
    name = name + QString::number(dgree);
    name += QString(".png");

    QResources *source = QResources::GetInstance();
    boundPix = &source->gamePix[name];

    hurt = 1;
}

void QMyBullet::moveRouteEvent()
{
    moveBy(0,-3);
}
