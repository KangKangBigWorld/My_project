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
    int bgY;//当前y坐标
    int bgSpeed;//y坐标移动速度
    int enemyMax;//最大敌机数
    int enemyCur;//当前敌机数
    QTimer timeFrame;//帧速率
    QTimer timeAdvance;//前进
    QTimer timeItem;//过段时间决定是否生成新图元
    QMyPlane *myPlane;//本机类
    QSingleTon *single;
signals:
    void gameEnd();
public slots:
    void newEnemy();
    void bgMove();
//暂停/继续
    void start();
    void stop();
};

#endif // QSCENE_H
