#include "qwindowmanger.h"

QMyRegister::QMyRegister(QMyWidget *parent)
{
    //�����ϼ�����
    higherWidget = parent;
    pParent = parent;
    //��������
    QFont fon;
    fon.setFamily("����");
    fon.setBold(true);
    fon.setPointSize(15);
    setFont(fon);

    //���ñ���
    setbg();

    //���ð���
    setbtn();
    //���ñ�ǩ
    setedit();
    this->hide();
}

void QMyRegister::setbg()
{
    QLabel *lab;
    //���ô����Զ���䱳�������ǣ�
     //this->setAutoFillBackground(true);
    //���ô��ڴ�С
    this->setFixedSize(576,652);
    //���ô���λ��
    this->setGeometry(pParent->x()+(pParent->width()-this->width())/2,205,576,652);
    //���ô��ڱ���
    this->setWindowTitle(QString::fromLocal8Bit("����ս��"));
    //���Ʊ���ͼ
    lab = new QLabel(this);
    lab->setGeometry(this->rect());
    lab->setStyleSheet("QLabel{border-image:url(\"./Image/Register/Register_Interface.png\")}");
}

void QMyRegister::setbtn()
{
    QMyButton *btn;

    btn = new QMyButton("ȷ��",this);
    btn->setGeometry(QRect(160,548,140,70));
    connect( btn, SIGNAL(clicked()),this,SLOT(nextFromslots()) );
    QPixmap *p;
    p= new QPixmap("./Image/Tooltip/Tooltip_LeftBtn.png");
    btn->setPix(*p);

    btn = new QMyButton("����",this);
    btn->setGeometry(QRect(287,550,130,70));
    connect( btn, SIGNAL(clicked()),this,SLOT(lastFromslots()) );
    p = new QPixmap("./Image/Tooltip/Tooltip_RightBtn.png");
    btn->setPix(*p);

    //��������
    QFont fon;
    fon.setFamily("����");
    fon.setBold(true);
    fon.setPointSize(15);
    setFont(fon);
}
/*
enum mode
{
    �������û���
    �û���ע��
    ����������
    ��ȷ������
    �𰸲���Ϊ��
};*/

void QMyRegister::setedit()
{
    //ֻ������
    QRegExp regx("[0-9]+$");
    QValidator *validator;

    //�༭��
    name = new QMyEdit(this);
    name->setGeometry(208,187,290,43);
    name->setMaxLength(12);
    name->setPlaceholderText(QString("�������û���"));

    pwd = new QMyEdit(this);
    pwd->setMaxLength(8);
    pwd->setGeometry(208,253,290,43);
    pwd->setEchoMode(QLineEdit::Password);
    pwd->setPlaceholderText(QString("������8λ��������"));
    validator = new QRegExpValidator(regx, pwd );
    pwd->setValidator( validator );
    pwd->setContextMenuPolicy(Qt::NoContextMenu);//�Ҽ��˵�������
    connect(pwd,SIGNAL(focusIn(int)),this,SLOT(nameslots()));
    connect(pwd,SIGNAL(textChanged(QString)),this,SLOT(pwdTureOpenslots()));

    pwdTure = new QMyEdit(this);
    pwdTure->setMaxLength(8);
    pwdTure->setGeometry(208,330,290,43);
    pwdTure->setEchoMode(QLineEdit::Password);
    pwdTure->setPlaceholderText(QString("��ȷ������"));
    validator = new QRegExpValidator(regx, pwdTure );
    pwdTure->setValidator( validator );
    pwdTure->setDisabled(true);//��ֹ����
    pwdTure->setContextMenuPolicy(Qt::NoContextMenu);//�Ҽ��˵�������


    //���ñ༭
        this->Question=new QComboBox(this);
        this->Question->setGeometry(208,397,290,43);
        this->Question->addItem("���ĵ绰�����ǣ�",0);
        this->Question->addItem("��ĸ�׵ĵ绰�����ǣ�",1);
        this->Question->addItem("�����׵ĵ绰�����ǣ�",2);
        this->Question->setItemText(0,QString::fromLocal8Bit("���ĵ绰�����ǣ�"));
        this->Question->setItemText(1,QString::fromLocal8Bit("��ĸ�׵ĵ绰�����ǣ�"));
        this->Question->setItemText(2,QString::fromLocal8Bit("�����׵ĵ绰�����ǣ�"));
        this->Question->setStyleSheet("color:white;background:transparent;border-width:0;border-style:outset");
        this->Question->setFont(QFont("KaiTi_GB2312",15, QFont::Bold));
    Answer = new QMyEdit(this);
    Answer->setMaxLength(12);
    Answer->setGeometry(208,465,290,43);
    Answer->setPlaceholderText(QString("���������Ĵ�"));
    name->setFocus();

    connect(name,SIGNAL(returnPressed()),this,SLOT(namefinishslot()));
    connect(pwd,SIGNAL(returnPressed()),this,SLOT(pwdfinishslot()));
    connect(pwdTure,SIGNAL(returnPressed()),this,SLOT(pwdTurefinishslot()));
    connect(Answer,SIGNAL(returnPressed()),this,SLOT(Answerfinishslot()));
}

