#ifndef GIFTWIDGET_H
#define GIFTWIDGET_H

#include <QWidget>
#include "chatroomwidget.h"
#include "../common/singleton.h"
namespace Ui {
class GiftWidget;
}

class GiftWidget : public QWidget
{
    Q_OBJECT
    friend class SingleTon<GiftWidget>;
private:
    explicit GiftWidget(QWidget *parent = nullptr);

public:
    ~GiftWidget();

    //金额/积分接口
    void setMonney(const int& num);
    void setIntegral(const int& num);

    int getMonney()const;
    int getIntegral()const;




private:
    Ui::GiftWidget *ui;


};

#endif // GIFTWIDGET_H
