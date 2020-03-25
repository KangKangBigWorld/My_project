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

    void setCountDownPix();//���Ƶ���ʱͼƬ������

    void keyPressEvent(QKeyEvent *event);

    void startGame();//��ʼ��Ϸ
    void stopGame();//��ͣ��Ϸ
    void reGame();//�ؿ���Ϸ
    void exitGame();//�˳���Ϸ
    void focusInEvent(QFocusEvent *event);
    QString name;
private:
    QLabel *lab ;
    QMyWidget *lastFrom;
    bool bStop;//��Ϸ��ͣ
    QTimer timeCountdown;//����ʱʹ��
    int iCountDown;//����ʱ����
public slots:
    void startCount();//��ʼ����ʱʱ

    void countDown();//����ʱ����
    void endGame();//������Ϸ
    void stopReturn(int stopState);//��ͣ���淵��ֵ
};

#endif // QGAME_H
