#include "chatroomwidget.h"
#include "ui_chatroomwidget.h"
#include "clienthandler.h"

#include <QDebug>
ChatroomWidget::ChatroomWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatroomWidget)
{
    ui->setupUi(this);
    //this->onlineuser=new QList<QString>;
    //刷新在线成员
    QObject::connect(ui->btnChrefersh,&QPushButton::clicked,[=](){
        //调用刷新在线成员策略
        ClientHandlerChrefresh::chrefresh(this->roomname);
    });

    //聊天
    QObject::connect(ui->lineEdit,&QLineEdit::returnPressed,[=](){
        QString text=ui->lineEdit->text();

        if(text.isEmpty() || username.isEmpty() || roomname.isEmpty()) return;
        //调用聊天策略
        ClientHandlerChat::chat(username,roomname,text);
    });

    //离开
    QObject::connect(ui->btnGoaway,&QPushButton::clicked,[=](){
        if(username.isEmpty() || roomname.isEmpty())return;

       //调用离开策略
        SingleTon<GiftWidget>::getReference().close();
        ClientHandlerGoaway::goaway(username,roomname);

    });

    //打开摄像头
    QObject::connect(ui->cbxCamera,&QCheckBox::clicked,[=](){
        if(ui->cbxCamera->isChecked()){
            openCamera();
        }else{}
    });


    //送礼
    QObject::connect(ui->btnGift,&QPushButton::clicked,[=](){
         //调用送礼策略
        if(username.isEmpty())return ;
        //设置窗口名
       SingleTon<GiftWidget>::getReference().setWindowTitle(SingleTon<ChatroomWidget>::getReference().getUsername());
       ClientHandlerGift::gif(username);
    });
}

ChatroomWidget::~ChatroomWidget()
{
    delete ui;

}

/**
 * @brief ChatroomWidget::closeEvent
 * 红叉事件
 * @param event
 */
void ChatroomWidget::closeEvent(QCloseEvent *event)
{
    SingleTon<GiftWidget>::getReference().close();
    ClientHandlerGoaway::goaway(username,roomname);
}

void ChatroomWidget::clearLvuser()
{
    ui->lvuser->clear();
}

bool ChatroomWidget::getTristate()
{
    return ui->checkBox->isChecked();
}



/**
 * @brief ChatroomWidget::appendBarrage
 * 弹幕添加
 * @param barrage
 *
 */
void ChatroomWidget::appendBarrage(const QString &barrage)
{
    //int Barrage=3;
    QLabel* label=new QLabel(this);//ui->mywidget
    QTimer* timer=new QTimer(this);
    label->setText(barrage);
    label->adjustSize();
    label->move(width(),Barrage);
    if(Barrage+label->height()+3>=this->height()){
        Barrage=3;
    }else{
        Barrage+=label->height();
    }

    QObject::connect(timer,&QTimer::timeout,[=](){
       QPoint pos=label->pos();
       pos+=QPoint(-10,0);
       label->move(pos);
       if(label->x()<=0){
           timer->stop();
           delete timer;
           delete label;
           return;
       }
    });

    label->show();
    timer->start(100);

}

/**
 * @brief ChatroomWidget::appendOnline
 * 添加在线列表
 * @param user
 */
void ChatroomWidget::appendOnline(const QString &user)
{
   ui->lvuser->addItem(user);
   //this->onlineuser->append(user);

}

/**
 * @brief ChatroomWidget::appendText
 * 添加消息队列
 * @param text
 */
void ChatroomWidget::appendText(const QString &text)
{
    ui->textBrowser->append(text);
    ui->lineEdit->clear();
}

void ChatroomWidget::refreshUser(QList<QString> &user)
{
    ui->lvuser->clear();
    //this->onlineuser->clear();
    //this->onlineuser=&user;
    ui->lvuser->addItems(user);
}

/**
 * @brief ChatroomWidget::openCamera
 * 打开摄像头
 */
void ChatroomWidget::openCamera()
{

   this->camera=new QCamera(this);
   //this->camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->setCaptureMode(QCamera::CaptureVideo);
   //this->pViewfinder=new QCameraViewfinder(ui->widget);
    //this->pImageCapture=new QCameraImageCapture(camera);
    //camera->setCaptureMode(QCamera::CaptureMode::CaptureViewfinder);
   // camera->setViewfinder(this->pViewfinder);
    camera->setViewfinder(ui->widget);
    this->camera->start();//启动
    //ImageCaptureTimer->start();

}

/**
 * @brief ChatroomWidget::captureImage
 * 截图
 *
 */
void  ChatroomWidget::captureImage()
{
   this->pImageCapture->capture("../common/m.jpg");

}


