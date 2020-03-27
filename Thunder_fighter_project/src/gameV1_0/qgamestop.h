#ifndef QGAMESTOP_H
#define QGAMESTOP_H

#include <QWidget>
#include <QLabel>
#include "qsingleton.h"
#include "qmybutton.h"

class QGameStop : public QWidget
{
    Q_OBJECT
public:
    explicit QGameStop(QWidget *parent = 0);

    void keyPressEvent(QKeyEvent *);
private:
    QMyButton *btn;
signals:
    void mySignal(int);//1 继续 2 重开  3 退出游戏
public slots:
    void gameSet();//游戏设置
    void reGame();//重开
    void exitGame();//退出游戏
    void gameStart();//继续
};

#endif // QGAMESTOP_H
