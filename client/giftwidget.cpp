#include "giftwidget.h"
#include "ui_giftwidget.h"
#include "clienthandler.h"
#include <QMessageBox>
GiftWidget::GiftWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GiftWidget)
{
    ui->setupUi(this);

    //充值
    QObject::connect(ui->btnRecharge,&QPushButton::clicked,[=](){
        int monney=ui->lineEdit->text().toInt();
        if(monney<=0){
            QMessageBox::warning(SingleTon<GiftWidget>::getInstance()," 充值信息","充值金额有误！");

        }else{

            //调用充值金额策略
            QString username=SingleTon<ChatroomWidget>::getReference().getUsername();
            if(username.isEmpty()){
                qDebug()<<"没找到用户的名字";
            }
            ClientHandlerRecharge::recharge(monney,username);
        }
         if(!ui->lineEdit->text().isEmpty())ui->lineEdit->clear();//清空输入栏
    });

    //余额送出
    QObject::connect(ui->btnMonney,&QPushButton::clicked,[=](){
        //判断哪种礼物

        //this->setGiftway("monney");
        QString giftway="monney";
        int gift=0;
        QString roomusername=SingleTon<ChatroomWidget>::getReference().getRoomusername();
        QString roomname=SingleTon<ChatroomWidget>::getReference().getRoomname();
        QString username=SingleTon<ChatroomWidget>::getReference().getUsername();

        if(roomusername==username){
            QMessageBox::warning(SingleTon<GiftWidget>::getInstance(),"送礼信息","您是房主不要越界操作");
            return;
        }

        if(ui->rbGiftfish->isChecked()){
           gift=10;

        }else if(ui->rbGiftfly->isChecked()){
            gift=200;

        }else if(ui->rbGiftrocket->isChecked()){
           gift=999;

        }else if(gift==0){
            QMessageBox::warning(SingleTon<GiftWidget>::getInstance(),"送礼信息","请先选择要送出的礼物");
            return;
        }else{return;}
        if(this->getMonney()<gift){
            QMessageBox::warning(SingleTon<GiftWidget>::getInstance(),"送礼信息","余额不足");
            return;
        }
        //调用送礼策略
        ClientHandlerGiftMonney::gift_monney(giftway,username,roomname,roomusername,gift);


    });

    //积分送礼
    QObject::connect(ui->btnIntegral,&QPushButton::clicked,[=](){
        //判断哪种礼物
        //this->setGiftway("integral");
         QString giftway="integral";
        int gift=0;
        QString roomusername=SingleTon<ChatroomWidget>::getReference().getRoomusername();
        QString roomname=SingleTon<ChatroomWidget>::getReference().getRoomname();
        QString username=SingleTon<ChatroomWidget>::getReference().getUsername();
        if(roomusername==username){
            QMessageBox::warning(SingleTon<GiftWidget>::getInstance(),"送礼信息","您是房主不要越界操作");
            return;
        }
        if(ui->rbGiftfish->isChecked()){
           gift=100;

        }else if(ui->rbGiftfly->isChecked()){
            gift=1019;

        }else if(ui->rbGiftrocket->isChecked()){
           gift=16666;

        }else {
            QMessageBox::warning(SingleTon<GiftWidget>::getInstance(),"送礼信息","请先选择要送出的礼物");
            return;
        }
        if(this->getIntegral()<gift){
            QMessageBox::warning(SingleTon<GiftWidget>::getInstance(),"送礼信息","余额不足");
            return;
        }
        //调用送礼策略
        ClientHandlerGiftIntegral::gift_integral(giftway,username,roomname,roomusername,gift);
    });

    //退出送礼界面
    QObject::connect(ui->btnGoaway,&QPushButton::clicked,[=](){
        SingleTon<GiftWidget>::getReference().hide();
    });

}

GiftWidget::~GiftWidget()
{
    delete ui;
}

void GiftWidget::setMonney(const int &num)
{
    ui->lcdmonney->display(num);
}

void GiftWidget::setIntegral(const int &num)
{
    ui->lcdintegral->display(num);
}

int GiftWidget::getMonney() const
{
    return ui->lcdmonney->intValue();
}

int GiftWidget::getIntegral() const
{
    return ui->lcdintegral->intValue();
}

