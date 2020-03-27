#include "qrankinglist.h"
#include <QHeaderView>
#include <string>
QRankingList::QRankingList(QMyWidget *parent)
{
    //�����ϼ�����
    higherWidget = parent;

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
    resize(400,600);
    this->setGeometry(higherWidget->x()+(higherWidget->width()-this->width())/2,300,400,600);
    //���Ʊ���ͼ
    lab = new QLabel(this);
    lab->setGeometry(this->rect());
    lab->setScaledContents(true);
    lab->setStyleSheet("QLabel{border-image:url(\"./Image/Rank/RankList.png\")}");

    //���ð���
    QMyButton *btn;
    btn = new QMyButton("",this);
    btn->setGeometry(QRect(40,480,60,60));
    connect( btn, SIGNAL(clicked()),this,SLOT(pageLastslots()) );
    QPixmap *p;
    p= new QPixmap("./Image/Rank/Last.png");
    btn->setPix(*p);

    btn = new QMyButton("",this);
    btn->setGeometry(QRect(300,480,60,60));
    connect( btn, SIGNAL(clicked()),this,SLOT(pageNextslots()) );
    p = new QPixmap("./Image/Rank/Next.png");
    btn->setPix(*p);

    btn = new QMyButton("�˳�",this);
    btn->setGeometry(QRect(110,550,180,40));
    connect( btn, SIGNAL(clicked()),this,SLOT(yesOrno()) );
    p = new QPixmap("./Image/About/AffirmBtn.png");
    btn->setPix(*p);

    //���ó�ʼҳ��
    pageCur = 1;

    //��ʼ�����ݱ�
    table.setRowCount(7);
    table.setColumnCount(3);

    //�����п�
    table.setColumnWidth(0,80);
    table.setColumnWidth(1,150);
    table.setColumnWidth(2,80);

    table.setParent(this);
    table.setGeometry(50,260,340,220);
    table.verticalHeader()->setVisible(false); // ����ˮƽheader
    table.horizontalHeader()->setVisible(false); // ����ˮƽheader
    table.setEnabled(false);
    table.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table.setStyleSheet("QTableWidget{border-radius:1px;background:transparent;color:rgb(255,100,255);font-size:15px;}");

    paintPage();
}

void QRankingList::pageLastslots()
{
    pageCur--;
    if(pageCur >  0)
    {
        paintPage();
        return;
    }
    pageCur = 1;
    QMyTip *tip;
    tip = new QMyTip(this,"�Ѿ��ǵ�һҳ��");
}

void QRankingList::pageNextslots()
{
    pageCur++;
    if(paintPage()) return;
    QMyTip *tip;
    tip = new QMyTip(this,"�Ѿ������һҳ��");
    pageCur--;
}

bool QRankingList::paintPage()
{
    QSingleTon *single = QSingleTon::GetInstance();
    if (!single->info.rank(7,this->pageCur))
    {
        return false;
    }
    int i = 0;
    QTableWidgetItem *name;
    char ch[6];
    for (; i < single->info.row; i++)
    {
        name=new QTableWidgetItem();//����һ��Item
        sprintf(ch,"%d",((pageCur-1)*7+i+1));
        name->setText(ch);
        table.setItem(i,0,name);

        name=new QTableWidgetItem();//����һ��Item
        name->setText(single->info.qresult[2*i+2]);
        table.setItem(i,1,name);
        name=new QTableWidgetItem();//����һ��Item
        name->setText(single->info.qresult[2*i+3]);
        table.setItem(i,2,name);
    }
    sqlite3_free_table(single->info.qresult);
    return true;
}
