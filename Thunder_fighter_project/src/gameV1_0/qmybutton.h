#ifndef QMYBUTTON_H
#define QMYBUTTON_H

#include <QPushButton>//������
#include <QEvent>//�¼���   ��ͼ��
#include <QPixmap>//ͼƬ������
#include <QPainter>//��ͼ��
#include <QDebug>//������
#include <QKeyEvent>
#include "qsingleton.h"
#include <QMouseEvent>

class QMyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QMyButton(QWidget *parent = 0);
    QMyButton(QWidget *parent,QString map);
    QMyButton(const QString &text,QWidget *parent = 0);
    QMyButton(const QString &text,QRect *rect,QWidget *parent = 0);
    QMyButton(QRect rect,const QString text,QWidget *parent = 0);

    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

    void setPix(QPixmap &pix);

    void mouseMoveEvent(QMouseEvent *e){}

private:
    QPixmap pix;
signals:
    void changePix();
    //void clickedSignals();
public slots:

};

#endif // QMYBUTTON_H
