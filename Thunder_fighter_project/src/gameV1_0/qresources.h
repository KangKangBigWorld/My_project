#ifndef QRESOURCES_H
#define QRESOURCES_H

#include <QMap>
#include <QString>
#include <QPixmap>
#include <QDebug>

class QResources
{
public:
    static QResources* GetInstance();
    static void Release();
    //ÓÎÏ·Í¼Æ¬×ÊÔ´QResources *source = QResources::GetInstance();source->gamePix["GameTips2.png"];
    QMap<QString,QPixmap> gamePix;
    QPixmap *bgPix;
    QPixmap *myPlanePix;
private:
    QResources();
    static QResources* m_pInstance;
};

#endif // QRESOURCES_H QResources *source = QResources::GetInstance();
