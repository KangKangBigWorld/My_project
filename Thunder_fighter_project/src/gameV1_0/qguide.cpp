#include "qguide.h"

#include "qsingleton.h"
QGuide::QGuide(QWidget *higherWidget)
    :QMyWidget(higherWidget)
{
    resize(400,400);

    //按钮设置
    next=new QMyButton("下页",this);
    next->setGeometry(QRect(330,40,50,50));

    back=new QMyButton("上页",this);
    back->setGeometry(QRect(280,40,50,50));

    exit=new QMyButton("退出",this);
    exit->setGeometry(QRect(10,25,100,30));

    connect(back,SIGNAL(clicked()),this,SLOT(pageback()));
    connect(exit,SIGNAL(clicked()),this,SLOT(exitbtn()));
    connect(next,SIGNAL(clicked()),this,SLOT(pagenext()));

    back->hide();

    addmap("./Image/Game/Course01.png");
    addmap("./Image/Game/Course02.png");
    addmap("./Image/Game/Course03.png");
    addmap("./Image/Game/Course04.png");
    addmap("./Image/Game/Course05.png");

    iCount = Course01;
    QSingleTon *single = QSingleTon::GetInstance();
    single->musicBox.playSound((MUISENAME)iCount);
}

void QGuide::addmap(QString mapFile)
{
    QPixmap map;
    map.load(mapFile);
    Lmap.push_back(map);
}

void QGuide::pageback()
{
    it--;
    iCount--;
    QSingleTon *single = QSingleTon::GetInstance();
    single->musicBox.playSound((MUISENAME)iCount);
    next->show();
    if(it == Lmap.begin())
    {
        back->hide();
    }
    this->repaint();
}

void QGuide::pagenext()
{
    it++;
    iCount++;
    QSingleTon *single = QSingleTon::GetInstance();
    single->musicBox.playSound((MUISENAME)iCount);
    back->show();
    if(it+1 == Lmap.end())
    {
        next->hide();
    }
    this->repaint();
}

void QGuide::exitbtn()
{
    higherWidget->show();
    emit mySignal();
    delete this;
}

void QGuide::paintEvent(QPaintEvent *)
{
    QPainter pal(this);
    pal.drawPixmap(this->rect(),(QPixmap)(*it));
}

void QGuide::show()
{
    it = Lmap.begin();
    QMyWidget::show();
}
