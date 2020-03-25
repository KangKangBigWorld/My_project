#ifndef QGAME_H
#define QGAME_H

#include <QGraphicsView>
#include "qscene.h"
#include <QLabel>
#include "qgamestop.h"
#include "qgamestart.h"

class QGame : public QGraphicsView
{
    Q_OBJECT
public:
    QGame( QMyWidget * parent = 0 , QString name = QString());

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

    void setCountDownPix();//绘制倒计时图片和音乐

    void keyPressEvent(QKeyEvent *event);

    void startGame();//开始游戏
    void stopGame();//暂停游戏
    void reGame();//重开游戏
    void exitGame();//退出游戏
    void focusInEvent(QFocusEvent *event);
    QString name;
private:
    QLabel *lab ;
    QMyWidget *lastFrom;
    bool bStop;//游戏暂停
    QTimer timeCountdown;//倒计时使用
    int iCountDown;//倒计时计数
public slots:
    void startCount();//开始倒计时时

    void countDown();//倒计时操作
    void endGame();//结束游戏
    void stopReturn(int stopState);//暂停界面返回值
};

#endif // QGAME_H
