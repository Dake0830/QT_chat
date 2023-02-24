#include "roomdalogwidget.h"
#include "ui_roomdalogwidget.h"

RoomDalogWidget::RoomDalogWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoomDalogWidget)
{
    ui->setupUi(this);
}

RoomDalogWidget::~RoomDalogWidget()
{
    delete ui;
}
