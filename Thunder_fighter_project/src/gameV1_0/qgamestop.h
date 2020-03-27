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
    void mySignal(int);//1 ���� 2 �ؿ�  3 �˳���Ϸ
public slots:
    void gameSet();//��Ϸ����
    void reGame();//�ؿ�
    void exitGame();//�˳���Ϸ
    void gameStart();//����
};

#endif // QGAMESTOP_H
