#ifndef QSCENE_H
#define QSCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QPainter>
#include "qresources.h"
#include "qenemyplane.h"
#include "qmyplane.h"


class QScene : public QGraphicsScene
{
    Q_OBJECT
public:
    QScene(QObject * parent = 0);
    void drawBackground(QPainter *painter, const QRectF &rect);
    void drawForeground(QPainter *painter, const QRectF &rect);

    QMyPlane *qmyPlane(){return myPlane;}
    void clearMyPlane(){ emit gameEnd(); myPlane = 0;}
    void newMyPlane(){myPlane = new QMyPlane(this);}
    void enemyDcc(int num = 1);
protected:

private:
    int bgY;//��ǰy����
    int bgSpeed;//y�����ƶ��ٶ�
    int enemyMax;//���л���
    int enemyCur;//��ǰ�л���
    QTimer timeFrame;//֡����
    QTimer timeAdvance;//ǰ��
    QTimer timeItem;//����ʱ������Ƿ�������ͼԪ
    QMyPlane *myPlane;//������
    QSingleTon *single;
signals:
    void gameEnd();
public slots:
    void newEnemy();
    void bgMove();
//��ͣ/����
    void start();
    void stop();
};

#endif // QSCENE_H
