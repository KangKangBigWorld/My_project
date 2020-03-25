#include "qbloodstrip.h"

#include "qplaneitem.h"
QBloodStrip::QBloodStrip( QItem * parent) :
    QItem(parent)
{
    QResources *source = QResources::GetInstance();
    pixCur = &source->gamePix["Enemy_Blood1.png"];
    boundPix = &source->gamePix["Enemy_Blood2.png"];
    max = (((QPlaneItem *)(this->parentItem()))->blood());
}

void QBloodStrip::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-30,0,60,30,*boundPix);
    int cur;
    cur = (((QPlaneItem *)(this->parentItem()))->blood());
    painter->drawPixmap(-30+1.0*(max - cur)/max*30,0,60.0*cur/max,30,*pixCur);
}

