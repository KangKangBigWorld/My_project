#include "qgamestop.h"
#include "qsetfrom.h"
#include "qgame.h"
QGameStop::QGameStop(QWidget *parent)
{
    setParent(parent);
    //绘制背景图
    QResources *source = QResources::GetInstance();

    //模态窗口
    resize(parent->size());
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    //设置透明
    setAttribute(Qt::WA_TranslucentBackground, true);

    btn = new QMyButton(QRect(140,445,140,50),"重新游戏",this);
    btn->setPix(source->gamePix["SelectButton.png"]);
    connect(btn,SIGNAL(clicked()),this,SLOT(reGame()));

    btn = new QMyButton(QRect(140,510,140,50),"退出游戏",this);
    btn->setPix(source->gamePix["SelectButton.png"]);
    connect(btn,SIGNAL(clicked()),this,SLOT(exitGame()));

    //配置按钮
    btn = new QMyButton(this);
    btn->setPix(source->gamePix["GameSet.png"]);
    btn->setGeometry(320,500,50,50);
    connect(btn,SIGNAL(clicked()),this,SLOT(gameSet()));

    //配置标签
    QLabel *lab;
    lab = new QLabel(this);
    lab->setGeometry(0,0,400,50);
    lab->setScaledContents(true);
    lab->setPixmap(source->gamePix["Frame01.png"]);

    QSingleTon *single = QSingleTon::GetInstance();
    QString name = single->name;

    if(name.isEmpty())
    {
        name = QString("您是游客访问受限制");
        btn->setDisabled(true);
    }
    else
    {
        name = QString("尊敬的用户")+ name;
    }

    btn = new QMyButton(QRect(140,380,140,50),"继续游戏",this);
    btn->setPix(source->gamePix["SelectButton.png"]);
    connect(btn,SIGNAL(clicked()),this,SLOT(gameStart()));
    if(((QScene*)((QGame*)parent)->scene())->qmyPlane() == 0)
    {
        btn->setDisabled(true);
    }

    //文字
    lab = new QLabel(this);
    lab->setGeometry(0,0,400,50);
    lab->setText(name);
    QFont ft;
    ft.setPointSize(20);
    lab->setFont(ft);
    lab->setAlignment(Qt::AlignCenter);
    //设置颜色使用QPalette
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::yellow);
    lab->setPalette(pa);
}

void QGameStop::gameSet()
{
    QSetFrom *set;
    set = new QSetFrom(this,0);
    set->show();
    this->hide();
}

void QGameStop::keyPressEvent(QKeyEvent *event)
{
    QWidget::keyPressEvent(event);
    if(event->key() == Qt::Key_Escape)
    {
        gameStart();
    }
}

void QGameStop::reGame()
{
    emit mySignal(2);
}

void QGameStop::gameStart()
{
    emit mySignal(1);
    delete this;
}

void QGameStop::exitGame()
{
    emit mySignal(3);
    delete this;
}

