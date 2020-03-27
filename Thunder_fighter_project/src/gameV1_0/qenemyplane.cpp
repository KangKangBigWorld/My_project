#include "qenemyplane.h"

#include "qbloodstrip.h"

QEnemyPlane::QEnemyPlane(  QGraphicsScene *scene ) :
    QPlaneItem(scene)
{
    //随机位置
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int iw = scene->width();
    iw -= 100;
    int w = qrand()%iw + 100/2;
    setPos(w,0);

    //设置一种路线
    modeRoute = qrand()%4;

    //飞机图片生成
    QResources *source = QResources::GetInstance();

    speed = 100;
    direction = 0;//初始方向
    //属性配置//飞机属性初始化
    switch(modeRoute)
    {
        case 0:
            boundPix = &source->gamePix["Enemy01.png"];
            setBlood(2);
            break;
        case 1:
            boundPix = &source->gamePix["Enemy03.png"];
            setBlood(3);
            break;
        case 2:
            boundPix = &source->gamePix["Enemy02.png"];
            setBlood(10);
            break;
        case 3:
            boundPix = &source->gamePix["Enemy04.png"];
            setBlood(5);
    }
    integral = this->blood()*5;//积分

    //生成血条图元
    QBloodStrip *myblood;
    myblood = new QBloodStrip(this);
}

#include "qscene.h"
void QEnemyPlane::sendBullt()
{
    QEnemyBullet *enemyBullet = new QEnemyBullet(scene());
    enemyBullet->setPos(x(),y());

    //子弹样式
    QResources *source = QResources::GetInstance();
    QString bullet("EnemyBullet0");
    bullet = bullet + QString::number(modeRoute+1)+QString(".png");
    enemyBullet->setPix(&source->gamePix[bullet]);
}

void QEnemyPlane::activeEvent(QItem *boundingItem)
{
    switch(boundingItem->type())
    {
        case OURBULLET_I://本机子弹
            dccBlood(((QMyBullet*)boundingItem)->hurt);
            boundingItem->setDeath();
            break;
    }
}

void QEnemyPlane::integralEvent()
{
    ((QScene *)scene())->enemyDcc();
    QSingleTon *single = QSingleTon::GetInstance();
    single->integral += integral;
}

void QEnemyPlane::outSceneEvent()
{
    ((QScene *)scene())->enemyDcc();
    delete this;
}

void QEnemyPlane::moveRouteEvent()
{
    //移动方式
    switch(modeRoute)
    {
        case 0:step_Line(60);break;
        case 1:step_Horizontal();break;
        case 2:step_Rhombus();break;
        case 3:step_Circle();break;
    }
    //发射子弹
    iCount++;
    if(iCount%60 == 0)
    {
        iCount = 1;
        sendBullt();
    }
}

void QEnemyPlane::step_Line(int angle)
{
    qreal dx;
    qreal dy;
    double rad; // 弧度
    rad = angle * PI / 180;
    dy = (speed/100.0)*sin(rad);   // sin函数里的参数是弧度表示的
    dx = -dy / tan(rad);
    moveBy(dx, dy);  //步进方式移动
}

//敌机按照水平路径重复步进
void QEnemyPlane::step_Horizontal()
{
    //敌机先垂直移动到位，再水平反复运动
    qreal dx=0;
    qreal dy=0;
    int x = pos().x();
    int y = pos().y();
    if(y<150)
    {
        dy = speed/100.0;
        dx =0;
    }
    else
    {
        if(direction==0) //向右移动
        {
            if(x<scene()->width()-90)
                dx = speed/100.0;
            else
            {
                direction=1;
            }
        }
        else  //向左移动
        {
            if(x>100)
                dx = -speed/100.0;
            else
            {
                direction=0;
            }
        }
    }
    moveBy(dx, dy);  //步进方式移动
}
//菱形运动
void QEnemyPlane::step_Rhombus()
{
    //敌机先垂直移动到中点，再顺时针菱形运动
    qreal dx=0;
    qreal dy=0;
    double rad; // 弧度
    int x = pos().x();
    int y = pos().y();

    if(direction==-1)
    {
        if(y<100)
        {
            dy = speed/100.0;
            dx =0;
        }
        else
        {
            dy = speed/100.0;
            dx =0;
            direction=0;
        }
    }
    else if(direction==0)
    {
        //第1条边，向右下方运动
        if(x<scene()->width()/2+150)
        {
            rad = 45 * PI / 180;
            dy = (speed/100.0)*sin(rad);   // sin函数里的参数是弧度表示的
            dx = dy / tan(rad);
        }
        else
        {
            direction=1;
            //qDebug()<<"x="<<x<<", y="<<y;
        }
    }
    else if(direction==1)
    {
        //第2条边，向左下方运动
        if(x>scene()->width()/2)
        {
            rad = 45 * PI / 180;
            dy = (speed/100.0)*sin(rad);   // sin函数里的参数是弧度表示的
            dx = -dy / tan(rad);
        }
        else
        {
            direction=2;
            //qDebug()<<"x="<<x<<", y="<<y;
        }
    }
    else if(direction==2)
    {
        //第3条边，向左上方运动
        if(x>scene()->width()/2-150)
        {
            rad = 45 * PI / 180;
            dy = -(speed/100.0)*sin(rad);   // sin函数里的参数是弧度表示的
            dx = dy / tan(rad);
        }
        else
        {
            direction=3;
            //qDebug()<<"x="<<x<<", y="<<y;
        }
    }
    else
    {
        //第4条边，向右上方运动
        if(x<scene()->width()/2-10)
        {
            rad = 45 * PI / 180;
            dy = -(speed/100.0)*sin(rad);   // sin函数里的参数是弧度表示的
            dx = -dy / tan(rad);
        }
        else
        {
            direction=0;
            //qDebug()<<"x="<<x<<", y="<<y;
        }
    }
    moveBy(dx, dy);  //步进方式移动
}
//圆形运动
void QEnemyPlane::step_Circle()
{
    //敌机先垂直移动到中点，再顺时针圆形运动
    qreal dx=0;
    qreal dy=0;
    double rad; // 弧度
    qreal radius=100;  //半径100
    int x = pos().x();
    int y = pos().y();
    int centerx = 180;
    int centery = 200; //圆心坐标
    int alpha=0;
    if(direction==-1)
    {
        if(y<150)
        {
            dy = speed/100.0;
            dx =0;
        }
        else
        {

            direction=0;
            this->setRotation(-90);
        }
        moveBy(dx, dy);  //步进方式移动
    }
    else
    {
        qreal x1=0;
        qreal y1=0;

        direction++;
        alpha = (direction/2)%360;

        for(int i=0;i<360;i++)
        {
            rad = alpha * PI / 180;
            x1 = radius*sin(rad);
            y1 = radius*cos(rad);

            dx = (centerx+x1)-x;
            dy = (centery-y1)-y;
        }
        moveBy(dx, dy);  //步进方式移动
        this->setRotation(-90+alpha);
    }
}

int QEnemyPlane::type() const
{
    return ENEMYPLANE_I;
}







