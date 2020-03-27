#ifndef QHELPPAGE_H
#define QHELPPAGE_H

#include "qmywidget.h"

class QHelpPage : public QMyWidget
{
    Q_OBJECT
public:
    QHelpPage(QMyWidget *parent = 0);
protected:
private:
    QMyWidget *pParent;
public slots:
};

#endif // QHELPPAGE_H
