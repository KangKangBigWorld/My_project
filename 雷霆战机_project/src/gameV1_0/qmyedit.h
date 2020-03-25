#ifndef QMYEDIT_H
#define QMYEDIT_H

#include <QLineEdit>
#include <QKeyEvent>
#include <QDebug>
#include <QString>
class QMyEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit QMyEdit(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *);
    void setMySignalValue(int tpye);
    int MySianalValue();
    void focusOutEvent(QFocusEvent *e)//失去焦点
    {
        QLineEdit::focusOutEvent(e);
        emit focusOut(mySianalValue);
    }
    void focusInEvent(QFocusEvent *e)//得到焦点
    {
        QLineEdit::focusInEvent(e);
        emit focusIn(mySianalValue);
    }
private:
    int mySianalValue;
signals:
    void focusOut(int);//失去焦点，给外部做判断
    void focusIn(int);//获得焦点
    void lineEditEmptySignal();//文本为空
public slots:

};

#endif // QMYEDIT_H
