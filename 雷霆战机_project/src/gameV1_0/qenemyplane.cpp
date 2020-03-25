#include "qenemyplane.h"

#include "qbloodstrip.h"

QEnemyPlane::QEnemyPlane(  QGraphicsScene *scene ) :
    QPlaneItem(scene)
{
    //���λ��
    QTime time;
    time= QTime::currentTime();
    qsrand(time.msec()+time.second()*1000);
    int iw = scene->width();
    iw -= 100;
    int w = qrand()%iw + 100/2;
    setPos(w,0);

    //����һ��·��
    modeRoute = qrand()%4;

    //�ɻ�ͼƬ����
    QResources *source = QResources::GetInstance();

    speed = 100;
    direction = 0;//��ʼ����
    //��������//�ɻ����Գ�ʼ��
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
    integral = this->blood()*5;//����

    //����Ѫ��ͼԪ
    QBloodStrip *myblood;
    myblood = new QBloodStrip(this);
}

#include "qscene.h"
void QEnemyPlane::sendBullt()
{
    QEnemyBullet *enemyBullet = new QEnemyBullet(scene());
    enemyBullet->setPos(x(),y());

    //�ӵ���ʽ
    QResources *source = QResources::GetInstance();
    QString bullet("EnemyBullet0");
    bullet = bullet + QString::number(modeRoute+1)+QString(".png");
    enemyBullet->setPix(&source->gamePix[bullet]);
}

void QEnemyPlane::activeEvent(QItem *boundingItem)
{
    switch(boundingItem->type())
    {
        case OURBULLET_I://�����ӵ�
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
    //�ƶ���ʽ
    switch(modeRoute)
    {
        case 0:step_Line(60);break;
        case 1:step_Horizontal();break;
        case 2:step_Rhombus();break;
        case 3:step_Circle();break;
    }
    //�����ӵ�
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
    double rad; // ����
    rad = angle * PI / 180;
    dy = (speed/100.0)*sin(rad);   // sin������Ĳ����ǻ��ȱ�ʾ��
    dx = -dy / tan(rad);
    moveBy(dx, dy);  //������ʽ�ƶ�
}

//�л�����ˮƽ·���ظ�����
void QEnemyPlane::step_Horizontal()
{
    //�л��ȴ�ֱ�ƶ���λ����ˮƽ�����˶�
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
        if(direction==0) //�����ƶ�
        {
            if(x<scene()->width()-90)
                dx = speed/100.0;
            else
            {
                direction=1;
            }
        }
        else  //�����ƶ�
        {
            if(x>100)
                dx = -speed/100.0;
            else
            {
                direction=0;
            }
        }
    }
    moveBy(dx, dy);  //������ʽ�ƶ�
}
//�����˶�
void QEnemyPlane::step_Rhombus()
{
    //�л��ȴ�ֱ�ƶ����е㣬��˳ʱ�������˶�
    qreal dx=0;
    qreal dy=0;
    double rad; // ����
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
        //��1���ߣ������·��˶�
        if(x<scene()->width()/2+150)
        {
            rad = 45 * PI / 180;
            dy = (speed/100.0)*sin(rad);   // sin������Ĳ����ǻ��ȱ�ʾ��
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
        //��2���ߣ������·��˶�
        if(x>scene()->width()/2)
        {
            rad = 45 * PI / 180;
            dy = (speed/100.0)*sin(rad);   // sin������Ĳ����ǻ��ȱ�ʾ��
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
        //��3���ߣ������Ϸ��˶�
        if(x>scene()->width()/2-150)
        {
            rad = 45 * PI / 180;
            dy = -(speed/100.0)*sin(rad);   // sin������Ĳ����ǻ��ȱ�ʾ��
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
        //��4���ߣ������Ϸ��˶�
        if(x<scene()->width()/2-10)
        {
            rad = 45 * PI / 180;
            dy = -(speed/100.0)*sin(rad);   // sin������Ĳ����ǻ��ȱ�ʾ��
            dx = -dy / tan(rad);
        }
        else
        {
            direction=0;
            //qDebug()<<"x="<<x<<", y="<<y;
        }
    }
    moveBy(dx, dy);  //������ʽ�ƶ�
}
//Բ���˶�
void QEnemyPlane::step_Circle()
{
    //�л��ȴ�ֱ�ƶ����е㣬��˳ʱ��Բ���˶�
    qreal dx=0;
    qreal dy=0;
    double rad; // ����
    qreal radius=100;  //�뾶100
    int x = pos().x();
    int y = pos().y();
    int centerx = 180;
    int centery = 200; //Բ������
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
        moveBy(dx, dy);  //������ʽ�ƶ�
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
        moveBy(dx, dy);  //������ʽ�ƶ�
        this->setRotation(-90+alpha);
    }
}

int QEnemyPlane::type() const
{
    return ENEMYPLANE_I;
}







