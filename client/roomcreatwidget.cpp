#include "roomcreatwidget.h"
#include "ui_roomcreatwidget.h"
#include "clienthandler.h"
#include <QMessageBox>
RoomCreatWidget::RoomCreatWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoomCreatWidget)
{
    ui->setupUi(this);
    //按Enter
    QObject::connect(ui->lineEdit,&QLineEdit::returnPressed,[=](){
        QString roomname=ui->lineEdit->text();
        if(roomname.isEmpty()||username.isEmpty()){
            QMessageBox::critical(this,"创建信息","房间名或房主名不能为空");
            return;
        }

           ClientHandlerCreatroom::creatroom(username,roomname); 

    });

    //按创建按钮
    QObject::connect(ui->btnCreate,&QPushButton::clicked,[=](){
        QString roomname=ui->lineEdit->text();
        if(roomname.isEmpty()||username.isEmpty()){
            QMessageBox::critical(this,"创建信息","房间名或房主名不能为空");
            return;
        }
           ClientHandlerCreatroom::creatroom(username,roomname);

    });

    //按取消按钮
    QObject::connect(ui->btnWaith,&QPushButton::clicked,[=](){
        SingleTon<RoomCreatWidget>::getReference().hide();
    });
}

RoomCreatWidget::~RoomCreatWidget()
{
    delete ui;
}
