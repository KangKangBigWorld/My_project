#ifndef QGAMESTART_H
#define QGAMESTART_H

#include <QWidget>
#include "qguide.h"

class QGameStart : public QWidget
{
    Q_OBJECT
public:
    QGameStart(QWidget *parent = 0);
    void guide();
};

#endif // QGAMESTART_H
