#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include "../common/singleton.h"
#include <QCloseEvent>
namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT
    friend class SingleTon<LoginWidget>;
private:
    explicit LoginWidget(QWidget *parent = nullptr);

public:
    ~LoginWidget();

    void clearLine();

private:
    Ui::LoginWidget *ui;
};

#endif // LOGINWIDGET_H
