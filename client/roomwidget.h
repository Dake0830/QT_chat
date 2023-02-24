#ifndef ROOMWIDGET_H
#define ROOMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "../common/singleton.h"
namespace Ui {
class RoomWidget;
}

//房间窗口
class RoomWidget : public QWidget
{
    Q_OBJECT
    friend class SingleTon<RoomWidget>;
private:
    explicit RoomWidget(QWidget *parent = nullptr);

public:
    ~RoomWidget();
    inline void setUsername(const QString& username){this->username=username;}
    inline const QString getUsername(){return this->username;}

    void appendroom(const QString& roomname);
    void clearrooms();
private:
    Ui::RoomWidget *ui;
    QString username;



};

#endif // ROOMWIDGET_H
