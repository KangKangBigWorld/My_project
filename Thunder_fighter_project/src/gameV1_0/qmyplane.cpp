#include "qmyplane.h"

QMyPlane::QMyPlane( QGraphicsScene *scene ) :
    QPlaneItem(scene)
{
    //选择敌机
    selectPlane(1);

    //血条设置
    ibloodMax = 5;
    ienergy = 0;
    setBlood(ibloodMax);

    time = 15;
}

void QMyPlane::mouseMoveEvent(QMouseEvent *event)
{
    QPointF pof = event->pos();
    QPointF posMid(QPointF(boundPix->width()/2,boundPix->height()/2));
    QRectF rect;
    rect = scene()->sceneRect();
    if( (pof.x() - posMid.x() ) < rect.left()  || (pof.x() + posMid.x() ) > rect.right())
    {
        return;
    }
    if( (pof.y() - posMid.y() ) < rect.top()  || (pof.y() + posMid.y() ) > rect.bottom())
    {
        return;
    }
    this->setPos(event->pos());
}

void QMyPlane::mousePressEvent(QMouseEvent *event)
{
    //发射子弹
    sendbullet();
}

void QMyPlane::activeEvent(QItem *boundingItem)
{
    switch(boundingItem->type())
    {
    case ENEMYPLANE_I://敌机
        this->setDeath();
        boundingItem->setDeath();
        break;
    case ENEMYBULLET_I://敌方子弹
        dccBlood(((QEnemyBullet*)boundingItem)->hurt);
        boundingItem->setDeath();
        break;
    case PROP_I://道具
        boundingItem->setDeath();
        break;
    }
}
#include "qscene.h"
void QMyPlane::integralEvent()
{
    ((QScene*)scene())->clearMyPlane();
    this->hide();
}

void QMyPlane::sendbullet()
{
    if(!sendBulletCd)
    {
        //按下构建子弹
        QMyBullet *bull = new QMyBullet(scene());
        bull->setPos(this->pos());
        QSingleTon *single = QSingleTon::GetInstance();
        single->musicBox.playSound(BulletBiuBiuBiu);
        sendBulletCd = true;
    }
}

void QMyPlane::sendbullet2()
{
    if(!sendBulletCd)
    {
        //按下构建子弹
        QMyBullet *bull = new QMyBullet(scene());
        bull->setPos(this->pos());
        QSingleTon *single = QSingleTon::GetInstance();
        single->musicBox.playSound(BulletBiuBiuBiu);
        sendBulletCd = true;
    }
}

void QMyPlane::sendClsCd()
{
    sendBulletCd = false;
}

void QMyPlane::selectPlane(int Num)
{
    QString name("MyPlane");
    name = name + QString::number(Num);
    name = name + QString("-");
    name = name + QString::number(STATE1);
    name += QString(".png");

    //qDebug()<<name;
    QResources *source = QResources::GetInstance();
    boundPix = &source->gamePix[name];
}

void QMyPlane::moveRouteEvent()
{
    time--;
    if(time == 0)
    {
        time = 15;
        sendClsCd();
    }

    if(this->pos().x()-30>0&&this->pos().x()+30<400&&this->pos().y()-130>0&&this->pos().y()+30<600)
    {
            if(FLAG==1)
        {
           moveBy(0,-3);
        }
        else if(FLAG==2)
        {
           moveBy(0,3);
        }
        else if(FLAG==3)
        {
           moveBy(-2,0);
        }
        else if(FLAG==4)
        {
           moveBy(2,0);
        }
    }
    else
    {
        if(FLAG==1)
    {
       moveBy(0,3);
    }
    else if(FLAG==2)
    {
       moveBy(0,-3);
    }
    else if(FLAG==3)
    {
       moveBy(2,0);
    }
    else if(FLAG==4)
    {
       moveBy(-2,0);
    }
        FLAG=0;
    }


}

void QMyPlane::setFlag(int num)
{
    FLAG=num;
}





