#ifndef QMYPLANE_H
#define QMYPLANE_H

#include "qplaneitem.h"
#include <QMouseEvent>
#include <QPointF>
#include <QRectF>

class QMyPlane : public QPlaneItem
{
public:
    QMyPlane( QGraphicsScene *scene );

    void selectPlane(int Num);//0 1 2 3 4
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    int bloodMax(){return ibloodMax;}
    int energyMax(){return 100;}
    int energy(){return ienergy;}
    int type() const{return OURPLANE_I;}

    void activeEvent(QItem *boundingItem);

    //积分处理 属性保留
    void integralEvent();
    void sendClsCd();
    void moveRouteEvent();
    void sendbullet();
    void sendbullet2();
    void setFlag(int num);
private:
    int ibloodMax;//血条最大值
    int ienergy;//能量
    int time;
    bool sendBulletCd;
    int FLAG;
    //int 伤害  积分
public slots:

};

typedef enum
{
    MYPLANE1,
    MYPLANE2,
    MYPLANE3,
    MYPLANE4,
    MYPLANE5
}MYPLANE;
typedef enum
{
    STATE1 = 1,
    STATE2 = 2,
    STATE3 = 3
}STATE;

#define MYPLANE_NAME "MyPlane"

#endif // QMYPLANE_H
