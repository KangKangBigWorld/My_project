#ifndef QDEATHEFFECT_H
#define QDEATHEFFECT_H

#include <QObject>
#include "qitem.h"
#include <QTimer>

class QDeathEffect : public QItem
{
    Q_OBJECT
public:
    explicit QDeathEffect( QGraphicsScene *scene );
    void setTime(int timeLong);

    void advance(int phase){}
private:
    int count;
    QTimer time;
signals:

public slots:
    void deleteSelf();
};

#endif // QDEATHEFFECT_H
