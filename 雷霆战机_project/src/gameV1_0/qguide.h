#ifndef QHELPPAGE_H
#define QHELPPAGE_H

#include "qmywidget.h"
#include <QList>

class QGuide : public QMyWidget
{
    Q_OBJECT
public:
    QGuide(QWidget *higherWidget);
    void addmap(QString mapFile);
    void paintEvent(QPaintEvent *);
    void show();
protected:
    QMyButton *back;
    QMyButton *next;
    QMyButton *exit;
    QList<QPixmap> Lmap;
    QList<QPixmap>::iterator it;
    int iCount;
private:
signals:
    void mySignal();
public slots:
    void pageback();
    void pagenext();
    void exitbtn();
};

#endif // QHELPPAGE_H
