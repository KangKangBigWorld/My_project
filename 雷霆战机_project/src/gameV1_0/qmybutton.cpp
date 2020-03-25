#include "qmybutton.h"

QMyButton::QMyButton(QWidget *parent) :
    QPushButton(parent)
{
    pix = QPixmap("./Image/StartUI/StartUI_Button.png");
    QPalette p = palette();
    p.setColor(QPalette::ButtonText, QColor(255, 255, 255));
    setPalette(p);
}

QMyButton::QMyButton(QWidget *parent,QString map) :
    QPushButton(parent)
{
    pix = QPixmap(map);
}

QMyButton::QMyButton(const QString &text,QWidget *parent)
    :QPushButton(text,parent)
{
    pix = QPixmap("./Image/StartUI/StartUI_Button.png");
    QPalette p = palette();
    p.setColor(QPalette::ButtonText, QColor(255, 255, 255));
    setPalette(p);
}

QMyButton::QMyButton(const QString &text,QRect* rect,QWidget *parent)
    :QPushButton(text,parent)
{
    pix = QPixmap("./Image/StartUI/StartUI_Button.png");
    this->setGeometry(QRect(rect->x(),rect->y(),rect->width(),rect->height()));
    QPalette p = palette();
    p.setColor(QPalette::ButtonText, QColor(255, 255, 255));
    setPalette(p);

    QFont ft;
    ft.setPointSize(17);
    this->setFont(ft);
}

QMyButton::QMyButton(QRect rect,const QString text,QWidget *parent)
    :QPushButton(text,parent)
{
    this->setGeometry(QRect(rect.x(),rect.y(),rect.width(),rect.height()));
    QPalette p = palette();
    p.setColor(QPalette::ButtonText, QColor(255, 255, 255));
    setPalette(p);

    QFont ft;
    ft.setPointSize(17);
    this->setFont(ft);
}

void QMyButton::paintEvent(QPaintEvent *)
{
    QPainter pal(this);
    pal.drawPixmap(this->rect(),pix);
    pal.drawText(this->rect(),Qt::AlignCenter,this->text());
}

void QMyButton::enterEvent(QEvent *)
{
    QSingleTon *single = QSingleTon::GetInstance();
    single->musicBox.playSound(Touch);
    QPalette p = palette();
    p.setColor(QPalette::ButtonText, QColor(255, 0, 0));
    setPalette(p);
    move(QPoint(0,5)+pos());
}

void QMyButton::leaveEvent(QEvent *)
{
    QPalette p = palette();
    p.setColor(QPalette::ButtonText, QColor(255, 255, 255));
    setPalette(p);
    move(QPoint(0,-5)+pos());
}

void QMyButton::setPix(QPixmap &pix)
{
    this->pix = pix;
}




