#ifndef ROOMDIALOGWIDGET_H
#define ROOMDIALOGWIDGET_H

#include <QDialog>
#include "../common/singleton.h"
namespace Ui {
class RoomDialogWidget;
}

class RoomDialogWidget : public QDialog
{
    Q_OBJECT
    friend class SingleTon<RoomDialogWidget>;
private:
    explicit RoomDialogWidget(QWidget *parent = nullptr);

public:
    ~RoomDialogWidget();

    //inline void setRoomname(const QString& roomname){this->roomname=roomname;}
private:
    Ui::RoomDialogWidget *ui;

   // QString roomname;
};

#endif // ROOMDIALOGWIDGET_H
