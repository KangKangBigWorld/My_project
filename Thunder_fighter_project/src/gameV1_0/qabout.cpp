#include "qabout.h"

QAbout::QAbout(QMyWidget *parent)
{
    //设置上级窗口
    higherWidget = parent;

    //设置字体
    QFont fon;
    fon.setFamily("仿宋");
    fon.setBold(true);
    fon.setPointSize(15);
    setFont(fon);

    //去掉标题栏
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    //设置模态窗口
    setWindowModality(Qt::WindowModal);

    //设置背景图
    QLabel *lab;
    resize(500,500);
    this->setGeometry(higherWidget->x()+(higherWidget->width()-this->width())/2,300,500,500);
    //绘制背景图
    lab = new QLabel(this);
    lab->setGeometry(this->rect());
    lab->setScaledContents(true);
    lab->setStyleSheet("QLabel{border-image:url(\"./Image/About/AboutAuthor.png\")}");

    //设置按键
    QMyButton *btn;
    QPixmap *p;
    btn = new QMyButton("退出",this);
    btn->setGeometry(QRect(137,425,225,50));
    connect( btn, SIGNAL(clicked()),this,SLOT(yesOrno()) );
    p = new QPixmap("./Image/About/AffirmBtn.png");
    btn->setPix(*p);


    lab = new QLabel(this);
    lab->setStyleSheet("QLabel{border-image:url(\"./Image/About/Plant_Left.png\")}");
    anim = new QPropertyAnimation(lab,"geometry");
    anim->setDuration(5000);
    anim->setLoopCount(-1);
    anim->setStartValue(QRect(-200,120,200,200));
    anim->setEndValue(QRect(500,120,150,150));
    anim->start();

    //设置文字
    lab = new QLabel(this);
    lab->setGeometry(QRect(90,300,400,100));
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::green);
    lab->setPalette(pa);
    lab->setText("作者：WF1905 何亚康");
}
