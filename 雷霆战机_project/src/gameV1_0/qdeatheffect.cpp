#include "qdeatheffect.h"

QDeathEffect::QDeathEffect(QGraphicsScene *parent) :
    QItem(parent)
{
    QResources *source = QResources::GetInstance();
    boundPix = &source->gamePix["Boom3.png"];

    connect(&time,SIGNAL(timeout()),this,SLOT(deleteLater()));
    time.start(200);
}

void QDeathEffect::deleteSelf()
{
    time.stop();
    delete this;
}

void QDeathEffect::setTime(int timeLong)
{
    time.stop();
    time.start(timeLong);
}
