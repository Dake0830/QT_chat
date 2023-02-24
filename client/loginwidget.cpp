#include "loginwidget.h"
#include "ui_loginwidget.h"

#include <QMessageBox>
#include "clienthandler.h"

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    //注册
    QObject::connect(ui->btnRegister,&QPushButton::clicked,[=](){
        QString username=ui->leUsername->text();
        QString password=ui->lePassword->text();

        if(username.isEmpty()||password.isEmpty()){
            QMessageBox::warning(this,"注册信息","账号或密码不能为空！");
            return;
        }

        //调用客户端注册的策略
        ClientHandlerRegister::regist(username,password);
    });


    //登录
    QObject::connect(ui->btnLogin,&QPushButton::clicked,[=](){
        QString username=ui->leUsername->text();
        QString password=ui->lePassword->text();

        if(username.isEmpty()||password.isEmpty()){
            QMessageBox::warning(this,"登录信息","账号或密码不能为空！");
            return;
        }

        //调用客户端登录的策略
        ClientHandlerLogin::login(username,password);
    });
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::clearLine()
{
    ui->leUsername->clear();
    ui->lePassword->clear();
}

