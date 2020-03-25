#include "qwindowmanger.h"

QHelpPage::QHelpPage(QMyWidget *parent):QMyWidget(parent)
{
    //设置上级窗口
    higherWidget = parent;
    pParent = parent;

    //设置字体
    QFont fon;
    fon.setFamily("仿宋");
    fon.setBold(true);
    fon.setPointSize(20);
    setFont(fon);

    //去掉标题栏
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    //设置模态窗口
    setWindowModality(Qt::WindowModal);

    //设置背景图
    QLabel *lab;
    resize(500,500);
    this->setGeometry(pParent->x()+(pParent->width()-this->width())/2,300,500,500);
    //绘制背景图
    lab = new QLabel(this);
    lab->setGeometry(this->rect());
    lab->setStyleSheet("QLabel{border-image:url(\"./Image/About/Help.png\")}");

    //设置按键
    QMyButton *btn;
    QPixmap *p;
    btn = new QMyButton("退出",this);
    btn->setGeometry(QRect(137,425,225,50));
    connect( btn, SIGNAL(clicked()),this,SLOT(yesOrno()) );
    p = new QPixmap("./Image/About/AffirmBtn.png");
    btn->setPix(*p);
}


