#include "qsetfrom.h"

#include "qsingleton.h"
QSetFrom::QSetFrom(QMyWidget *parent)
{
    //设置上级窗口
    higherWidget = parent;

    //去掉标题栏
    setWindowFlags(Qt::FramelessWindowHint);

    //设置背景图
    resize(400,500);
    //绘制背景图
    lab = new QLabel(this);
    this->setGeometry(higherWidget->x()+(higherWidget->width()-this->width())/2,300,400,500);
    lab->setGeometry(this->rect());
    lab->setStyleSheet("QLabel{border-image:url(\"./Image/Set/SetInterface.png\")}");


    //设置按键
    QMyButton *btn;
    QPixmap *p;
    btn = new QMyButton("退出",this);
    btn->setGeometry(QRect(110,435,180,40));
    connect( btn, SIGNAL(clicked()),this,SLOT(lastFromslots()) );
    p = new QPixmap("./Image/About/AffirmBtn.png");
    btn->setPix(*p);

    //设置字体
    QFont fon;
    fon.setFamily("仿宋");
    fon.setBold(true);
    fon.setPointSize(13);
    btn->setFont(fon);

    //设置滑动条
    setSlider();
    //配置下拉窗口
    hard = new QComboBox(this);
    hard->setGeometry(220,340,100,30);
    this->hard->addItem("简单",0);
    this->hard->addItem("一般",1);
    this->hard->addItem("困难",2);
    this->hard->setItemText(0,QString::fromLocal8Bit("简单"));
    this->hard->setItemText(1,QString::fromLocal8Bit("一般"));
    this->hard->setItemText(2,QString::fromLocal8Bit("困难"));
    hard->setStyleSheet("color:white;background:transparent;border-width:0;border-style:outset");
    connect(hard,SIGNAL(activated(int)),this,SLOT(setHard(int)));

    guide = new QComboBox(this);
    guide->setGeometry(220,386,100,30);
    this->guide->addItem("打开",0);
    this->guide->addItem("关闭",1);
    this->guide->setItemText(0,QString::fromLocal8Bit("打开"));
    this->guide->setItemText(1,QString::fromLocal8Bit("关闭"));
    guide->setStyleSheet("color:white;background:transparent;border-width:0;border-style:outset");
    connect(guide,SIGNAL(currentIndexChanged(int)),this,SLOT(setGuide(int)));

    //设置字体
    QFont fon2;
    fon2.setFamily("黑体");
    fon2.setBold(true);
    fon2.setPointSize(13);
    hard->setFont(fon2);
    guide->setFont(fon2);
}

QSetFrom::QSetFrom(QWidget *parent,int i)
{
    //设置上级窗口
    higherWidget = parent;

    //setParent(parent);
    //绘制背景图
    QResources *source = QResources::GetInstance();

    resize(parent->size());
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    //设置透明
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

    //设置滑动条
    setSlider();

    //配置位置
    volumeslider->setGeometry(150,35,100,20);
    lineEdit->setGeometry(270,35,30,20);
    soundslider->setGeometry(150,75,100,20);
    soundEdit->setGeometry(270,75,30,20);

    //配置下拉窗口
    hard = new QComboBox(this);
    hard->setGeometry(160,100,100,28);
    this->hard->addItem("您的电话号码是？",0);
    this->hard->addItem("您母亲的电话号码是？",1);
    this->hard->addItem("您父亲的电话号码是？",2);
    this->hard->setItemText(0,QString::fromLocal8Bit("简单"));
    this->hard->setItemText(1,QString::fromLocal8Bit("一般"));
    this->hard->setItemText(2,QString::fromLocal8Bit("困难"));
    hard->setStyleSheet("color:white;background:transparent;border-width:0;border-style:outset");
    connect(hard,SIGNAL(activated(int)),this,SLOT(setHard(int)));

    //设置字体
    QFont fon2;
    fon2.setFamily("黑体");
    fon2.setBold(true);
    fon2.setPointSize(13);
    hard->setFont(fon2);
}

void QSetFrom::setEditVolume(int value)
{
    //滑动条显示
    volumeslider->setValue(value);
    //标签显示
    QString str = QString("%1").arg(value);
    lineEdit->setText(str);

    //写入数据库
    QSingleTon *single = QSingleTon::GetInstance();
    single->info.setVolum(BACKGROUND,value);//背景音乐
    single->musicBox.setVolume(value);
}

void QSetFrom::setEditSound(int value)
{
    //滑动条显示
    soundslider->setValue(value);
    //标签显示
    QString str = QString("%1").arg(value);
    soundEdit->setText(str);

    //写入数据库
    QSingleTon *single = QSingleTon::GetInstance();
    single->info.setVolum(SOUNDEFFECT,value);//背景音乐
    single->musicBox.setSound(value);
}

void QSetFrom::setSlider()
{
    //创建滑动条
    volumeslider = new QSlider(Qt::Horizontal,this);
    volumeslider->setMinimum(0);     // 设置滑动条的最小值
    volumeslider->setMaximum(100);   // 设置滑动条的最大值

    soundslider = new QSlider(Qt::Horizontal,this);
    soundslider->setMinimum(0);     // 设置滑动条的最小值
    soundslider->setMaximum(100);   // 设置滑动条的最大值

    //创建编辑框
    lineEdit = new QLineEdit(this);
    soundEdit = new QLineEdit(this);

    //配置位置
    volumeslider->setGeometry(220,255,100,20);
    lineEdit->setGeometry(340,255,30,20);
    soundslider->setGeometry(220,300,100,20);
    soundEdit->setGeometry(340,300,30,20);

    lineEdit->setDisabled(true);//禁止输入
    soundEdit->setDisabled(true);//禁止输入

    //链接信号与槽
    connect(volumeslider, SIGNAL(valueChanged(int)), this, SLOT(setEditVolume(int)));
    connect(soundslider, SIGNAL(valueChanged(int)), this, SLOT(setEditSound(int)));

    //获取数据库 和 音乐类
    QSingleTon *single = QSingleTon::GetInstance();
    volumeslider->setValue(single->info.volum(BACKGROUND));//背景音乐滑动条初始值
    soundslider->setValue(single->info.volum(SOUNDEFFECT));//音效滑动条初始值
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




