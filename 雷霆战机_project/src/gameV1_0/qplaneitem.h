#ifndef QPLANEITEM_H
#define QPLANEITEM_H

#include "qitem.h"
#include "qmybullet.h"
#include "qenemyBullet.h"
#include "qdeatheffect.h"

class QPlaneItem : public QItem
{
public:
    explicit QPlaneItem(QGraphicsScene *scene);

    //����
    int blood();
    void setBlood(int blood);
    void dccBlood(int hurt);

    //�����¼�
    void deathEvent();

    //���ִ���
    virtual void integralEvent(){}
private:
    int iBlood;//Ѫ��
};

#endif // QPLANEITEM_H
