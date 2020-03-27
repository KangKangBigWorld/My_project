#include "qmywidget.h"
//ֻ�ڹ��캯����Ӧ����
#include <QDesktopWidget>
#include <QApplication>


QMyWidget::QMyWidget(QWidget *parent)
{
    this->higherWidget = parent;
    this->setWindowTitle("����ս��");
    setWindowIcon(QIcon("./Image/StartUI/StartUI_Logo.png"));//ͼ��

    //ȥ��������
    this->setWindowFlags(Qt::FramelessWindowHint);

    //����͸��
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
    /*�����ﻹ�������������ķ�Χ�������������ĳһ���ֵ�����ʱ�����϶����ڣ���������ط�û���϶�*/
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

