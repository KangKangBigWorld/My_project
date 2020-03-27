#include "qsetfrom.h"

#include "qsingleton.h"
QSetFrom::QSetFrom(QMyWidget *parent)
{
    //�����ϼ�����
    higherWidget = parent;

    //ȥ��������
    setWindowFlags(Qt::FramelessWindowHint);

    //���ñ���ͼ
    resize(400,500);
    //���Ʊ���ͼ
    lab = new QLabel(this);
    this->setGeometry(higherWidget->x()+(higherWidget->width()-this->width())/2,300,400,500);
    lab->setGeometry(this->rect());
    lab->setStyleSheet("QLabel{border-image:url(\"./Image/Set/SetInterface.png\")}");


    //���ð���
    QMyButton *btn;
    QPixmap *p;
    btn = new QMyButton("�˳�",this);
    btn->setGeometry(QRect(110,435,180,40));
    connect( btn, SIGNAL(clicked()),this,SLOT(lastFromslots()) );
    p = new QPixmap("./Image/About/AffirmBtn.png");
    btn->setPix(*p);

    //��������
    QFont fon;
    fon.setFamily("����");
    fon.setBold(true);
    fon.setPointSize(13);
    btn->setFont(fon);

    //���û�����
    setSlider();
    //������������
    hard = new QComboBox(this);
    hard->setGeometry(220,340,100,30);
    this->hard->addItem("��",0);
    this->hard->addItem("һ��",1);
    this->hard->addItem("����",2);
    this->hard->setItemText(0,QString::fromLocal8Bit("��"));
    this->hard->setItemText(1,QString::fromLocal8Bit("һ��"));
    this->hard->setItemText(2,QString::fromLocal8Bit("����"));
    hard->setStyleSheet("color:white;background:transparent;border-width:0;border-style:outset");
    connect(hard,SIGNAL(activated(int)),this,SLOT(setHard(int)));

    guide = new QComboBox(this);
    guide->setGeometry(220,386,100,30);
    this->guide->addItem("��",0);
    this->guide->addItem("�ر�",1);
    this->guide->setItemText(0,QString::fromLocal8Bit("��"));
    this->guide->setItemText(1,QString::fromLocal8Bit("�ر�"));
    guide->setStyleSheet("color:white;background:transparent;border-width:0;border-style:outset");
    connect(guide,SIGNAL(currentIndexChanged(int)),this,SLOT(setGuide(int)));

    //��������
    QFont fon2;
    fon2.setFamily("����");
    fon2.setBold(true);
    fon2.setPointSize(13);
    hard->setFont(fon2);
    guide->setFont(fon2);
}

QSetFrom::QSetFrom(QWidget *parent,int i)
{
    //�����ϼ�����
    higherWidget = parent;

    //setParent(parent);
    //���Ʊ���ͼ
    QResources *source = QResources::GetInstance();

    resize(parent->size());
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    //����͸��
    setAttribute(Qt::WA_TranslucentBackground, true);

    QLabel *lab;
    lab = new QLabel(this);
    lab->resize(parent->size());
    lab->setScaledContents(true);
    lab->setPixmap(source->gamePix["GameSetUI.png"]);

    QMyButton *btn;
    btn = new QMyButton(this);
    btn->setPix(source->gamePix["TopCloseButton.png"]);
    btn->setGeometry(320,0,80,50);
    connect(btn,SIGNAL(clicked()),this,SLOT(lastFromslots()));

    //���û�����
    setSlider();

    //����λ��
    volumeslider->setGeometry(150,35,100,20);
    lineEdit->setGeometry(270,35,30,20);
    soundslider->setGeometry(150,75,100,20);
    soundEdit->setGeometry(270,75,30,20);

    //������������
    hard = new QComboBox(this);
    hard->setGeometry(160,100,100,28);
    this->hard->addItem("���ĵ绰�����ǣ�",0);
    this->hard->addItem("��ĸ�׵ĵ绰�����ǣ�",1);
    this->hard->addItem("�����׵ĵ绰�����ǣ�",2);
    this->hard->setItemText(0,QString::fromLocal8Bit("��"));
    this->hard->setItemText(1,QString::fromLocal8Bit("һ��"));
    this->hard->setItemText(2,QString::fromLocal8Bit("����"));
    hard->setStyleSheet("color:white;background:transparent;border-width:0;border-style:outset");
    connect(hard,SIGNAL(activated(int)),this,SLOT(setHard(int)));

    //��������
    QFont fon2;
    fon2.setFamily("����");
    fon2.setBold(true);
    fon2.setPointSize(13);
    hard->setFont(fon2);
}

void QSetFrom::setEditVolume(int value)
{
    //��������ʾ
    volumeslider->setValue(value);
    //��ǩ��ʾ
    QString str = QString("%1").arg(value);
    lineEdit->setText(str);

    //д�����ݿ�
    QSingleTon *single = QSingleTon::GetInstance();
    single->info.setVolum(BACKGROUND,value);//��������
    single->musicBox.setVolume(value);
}

void QSetFrom::setEditSound(int value)
{
    //��������ʾ
    soundslider->setValue(value);
    //��ǩ��ʾ
    QString str = QString("%1").arg(value);
    soundEdit->setText(str);

    //д�����ݿ�
    QSingleTon *single = QSingleTon::GetInstance();
    single->info.setVolum(SOUNDEFFECT,value);//��������
    single->musicBox.setSound(value);
}

void QSetFrom::setSlider()
{
    //����������
    volumeslider = new QSlider(Qt::Horizontal,this);
    volumeslider->setMinimum(0);     // ���û���������Сֵ
    volumeslider->setMaximum(100);   // ���û����������ֵ

    soundslider = new QSlider(Qt::Horizontal,this);
    soundslider->setMinimum(0);     // ���û���������Сֵ
    soundslider->setMaximum(100);   // ���û����������ֵ

    //�����༭��
    lineEdit = new QLineEdit(this);
    soundEdit = new QLineEdit(this);

    //����λ��
    volumeslider->setGeometry(220,255,100,20);
    lineEdit->setGeometry(340,255,30,20);
    soundslider->setGeometry(220,300,100,20);
    soundEdit->setGeometry(340,300,30,20);

    lineEdit->setDisabled(true);//��ֹ����
    soundEdit->setDisabled(true);//��ֹ����

    //�����ź����
    connect(volumeslider, SIGNAL(valueChanged(int)), this, SLOT(setEditVolume(int)));
    connect(soundslider, SIGNAL(valueChanged(int)), this, SLOT(setEditSound(int)));

    //��ȡ���ݿ� �� ������
    QSingleTon *single = QSingleTon::GetInstance();
    volumeslider->setValue(single->info.volum(BACKGROUND));//�������ֻ�������ʼֵ
    soundslider->setValue(single->info.volum(SOUNDEFFECT));//��Ч��������ʼֵ
}

void QSetFrom::setHard(int hard)
{
    QSingleTon *single = QSingleTon::GetInstance();
    single->hard = (hard+1) * 2;
}

void QSetFrom::setGuide(int guide)
{
    QSingleTon *single = QSingleTon::GetInstance();
    single->guide = !guide;
}




