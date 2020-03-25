#include "qmywidget.h"
//只在构造函数中应用了
#include <QDesktopWidget>
#include <QApplication>


QMyWidget::QMyWidget(QWidget *parent)
{
    this->higherWidget = parent;
    this->setWindowTitle("雷霆战机");
    setWindowIcon(QIcon("./Image/StartUI/StartUI_Logo.png"));//图标

    //去掉标题栏
    this->setWindowFlags(Qt::FramelessWindowHint);

    //设置透明
    setAttribute(Qt::WA_TranslucentBackground, true);

    group = new QParallelAnimationGroup;
}

void QMyWidget::animStyleSheet(const QString styleSheet,int msecs,int loopCount,QSize &start,QSize &maxSize,QPoint &enterPoint)
{
    QLabel *lab;
    lab = new QLabel(this);
    lab->setStyleSheet(styleSheet);
    anim = new QPropertyAnimation(lab,"geometry");
    anim->setDuration(msecs);
    anim->setLoopCount(loopCount);
    anim->setKeyValueAt(0,QRect(enterPoint.x(),enterPoint.y(),start.width(),start.height()));
    anim->setKeyValueAt(0.8,QRect(enterPoint.x() - maxSize.width()/2,enterPoint.y()  - maxSize.height()/2,maxSize.width(),maxSize.height()));
    anim->setKeyValueAt(1,QRect(enterPoint.x(),enterPoint.y(),start.width(),start.height()));
    group->addAnimation(anim);

    group->start();
}

void QMyWidget::mousePressEvent(QMouseEvent *event)
{
    /*在这里还可以添加鼠标点击的范围，在鼠标点击顶部某一部分的区域时可以拖动窗口，点击其他地方没法拖动*/
    if(event->button()==Qt::LeftButton)
    {
        dragPosition=event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    if(event->button()==Qt::RightButton)
    {
        return ;
    }
}

void QMyWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()==Qt::LeftButton)
    {
        move(event->globalPos()-dragPosition);
        event->accept();
    }
}
#include "qmytip.h"
void QMyWidget::yesOrno()
{
    if(0 == higherWidget)
    {
        exit(0);
    }
    higherWidget->show();
    delete(this);
}

void QMyWidget::lastFromslots()
{
    QMyTip *tip2;
    tip2 = new QMyTip(this,RETURN);
}

