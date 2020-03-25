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
    //��ײ����
    int type() const;

    //�ƶ�
    void moveRouteEvent();

    //�����¼� ֮
    //�����¼�
    void outSceneEvent();
    //���ִ���
    void integralEvent();

    //����ײ��
    void activeEvent(QItem *boundingItem);
private:
    int speed;
    int direction;
    int modeRoute;
    int integral;
    int iCount;//�ӵ�����
    //�ɻ��켣
    void step_Line(int angle);
    void step_Horizontal();
    void step_Rhombus();
    void step_Circle();
public slots:
    void sendBullt();
};

#endif // QENEMYPLANE_H
