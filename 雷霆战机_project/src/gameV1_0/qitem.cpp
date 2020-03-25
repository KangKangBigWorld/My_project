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
    //����ͼ�Զ�����
    if(boutViewDeath)
    {
        if(IsOutScene())
        {
            //����ͼ�¼�
            //qDebug()<<"0*******************";
            outSceneEvent();
            return;
        }
    }

    //�ƶ�·��
    moveRouteEvent();

    //�������
    if(bdeath)
    {
        //�����¼�
        deathEvent();
        if(type() != OURPLANE_I)
        {
            delete this;
        }
        return;
    }

    //�Ƿ������ײ���
    if(!type())
    {
        return;
    }

    //��ײ���
    QList<QGraphicsItem *> items = this->collidingItems();
    if(items.empty())
    {
        return;
    }

    //���ʵ�������ʲô����ͼԪ
    QList<QGraphicsItem *>::iterator its=items.begin();
    QItem *item;
    for(;its!=items.end();its++)
    {
        item=(QItem *)(*its);
        //��ײ�����Ƿ������ײ���
        if(!type())
        {
            continue;
        }
        this->activeEvent(item);//��ײ������ı仯
        item->passiveEvent(this);//��������ı仯
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

