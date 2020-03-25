#ifndef QSetFrom_H
#define QSetFrom_H

#include "qmywidget.h"
#include <QSlider>
#include <QLineEdit>
#include <QComboBox>
#include <QFont>
#include <QLabel>

class QSetFrom : public QMyWidget
{
    Q_OBJECT
public:
    explicit QSetFrom(QMyWidget *parent = 0);
    QSetFrom(QWidget *parent,int i);

private:
    QLabel *lab;
    void setSlider();
    QSlider* volumeslider;
    QSlider* soundslider;
    QLineEdit *lineEdit;
    QLineEdit *soundEdit;
    QComboBox *hard;//难度
    QComboBox *guide;//新手指导
signals:

public slots:
    void setEditVolume(int value);
    void setEditSound(int value);
    void setHard(int hard);
    void setGuide(int guide);
};

#endif // QSetFrom_H
