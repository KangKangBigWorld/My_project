#ifndef QRANKINGLIST_H
#define QRANKINGLIST_H

#include "qmywidget.h"
#include "qsingleton.h"
#include "qmytip.h"
#include <QTableWidget>
#include <QList>
#include <QString>
#include <QPair>

class QRankingList :public QMyWidget
{
    Q_OBJECT
public:
    QRankingList(QMyWidget *parent = 0);
    bool paintPage();
public slots:
    void pageNextslots();
    void pageLastslots();
private:
    QTableWidget table;
    //QLabel table[7][3];
    int pageMax;
    int pageCur;
};

#endif // QRANKINGLIST_H
