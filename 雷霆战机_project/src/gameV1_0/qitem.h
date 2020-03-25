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

    //ǰ�����
    virtual void advance(int phase);

    //�ƶ�·��
    virtual void moveRouteEvent(){}

    //�������
    virtual bool IsDeath() const { return bdeath;}
    void setDeath(bool death = true){bdeath = death;}

    //�����¼�
    virtual void deathEvent(){}

    //��ײ������ı仯
    virtual void activeEvent(QItem *boundingItem ){}
    //��������ı仯
    virtual void passiveEvent(QItem *boundingItem){}

    //����ʶ����ײ���������
    virtual int type() const{ return 0;}

    virtual void outSceneEvent(){delete this;}

protected:
    QPixmap *boundPix;
private:
    bool bdeath;//�Ƿ����� Ĭ�Ϸ�
    bool boutViewDeath;//����ͼ�Զ����� Ĭ����

    //��ͼ���Զ�����
    bool IsOutScene();//�������� true
};

typedef enum
{
    DEFAULT,//Ĭ��
    BACKGROUND_I,//����
    OURPLANE_I,//����
    ENEMYPLANE_I,//�л�
    OURBULLET_I,//�ҵ��ӵ�
    ENEMYBULLET_I,//�з��ӵ�
    PROP_I,//����
    TYPE_ITEM_MAX//ö�����ֵ
}TYPE_ITEM;

#endif // QITEM_H
