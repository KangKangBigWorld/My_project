#ifndef QPROP_H
#define QPROP_H

#include "qitem.h"

class QProp : public QItem
{
public:
    QProp( QGraphicsScene *scene );
    void moveRouteEvent();
    int type() const{return PROP_I;}
private:
};

#endif // QPROP_H
