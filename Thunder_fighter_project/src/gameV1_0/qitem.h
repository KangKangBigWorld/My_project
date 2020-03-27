#ifndef QITEM_H
#define QITEM_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <QRectF>
#include <QWidget>
#include <QObject>
#include "qresources.h"
#include "qsingleton.h"

class QItem : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit QItem( QGraphicsItem * parent );
    QItem( QGraphicsScene *scene,QGraphicsItem * parent = 0);
    void setPix(QPixmap *pix);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    QRectF boundingRect() const;

    //前进拆分
    virtual void advance(int phase);

    //移动路线
    virtual void moveRouteEvent(){}

    //死亡与否
    virtual bool IsDeath() const { return bdeath;}
    void setDeath(bool death = true){bdeath = death;}

    //死亡事件
    virtual void deathEvent(){}

    //碰撞主动体的变化
    virtual void activeEvent(QItem *boundingItem ){}
    //被碰物体的变化
    virtual void passiveEvent(QItem *boundingItem){}

    //用于识别碰撞物体的类型
    virtual int type() const{ return 0;}

    virtual void outSceneEvent(){delete this;}

protected:
    QPixmap *boundPix;
private:
    bool bdeath;//是否死亡 默认否
    bool boutViewDeath;//出视图自动死亡 默认是

    //视图外自动消亡
    bool IsOutScene();//死亡返回 true
};

typedef enum
{
    DEFAULT,//默认
    BACKGROUND_I,//背景
    OURPLANE_I,//本机
    ENEMYPLANE_I,//敌机
    OURBULLET_I,//我的子弹
    ENEMYBULLET_I,//敌方子弹
    PROP_I,//道具
    TYPE_ITEM_MAX//枚举最大值
}TYPE_ITEM;

#endif // QITEM_H