void QMyRegister::nextFromslots()
{
    QWidget *widget;
    if(name->text().isEmpty())
    {
        widget = new QMyTip(this,"�û�������Ϊ��Ŷ!");
        name->setFocus();
        return;
    }
    if(pwdTure->text().isEmpty())
    {
        if(pwd->text().isEmpty())
        {
            widget = new QMyTip(this,"���벻��Ϊ��Ŷ!");
            pwd->setFocus();
            return;
        }
        widget = new QMyTip(this,"��ȷ������Ŷ!");
        pwdTure->setFocus();
        return;
    }
    if(pwdTure->text() != pwd->text())
    {
        widget = new QMyTip(this,"��������ͬ����Ŷ!");
        pwdTure->clear();
        pwd->clear();
        pwd->setFocus();
        return;
    }
    if(Answer->text().isEmpty())
    {
        widget = new QMyTip(this,"�𰸲���Ϊ��Ŷ!");
        Answer->setFocus();
        return;
    }

    QSingleTon *single = QSingleTon::GetInstance();
    single->info.saveUserinfo(name->text(),pwd->text(),Question->currentText(),Answer->text());
    QString str("ע��ɹ��û�:");
    str = str + name->text();
    widget = new QMyTip(higherWidget,str);

    this->hide();
}

void QMyRegister::nameslots()
{
    QWidget *widget;
    if(name->text().isEmpty())
    {
        widget = new QMyTip(this,"�û�������Ϊ��Ŷ!");
        //����λ��
        name->setFocus();
        return;
    }
    QSingleTon *single = QSingleTon::GetInstance();
    if(single->info.getQuestion(name->text()))
    {
        widget = new QMyTip(this,"�û����Ѿ�ע��Ŷ!");
        //����  �û������
        name->clear();
        name->setFocus();
        return;
    }
}

void QMyRegister::pwdTureOpenslots()
{
    if(pwd->text().isEmpty())
    {
        pwdTure->setDisabled(true);//��ֹ����
    }
    else
    {
        pwdTure->setDisabled(false);//��������
    }

}

void QMyRegister::namefinishslot()
{
    pwd->setFocus();
}

void QMyRegister::pwdfinishslot()
{
    if(!pwd->text().isEmpty())
    {
        pwdTure->setFocus();
    }
    else
    {
        QMyTip *widget;
        widget = new QMyTip(this,"���벻��Ϊ��Ŷ!");
    }
}

void QMyRegister::pwdTurefinishslot()
{
    Answer->setFocus();
}
void QMyRegister::Answerfinishslot()
{
    nextFromslots();
}


