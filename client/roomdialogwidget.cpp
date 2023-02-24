#include "roomdialogwidget.h"
#include "ui_roomdialogwidget.h"

RoomDialogWidget::RoomDialogWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoomDialogWidget)
{
    ui->setupUi(this);

    QObject::connect(ui->leRoomName,&QLineEdit::returnPressed,[=](){
        QString text=ui->leRoomName->text();
        if(text.isEmpty()){

        }
    });

}

RoomDialogWidget::~RoomDialogWidget()
{
    delete ui;
}
