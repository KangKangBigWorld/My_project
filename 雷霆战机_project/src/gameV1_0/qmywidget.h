#ifndef QMYWIDGET_H
#define QMYWIDGET_H

#include "qsingleton.h"
#include <QPropertyAnimation>   //小动画制作
#include <QParallelAnimationGroup>
#include <QMouseEvent>
#include "qmyedit.h"
#include "qmybutton.h"
#include <QLabel>


class QMyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QMyWidget(QWidget *parent = 0);
    void animStyleSheet(const QString styleSheet,int msecs,int loopCount,QSize &start,QSize &maxSize,QPoint &enterPoint);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

protected://这里构造都不用
    QParallelAnimationGroup *group;
    QPropertyAnimation *anim;
    QPoint dragPosition;//位置
    QWidget *higherWidget;
private:

signals:

public slots:
    void yesOrno();
    void lastFromslots();
};

#endif // QMYWIDGET_H
