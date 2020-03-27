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
    void focusOutEvent(QFocusEvent *e)//ʧȥ����
    {
        QLineEdit::focusOutEvent(e);
        emit focusOut(mySianalValue);
    }
    void focusInEvent(QFocusEvent *e)//�õ�����
    {
        QLineEdit::focusInEvent(e);
        emit focusIn(mySianalValue);
    }
private:
    int mySianalValue;
signals:
    void focusOut(int);//ʧȥ���㣬���ⲿ���ж�
    void focusIn(int);//��ý���
    void lineEditEmptySignal();//�ı�Ϊ��
public slots:

};

#endif // QMYEDIT_H
