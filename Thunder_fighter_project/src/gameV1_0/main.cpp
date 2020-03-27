#include <QtGui/QApplication>
#include <QTextCodec>

#include "qstartui.h"
#include "qsingleton.h"
#include "qwindowmanger.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //获取系统编码GB2312
    QTextCodec *codec = QTextCodec::codecForName("GB2312");
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    QSingleTon *single;`
    single= QSingleTon::GetInstance();
    QResources *sources;
    sources= QResources::GetInstance();
    QWindowManger* pIntence=QWindowManger::getIntence();
    pIntence->pStart->show();


    return a.exec();
}

