#ifndef QENEMYPLANE_H
#define QENEMYPLANE_H

#include "qplaneitem.h"
#define PI 3.1415929
#include <math.h>
#include <QObject>
#include <QTime>

class QEnemyPlane : public QPlaneItem
{
    Q_OBJECT
public:
    QEnemyPlane( QGraphicsScene *scene);
    //碰撞类型
    int type() const;

    //移动
    void moveRouteEvent();

    //死亡事件 之
    //出界事件
    void outSceneEvent();
    //积分处理
    void integralEvent();

    //主动撞击
    void activeEvent(QItem *boundingItem);
private:
    int speed;
    int direction;
    int modeRoute;
    int integral;
    int iCount;//子弹射速
    //飞机轨迹
    void step_Line(int angle);
    void step_Horizontal();
    void step_Rhombus();
    void step_Circle();
public slots:
    void sendBullt();
};

#endif // QENEMYPLANE_H
