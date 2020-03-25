#include "qitem.h"

QItem::QItem(QGraphicsItem *parent) :
    QGraphicsItem(parent)
{
    boundPix = 0;
    bdeath = false;
    boutViewDeath = true;
}

QItem::QItem( QGraphicsScene *scene,QGraphicsItem * parent ):
    QGraphicsItem(parent)
{
    boundPix = 0;
    bdeath = false;
    boutViewDeath = true;
    scene->addItem(this);
}

void QItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-boundPix->width()/2,-boundPix->height()/2,boundPix->width(),boundPix->height(),*boundPix);
}

QRectF QItem::boundingRect() const
{
    return QRectF(-boundPix->width()/2,-boundPix->height()/2,boundPix->width(),boundPix->height());
}

void QItem::advance(int phase)
{
    //qDebug()<<"*********type**********"<<type();
    //出视图自动死亡
    if(boutViewDeath)
    {
        if(IsOutScene())
        {
            //出视图事件
            //qDebug()<<"0*******************";
            outSceneEvent();
            return;
        }
    }

    //移动路线
    moveRouteEvent();

    //死亡与否
    if(bdeath)
    {
        //死亡事件
        deathEvent();
        if(type() != OURPLANE_I)
        {
            delete this;
        }
        return;
    }

    //是否进行碰撞检测
    if(!type())
    {
        return;
    }

    //碰撞检测
    QList<QGraphicsItem *> items = this->collidingItems();
    if(items.empty())
    {
        return;
    }

    //访问迭代器是什么类型图元
    QList<QGraphicsItem *>::iterator its=items.begin();
    QItem *item;
    for(;its!=items.end();its++)
    {
        item=(QItem *)(*its);
        //被撞物体是否进行碰撞检测
        if(!type())
        {
            continue;
        }
        this->activeEvent(item);//碰撞主动体的变化
        item->passiveEvent(this);//被碰物体的变化
    }
}

bool QItem::IsOutScene()
{
    if( ( this->x() > this->scene()->width())
            ||( this->y() > this->scene()->height() )
            ||( this->x() < 0 )
            ||(this->y() < 0)      )
    {
        return true;
    }
    return false;
}

void QItem::setPix(QPixmap *pix)
{
    boundPix = pix;
}

