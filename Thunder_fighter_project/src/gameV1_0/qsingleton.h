#ifndef QSINGLETON_H
#define QSINGLETON_H

#include "qmusicbox.h"
#include "qdbuserinfo.h"
#include "qresources.h"

class QAftermath :public QObject
{
    Q_OBJECT
public:
    QAftermath(){}
    ~QAftermath();
};

extern QAftermath aftermath;
// 取内容 QSingleTon *single = QSingleTon::GetInstance();
class QSingleTon
{
public:
    static QSingleTon* GetInstance();
    static void Release();

    int getCount(){
        return m_nCount;
    }
    void setCount(int c){
        m_nCount = c;
    }
    QMusicBox musicBox;
    QDbUserInfo info;
    int hard;  // 0 简单  1 一般  2 困难
    bool guide;//1 打开  0 关闭

    QString name;//用户名
    int integral;
private:
    QSingleTon();
    static QSingleTon* m_pInstance;
    bool m_nCount;
};
#endif // QSINGLETON_H
