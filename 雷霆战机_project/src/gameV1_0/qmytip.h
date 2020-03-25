#ifndef QMYTIP_H
#define QMYTIP_H

#include "qmybutton.h"
#include <QLabel>

enum break_mode
{
    EXIT,
    LOGOUT,
    RETURN
};

class QMyTip : public QWidget
{
    Q_OBJECT
public:
    QMyTip(QWidget *parent,QString tip);
    QMyTip(QWidget *parent,break_mode mode);
    ~QMyTip();
    void setTipInfo(QString tip);
    void keyPressEvent(QKeyEvent *);
private:
    QLabel *label;
    QMyButton* SureButton;
    QMyButton*  CancleButton;
    QPushButton* btn;
    bool keyClose;
signals:

public slots:
};

#endif // QMYTIP_H
