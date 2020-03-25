#include "qabout.h"

QAbout::QAbout(QMyWidget *parent)
{
    //�����ϼ�����
    higherWidget = parent;

    //��������
    QFont fon;
    fon.setFamily("����");
    fon.setBold(true);
    fon.setPointSize(15);
    setFont(fon);

    //ȥ��������
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    //����ģ̬����
    setWindowModality(Qt::WindowModal);

    //���ñ���ͼ
    QLabel *lab;
    resize(500,500);
    this->setGeometry(higherWidget->x()+(higherWidget->width()-this->width())/2,300,500,500);
    //���Ʊ���ͼ
    lab = new QLabel(this);
    lab->setGeometry(this->rect());
    lab->setScaledContents(true);
    lab->setStyleSheet("QLabel{border-image:url(\"./Image/About/AboutAuthor.png\")}");

    //���ð���
    QMyButton *btn;
    QPixmap *p;
    btn = new QMyButton("�˳�",this);
    btn->setGeometry(QRect(137,425,225,50));
    connect( btn, SIGNAL(clicked()),this,SLOT(yesOrno()) );
    p = new QPixmap("./Image/About/AffirmBtn.png");
    btn->setPix(*p);


    lab = new QLabel(this);
    lab->setStyleSheet("QLabel{border-image:url(\"./Image/About/Plant_Left.png\")}");
    anim = new QPropertyAnimation(lab,"geometry");
    anim->setDuration(5000);
    anim->setLoopCount(-1);
    anim->setStartValue(QRect(-200,120,200,200));
    anim->setEndValue(QRect(500,120,150,150));
    anim->start();

    //��������
    lab = new QLabel(this);
    lab->setGeometry(QRect(90,300,400,100));
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::green);
    lab->setPalette(pa);
    lab->setText("���ߣ�WF1905 ���ǿ�");
}
