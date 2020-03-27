#include "qprop.h"

#include "qscene.h"

QProp::QProp(QGraphicsScene *scene ) :
    QItem(scene)
{
}

void QProp::moveRouteEvent()
{
    //ÒÆ¶¯
    if((((QScene *)scene())->qmyPlane())->x() > x())
    {
        moveBy(2,0);
    }
    else
    {
        moveBy(-2,0);
    }

    if((((QScene *)scene())->qmyPlane())->y() > y())
    {
        moveBy(0,2);
    }
    else
    {
        moveBy(0,-2);
    }
}
