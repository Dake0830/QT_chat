#ifndef ROOMDALOGWIDGET_H
#define ROOMDALOGWIDGET_H

#include <QDialog>

namespace Ui {
class RoomDalogWidget;
}

class RoomDalogWidget : public QDialog
{
    Q_OBJECT

public:
    explicit RoomDalogWidget(QWidget *parent = nullptr);
    ~RoomDalogWidget();

private:
    Ui::RoomDalogWidget *ui;
};

#endif // ROOMDALOGWIDGET_H
