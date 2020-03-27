#include "qwindowmanger.h"

QHelpPage::QHelpPage(QMyWidget *parent):QMyWidget(parent)
{
    //�����ϼ�����
    higherWidget = parent;
    pParent = parent;

    //��������
    QFont fon;
    fon.setFamily("����");
    fon.setBold(true);
    fon.setPointSize(20);
    setFont(fon);

    //ȥ��������
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    //����ģ̬����
    setWindowModality(Qt::WindowModal);

    //���ñ���ͼ
    QLabel *lab;
    resize(500,500);
    this->setGeometry(pParent->x()+(pParent->width()-this->width())/2,300,500,500);
    //���Ʊ���ͼ
    lab = new QLabel(this);
    lab->setGeometry(this->rect());
    lab->setStyleSheet("QLabel{border-image:url(\"./Image/About/Help.png\")}");

    //���ð���
    QMyButton *btn;
    QPixmap *p;
    btn = new QMyButton("�˳�",this);
    btn->setGeometry(QRect(137,425,225,50));
    connect( btn, SIGNAL(clicked()),this,SLOT(yesOrno()) );
    p = new QPixmap("./Image/About/AffirmBtn.png");
    btn->setPix(*p);
}


