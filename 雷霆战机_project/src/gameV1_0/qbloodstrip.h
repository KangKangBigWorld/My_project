#ifndef QBLOODSTRIP_H
#define QBLOODSTRIP_H

#include "qitem.h"

class QBloodStrip : public QItem
{
public:
    QBloodStrip( QItem * parent );
    void paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0 );
private:
    QPixmap *pixCur;
    int max;
};

#endif // QBLOODSTRIP_H
