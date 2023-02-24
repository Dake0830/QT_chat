#include "roomwidget.h"
#include "ui_roomwidget.h"

#include "clienthandler.h"
#include "loginwidget.h"
#include "roomcreatwidget.h"
#include "chatroomwidget.h"
#include <QDebug>
RoomWidget::RoomWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoomWidget)
{
    ui->setupUi(this);

    //创建聊天室
    QObject::connect(ui->btnCreate,&QPushButton::clicked,[=](){
            SingleTon<RoomCreatWidget>::getReference().setUsername(this->username);
            SingleTon<RoomCreatWidget>::getReference().setWindowTitle(username);
            SingleTon<RoomCreatWidget>::getReference().show();
    });

    //退出
    QObject::connect(ui->btnExit,&QPushButton::clicked,[=](){

        //调用退出登录策略
       ClientHandlerExit::exit(username);

       SingleTon<RoomWidget>::getReference().close();
       SingleTon<LoginWidget>::getReference().clearLine();
       SingleTon<LoginWidget>::getReference().show();
    });

    //刷新
    QObject::connect(ui->btnRefresh,&QPushButton::clicked,[=](){
      ClientHandlerRefresh::refresh();
    });

    //加入聊天室
    //双击鼠标触发

    QObject::connect(ui->lwRoom,&QListWidget::itemDoubleClicked,[=](){
         SingleTon<RoomWidget>::getReference().hide();
         int currenRow=ui->lwRoom->currentRow();//获取当前行号
         QString roomname=ui->lwRoom->item(currenRow)->text();
         QString username=SingleTon<RoomWidget>::getReference().getUsername();
        // qDebug()<<roomname;
         SingleTon<ChatroomWidget>::getReference().setRoomname(roomname);//设置聊天室名
         SingleTon<ChatroomWidget>::getReference().setUsername(username);

         //调用加入策略
        ClientHandlerJoin::joinchat(username,roomname);

    });


}

RoomWidget::~RoomWidget()
{
    delete ui;
}

void RoomWidget::appendroom(const QString &roomname)
{
    //添加房间名
    ui->lwRoom->addItem(roomname);
}

void RoomWidget::clearrooms()
{
    ui->lwRoom->clear();
}
