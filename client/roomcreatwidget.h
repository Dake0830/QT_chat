#ifndef ROOMCREATWIDGET_H
#define ROOMCREATWIDGET_H

#include <QWidget>
#include "../common/singleton.h"

namespace Ui {
class RoomCreatWidget;
}

class RoomCreatWidget : public QWidget
{
    Q_OBJECT
    friend class SingleTon<RoomCreatWidget>;
private:
    explicit RoomCreatWidget(QWidget *parent = nullptr);

public:
    ~RoomCreatWidget();
    inline void setUsername(const QString& username){this->username=username;}
    inline const QString  getUsername(){return this->username;}
private:
    Ui::RoomCreatWidget *ui;
    QString username;

};

#endif // ROOMCREATWIDGET_H
