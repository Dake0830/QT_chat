#ifndef CHATROOMWIDGET_H
#define CHATROOMWIDGET_H

#include <QWidget>
#include <QtWidgets/QWidget>
#include <QMediaObject>
#include <QCamera>
#include <QCameraViewfinder>
#include <QImage>
#include <Qt3DRender/QCamera>
#include <QCameraImageCapture>
#include <QPixmap>
#include <QTimer>
#include <QMediaBindableInterface>
#include <QCloseEvent>
#include "../common/singleton.h"
#include "roomwidget.h"
#include "giftwidget.h"
namespace Ui {
class ChatroomWidget;
}

class ChatroomWidget : public QWidget
{
    Q_OBJECT
    friend class SingleTon<ChatroomWidget>;
private:
    explicit ChatroomWidget(QWidget *parent = nullptr);

public:
    ~ChatroomWidget();

    inline void setRoomusername(const QString& roomusername){this->roomusername=roomusername;}
    inline void setRoomname(const QString& roomname){this->roomname=roomname;}
    inline void setUsername(const QString& username){this->username=username;}

    inline void setBarrage(const int Barrage){this->Barrage=Barrage;}

    //inline void setFlag(const int flag){this->flag=flag;}
    inline const QString getRoomusername(){return this->roomusername;}
    inline const QString getRoomname(){return this->roomname;}
    inline const QString getUsername(){return this->username;}

    virtual void closeEvent(QCloseEvent* event)override;

    void clearLvuser();



    bool getTristate();
    //inline const QList<QString>& getOnlineuser(){return *(this->onlineuser);}
    //弹幕
    void appendBarrage(const QString& barrage);

    //添加列表
    void appendOnline(const QString& user);

    //添加消息队列
    void appendText(const QString& text);

    //用户离开聊天室刷新
    void refreshUser(QList<QString>& user);

    //打开摄像头
    void openCamera();

    //截图
    void captureImage();



private:
    Ui::ChatroomWidget *ui;
    QString roomusername;//房主名
    QString roomname;//房间名
    QString username;//客户名




    int Barrage;//弹幕移动Y轴

    QCamera* camera;//摄像头
    QCameraImageCapture* pImageCapture;//获取当前摄像头帧数
    QCameraViewfinder*  pViewfinder;//取景器

    QTimer* ImageCaptureTimer;
    QImage pixmap;




};

#endif // CHATROOMWIDGET_H
