#include "qscene.h"

#include "qsingleton.h"
QScene::QScene( QObject * parent ) :
    QGraphicsScene(parent)
{
    this->setSceneRect(0,0,400,600);

    //每一帧画面检查
    connect(&timeFrame,SIGNAL(timeout()),this,SLOT(advance()));
    connect(&timeAdvance,SIGNAL(timeout()),this,SLOT(bgMove()));

    //飞机数量检查
    connect(&timeItem,SIGNAL(timeout()),this,SLOT(newEnemy()));

    single = QSingleTon::GetInstance();
    bgY = 0;
    enemyCur = 0;
    bgSpeed = 2;
    enemyMax = single->hard;

    //添加本机类
    myPlane = new QMyPlane(this);
    myPlane->setPos(200,450);
}

void QScene::newEnemy()
{
    if(enemyCur < enemyMax)
    {
        enemyCur++;
        QEnemyPlane *enemy;
        enemy= new QEnemyPlane(this);
    }
}

void QScene::drawForeground(QPainter *painter, const QRectF &rect)
{
    QResources *source = QResources::GetInstance();
    if(0 == myPlane)
    {
        painter->drawPixmap(89,3,0,14,source->gamePix["MyPlane_Blood.png"]);
        return;
    }
    //绘制状态栏
    painter->drawPixmap(0,0,400,35,source->gamePix["MyPlane_BloodSlot.jpg"]);
    painter->drawPixmap(89,3,188.0*(myPlane->blood())/(myPlane->bloodMax()),14,source->gamePix["MyPlane_Blood.png"]);
    painter->drawPixmap(82,15,187.0*(myPlane->energy())/(myPlane->energyMax()),14,source->gamePix["MyPlane_Energy.png"]);

    QSingleTon *single = QSingleTon::GetInstance();
    QString inter = QString::number(single->integral);
    painter->setFont(QFont("黑体",20));
    painter->setPen(Qt::yellow);
    painter->drawText(320,10,80,20,Qt::AlignCenter,inter);
/*
    painter->setFont(QFont("黑体",10));
    painter->setPen(Qt::red);
    painter->drawText(0,0,80,20,Qt::AlignCenter,single->name);
*/
}

void QScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    QResources *source = QResources::GetInstance();
    //绘制背景
    if(enemyMax==0)
    {
        painter->drawPixmap(0,this->bgY,400,600,source->gamePix["Sky.jpg"]);
        painter->drawPixmap(0,this->bgY-600,400,600,source->gamePix["Sky.jpg"]);
    }
    else if(enemyMax==1)
    {
        painter->drawPixmap(0,this->bgY,400,600,source->gamePix["Forest.jpg"]);
        painter->drawPixmap(0,this->bgY-600,400,600,source->gamePix["Forest.jpg"]);
    }
    else if(enemyMax==2)
    {
        painter->drawPixmap(0,this->bgY,400,600,source->gamePix["Desert.jpg"]);
        painter->drawPixmap(0,this->bgY-600,400,600,source->gamePix["Desert.jpg"]);
    }

}


void QScene::bgMove()
{
    bgY += bgSpeed;
    if(bgY >= 600)
    {
        bgY=0;
    }
    update();
}

void QScene::start()
{
    timeItem.start(1200);
    timeFrame.start(30);
    timeAdvance.start(30);

}
void QScene::stop()
{
    timeItem.stop();
    timeFrame.stop();
    timeAdvance.stop();
}

void QScene::enemyDcc(int num)
{
    enemyCur -= num;
}






