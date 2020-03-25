
#include "qgame.h"
QGame::QGame( QMyWidget * parent , QString name )
{
    //���ô����Զ���䱳�������ǣ�
    this->setAutoFillBackground(true);

    lastFrom = parent;
    lastFrom->hide();

    this->show();
    this->name = name;
    resize(400,600);

    lab = new QLabel(this);
    lab->setGeometry(100,100,200,40);

    QFont fon;
    fon.setFamily("����");
    fon.setBold(true);
    fon.setPointSize(18);
    lab->setFont(fon);

    bStop = true;

    setCursor(Qt::BlankCursor); //�������

    setMouseTracking(true);//�ƶ��¼��Ƿ���Ҫ��굥��
    this->show();
    //ȥ��������
    this->setWindowFlags(Qt::FramelessWindowHint);
    //�ޱ߿�
    this->setStyleSheet("border-style:outset");

    this->setWindowTitle("����ս��");
    setWindowIcon(QIcon("./Image/Icon/Icon.jpg"));//ͼ��

    //��������
    QScene *newScene = new QScene();
    this->setScene(newScene);
    connect(&timeCountdown,SIGNAL(timeout()),this,SLOT(countDown()));

    //��������������Ϸ����
    connect(newScene,SIGNAL(gameEnd()),this,SLOT(endGame()));


    QSingleTon *single = QSingleTon::GetInstance();
    single->name = name;
    single->integral = 0;
    if(single->guide && !(single->name.isEmpty()) )
    {
        QGuide *guide = new QGuide(this);
        connect(guide,SIGNAL(mySignal()),this,SLOT(startCount()));
        guide->show();
        single->guide = false;
    }
    else
    {
        //��ӵ���ʱ������
        startCount();
    }
}

void QGame::mousePressEvent(QMouseEvent *event)
{
    if(bStop)
    {
        return;
    }
    ((QScene*)scene())->qmyPlane()->mousePressEvent(event);
}

void QGame::mouseMoveEvent(QMouseEvent *event)
{
    if(bStop)
    {
        return;
    }
    ((QScene*)scene())->qmyPlane()->mouseMoveEvent(event);
}

//��ͣ����  ��ʱ��
void QGame::stopGame()
{
    bStop = true;
    timeCountdown.stop();
    //��ͣ����
    QGameStop *gameStop = new QGameStop(this);
    gameStop->show();
    connect(gameStop,SIGNAL(mySignal(int)),this,SLOT(stopReturn(int)));
    //�رն�ʱ��
    ((QScene*)scene())->stop();
}

void QGame::startGame()
{
    lab->hide();
    if(iCountDown < 5)
    {
        timeCountdown.start(1000);
    }
    else
    {
        bStop = false;
        QMyPlane *myPlane = ((QScene *)scene())->qmyPlane();
       ((QScene *)this->scene())->start();
        QCursor::setPos(x()+myPlane->x(),y()+myPlane->y());
    }
}

#include "qmytip.h"
#include "qrankinglist.h"
//1����ʾ�ɼ�   2���������а� ˢ���а�
void QGame::endGame()
{
    bStop = true;
    ((QScene *)this->scene())->stop();
    qDebug()<<"endGame";
    QSingleTon *single = QSingleTon::GetInstance();

    QString info("���Ļ���:");

    info = info + QString::number(single->integral);

    lab->setText(info);
    lab->show();
    if(name.isEmpty())
    {

    }
    else
    {
        single->info.addrank(name,single->integral);
        QRankingList *rank = new QRankingList((QMyWidget*)this);
        rank->show();
    }
    stopGame();
}
//1���ر���ͼ ����
void QGame::exitGame()
{
    //�رն�ʱ��
    ((QScene*)scene())->stop();

    ((QWidget*)lastFrom)->show();
    delete scene();
    this->deleteLater();
}


void QGame::countDown()
{
    QSingleTon *single = QSingleTon::GetInstance();
    switch(iCountDown++)
    {
        case 0:
        case 1:
        case 2:
            single->musicBox.playSound(_321);
            break;
        case 3:
            single->musicBox.playSound(ReadyGo);
            break;
        case 4:
            //��ʼ��Ϸ
            startGame();
            timeCountdown.stop();
            break;
    }
    setCountDownPix();
}

void QGame::startCount()
{
    this->show();
    timeCountdown.start(1000);
    iCountDown = 0;
}

void QGame::setCountDownPix()
{
    QResources *source = QResources::GetInstance();
    QString namePix(".png");
    namePix = QString::number(iCountDown) + namePix;
    QPixmap *pix = &source->gamePix[namePix];

    QDeathEffect *deathEffect;
    deathEffect = new QDeathEffect(scene());
    deathEffect->setPix(pix);
    deathEffect->setPos(width()/2,height()/2);
}

void QGame::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Escape:
            stopGame();
            break;
        case Qt::Key_X:
            ((QScene *)scene())->qmyPlane()->sendbullet();
            break;
        case Qt::Key_Space:
            ((QScene *)scene())->qmyPlane()->sendbullet2();
        break;
    case Qt::Key_1:
        ((QScene *)scene())->qmyPlane()->selectPlane(1);
    break;
    case Qt::Key_2:
        ((QScene *)scene())->qmyPlane()->selectPlane(2);
    break;
    case Qt::Key_3:
        ((QScene *)scene())->qmyPlane()->selectPlane(3);
    break;
    case Qt::Key_4:
        ((QScene *)scene())->qmyPlane()->selectPlane(4);
    break;
    case Qt::Key_W:
        ((QScene *)scene())->qmyPlane()->setFlag(1);
    break;
    case Qt::Key_S:
        ((QScene *)scene())->qmyPlane()->setFlag(2);
    break;
    case Qt::Key_A:
        ((QScene *)scene())->qmyPlane()->setFlag(3);
    break;
    case Qt::Key_D:
        ((QScene *)scene())->qmyPlane()->setFlag(4);
    break;
    }
}

void QGame::stopReturn(int stopState)
{
    //1 ���� 2 �ؿ�  3 �˳���Ϸ
    switch(stopState)
    {
        case 1:
            if(((QScene*)scene())->qmyPlane() ==  0)
            {
                this->stopGame();
            }
            else
            {
                this->startGame();
            }
            break;
        case 2:
            this->reGame();
            break;
        case 3:
            this->exitGame();
            break;
    }
}

void QGame::reGame()
{
    QGame *game;
    game = new QGame(lastFrom,name);
    game->show();
    ((QScene*)scene())->stop();
    delete scene();
    delete this;
}

#include <windef.h>
#include <windows.h>
void QGame::focusInEvent(QFocusEvent *event)
{
    /*
    RECT mainRect; //windef.h�б�����
    mainRect.left = (LONG)this->geometry().left()+50;
    mainRect.right = (LONG)this->geometry().right()-50;
    mainRect.top = (LONG)this->geometry().top()+100;
    mainRect.bottom = (LONG)this->geometry().bottom()-50;
    ClipCursor(&mainRect);
    */
}







