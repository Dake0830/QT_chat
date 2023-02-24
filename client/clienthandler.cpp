#include "clienthandler.h"

#include <QJsonObject>
#include <QJsonDocument>

#include "../common/streamer.h"
#include "client.h"
#include "loginwidget.h"
#include "roomwidget.h"
#include "roomcreatwidget.h"
#include "chatroomwidget.h"
#include "giftwidget.h"
#include <QMessageBox>

/**
 * @brief ClientHandler::ClientHandler
 *      新建具体的用户策略套接字
 * @param client
 */
ClientHandler::ClientHandler(Client *client)
{
    handlers=QVector<IHandler*>(last,nullptr);

    handlers[regist]=new ClientHandlerRegister(client);
    handlers[login]=new ClientHandlerLogin(client);
    handlers[creatroom]=new ClientHandlerCreatroom(client);
    handlers[refresh]=new ClientHandlerRefresh(client);
    handlers[join]=new ClientHandlerJoin(client);
    handlers[chrefresh]=new ClientHandlerChrefresh(client);
    handlers[chat]=new ClientHandlerChat(client);
    handlers[recharge]=new ClientHandlerRecharge(client);
    handlers[gift]=new ClientHandlerGift(client);
    handlers[gift_monney]=new ClientHandlerGiftMonney(client);
    handlers[gift_integral]=new ClientHandlerGiftIntegral(client);
    handlers[goaway]=new ClientHandlerGoaway(client);
    handlers[exit]=new ClientHandlerExit(client);

}



/**
 * @brief ClientHandlerRegister::handle
 *      反馈服务器的注册处理信息
 * @param data
 *
 */
void ClientHandlerRegister::handle(const QByteArray &data)
{
    QJsonObject json=QJsonDocument::fromJson(data).object();
    QString result = json["result"].toString();

    if(result=="success"){
        //成功
        QMessageBox::information(SingleTon<LoginWidget>::getInstance(),"注册信息","注册成功");

    }else if(result=="failed"){
        //失败
        QMessageBox::critical(SingleTon<LoginWidget>::getInstance(),"注册信息","注册失败");
    }else if(result=="repeat"){
        //重复注册
        QMessageBox::warning(SingleTon<LoginWidget>::getInstance(),"注册信息","重复注册，请直接登录");
    }
}

/**
 * @brief ClientHandlerRegister::regist
 *      向服务器发送用户注册请求
 * @param username
 * @param password
 */
void ClientHandlerRegister::regist(const QString &username, const QString &password)
{
    QJsonObject json;
    json["username"]=username;
    json["password"]=password;

    auto data=QJsonDocument(json).toJson();//存放数据，转成json格式

    //数据打包，向服务器发送注册请求
    SingleTon<Client>::getReference().write(Streamer::pack(Handler::regist,data));
}




/**
 * @brief ClientHandlerLogin::handle
 * @param data
 * @brief 处理服务发来的登录操作结果
 *         成功隐藏注册、登录操作界面，
 *         显示房间界面
 */
void ClientHandlerLogin::handle(const QByteArray &data)
{
    //登录处理
    QJsonObject json=QJsonDocument::fromJson(data).object();

    QString result=json["result"].toString();
    QString info=json["info"].toString();

    if(result=="success"){
        //界面切换
        QString username=json["username"].toString();
        SingleTon<RoomWidget>::getReference().setUsername(username);

        SingleTon<LoginWidget>::getReference().hide();
        SingleTon<RoomWidget>::getReference().setWindowTitle(username);
        SingleTon<RoomWidget>::getReference().show();

    }else if(result=="failed"){
        QMessageBox::warning(SingleTon<LoginWidget>::getInstance(),"登录信息",info);
    }

}

/**
 * @brief ClientHandlerLogin::login
 *      具体的登录策略（向服务器发送用户登录请求）
 * @param username
 * @param password
 *
 */
void ClientHandlerLogin::login(const QString &username, const QString &password)
{
    QJsonObject json;
    json["username"]=username;
    json["password"]=password;

    auto data = QJsonDocument(json).toJson();

    SingleTon<Client>::getReference().write(Streamer::pack(Handler::login,data));
}

/**
 * @brief ClientHandlerCreatroom::handle
 * 创建房间
 * @param data
 *
 */
void ClientHandlerCreatroom::handle(const QByteArray &data)
{
    QJsonObject json=QJsonDocument::fromJson(data).object();
    QString result=json["result"].toString();
    QString roomname=json["roomname"].toString();
    if(result=="success"){
        //成功
        QMessageBox::information(SingleTon<RoomCreatWidget>::getInstance(),"创建结果","创建成功");
        SingleTon<RoomWidget>::getReference().appendroom(roomname);
        SingleTon<RoomCreatWidget>::getReference().hide();

    }else if(result=="failed"){
        //失败
        QMessageBox::critical(SingleTon<RoomCreatWidget>::getInstance(),"创建结果","创建失败");
    }else if(result=="repeat"){
        //房间名重复
        QMessageBox::warning(SingleTon<RoomCreatWidget>::getInstance(),"创建结果","房间名重复，请重新创建");
    }
}

void ClientHandlerCreatroom::creatroom(const QString &username, const QString &roomname)
{
    QJsonObject json;
    json["username"]=username;
    json["roomname"]=roomname;

    auto data=QJsonDocument(json).toJson();
    SingleTon<Client>::getReference().write(Streamer::pack(Handler::creatroom,data));
}




/**
 * @brief ClientHandlerRefresh::refresh
 * 向服务器发送刷新房间列表请求
 */
void ClientHandlerRefresh::refresh()
{
    QByteArray data;
    SingleTon<Client>::getReference().write(Streamer::pack(Handler::refresh,data));

}

/**
 * @brief ClientHandlerRefresh::handle
 * @param data
 * 反馈服务器刷新结果
 */
void ClientHandlerRefresh::handle(const QByteArray &data)
{
    QJsonObject json = QJsonDocument::fromJson(data).object();//解包

    QString room;
     SingleTon<RoomWidget>::getReference().clearrooms();//清空列表
     //转换成QString类
    for(auto i:json){
     room=i.toString();
     //逐个添加
     SingleTon<RoomWidget>::getReference().appendroom(room);

    }
}

/**
 * @brief ClientHandlerJoin::handle
 * 反馈服务器发来的加入房间处理结果
 * @param data
 *
 */
void ClientHandlerJoin::handle(const QByteArray &data)
{
    QJsonObject json=QJsonDocument::fromJson(data).object();

    QString result=json["result"].toString();
    QString info =json["info"].toString();
    QString roomusername=json["roomusername"].toString();
    QString username=json["username"].toString();

    if(result=="failed"){
        QMessageBox::warning(SingleTon<RoomWidget>::getInstance(),"加入聊天室结果",info);
    }
    QString welcome="欢迎"+username+"进入房间";
    SingleTon<ChatroomWidget>::getReference().setRoomusername(roomusername);
    SingleTon<RoomWidget>::getReference().hide();
    SingleTon<ChatroomWidget>::getReference().setWindowTitle(roomusername);
    SingleTon<ChatroomWidget>::getReference().show();
    SingleTon<ChatroomWidget>::getReference().setBarrage(3);


    SingleTon<ChatroomWidget>::getReference().appendBarrage(welcome);
    SingleTon<ChatroomWidget>::getReference().appendOnline(username);

}

/**
 * @brief ClientHandlerJoin::joinchat
 * 加入房间策略
 * @param username
 * @param roomname
 */
void ClientHandlerJoin::joinchat(const QString &username, const QString &roomname)
{
    QJsonObject json;
    json["username"]=username;
    json["roomname"]=roomname;

    auto data=QJsonDocument(json).toJson();
    SingleTon<Client>::getReference().write(Streamer::pack(Handler::join,data));
}




/**
 * @brief ClientHandlerChrefresh::chrefresh
 * 刷新在线策略
 * @param roomname
 */
void ClientHandlerChrefresh::chrefresh(const QString& roomname)
{
    QJsonObject json;
    json["roomname"]=roomname;
    auto data=QJsonDocument(json).toJson();
    SingleTon<Client>::getReference().write(Streamer::pack(Handler::chrefresh,data));
}

/**
 * @brief ClientHandlerChrefresh::handle
 * 反馈刷新在线策略
 * @param data
 */
void ClientHandlerChrefresh::handle(const QByteArray &data)
{
    QJsonObject json=QJsonDocument::fromJson(data).object();

    QList<QString> onlineuser;

    for(auto o:json){
        onlineuser.append(o.toString());
    }
    SingleTon<ChatroomWidget>::getReference().refreshUser(onlineuser);
}

/**
 * @brief ClientHandlerChat::chat
 * 聊天策略
 * @param username
 * @param roomname
 */
void ClientHandlerChat::handle(const QByteArray &data)
{
    QJsonObject json=QJsonDocument::fromJson(data).object();

    QString username=json["username"].toString();
    QString message=json["message"].toString();
    QString gift=json["gift"].toString();


    QString text=username + ":\n" +message+"\n";//消息
   if (!gift.isEmpty())
   {
           //送礼
           text="感谢"+username+"送出的"+gift;
           SingleTon<ChatroomWidget>::getReference().appendBarrage(text);
           SingleTon<ChatroomWidget>::getReference().appendText(text);
           return;
   }

   if(SingleTon<ChatroomWidget>::getReference().getTristate()==true){//弹幕
       SingleTon<ChatroomWidget>::getReference().appendBarrage(message);
       SingleTon<ChatroomWidget>::getReference().appendText(text);
   }else{
       //消息
    SingleTon<ChatroomWidget>::getReference().appendText(text);
   }
}

void ClientHandlerChat::chat(const QString &username, const QString &roomname,const QString& message)
{
    QJsonObject json;
    json["username"]=username;
    json["message"]=message;
    json["roomname"]=roomname;

    auto data=QJsonDocument(json).toJson();
    SingleTon<Client>::getReference().write(Streamer::pack(Handler::chat,data));
}


/**
 * @brief ClientHandlerRecharge::recharge
 * 充值策略
 * @param monney
 * @param username
 */
void ClientHandlerRecharge::handle(const QByteArray &data)
{
    QJsonObject json=QJsonDocument::fromJson(data).object();
    QString result=json["result"].toString();
    if(result=="failed"){
        QMessageBox::warning(SingleTon<GiftWidget>::getInstance(),"充值信息","充值失败！");

    }else{
        int monney=json["monney"].toInt();
        SingleTon<GiftWidget>::getReference().setMonney(monney);
        QMessageBox::information(SingleTon<GiftWidget>::getInstance(),"充值信息","充值成功");
    }
}

void ClientHandlerRecharge::recharge(const int &monney, const QString &username)
{
    QJsonObject json;
    json["monney"]=monney;
    json["username"]=username;

    auto data=QJsonDocument(json).toJson();
    SingleTon<Client>::getReference().write(Streamer::pack(Handler::recharge,data));
}

/**
 * @brief ClientHandlerGift::handle
 * 送礼刷新数据
 * @param data
 */

void ClientHandlerGift::handle(const QByteArray &data)
{
     QJsonObject json=QJsonDocument::fromJson(data).object();
     int monney=json["monney"].toInt();
     int integral=json["integral"].toInt();
     //
     if(monney<0 || integral<0){
         //
         monney=0;
         integral=0;

     }

     SingleTon<GiftWidget>::getReference().setMonney(monney);
     SingleTon<GiftWidget>::getReference().setIntegral(integral);

     SingleTon<GiftWidget>::getReference().show();

}

void ClientHandlerGift::gif(const QString& username)
{
    QJsonObject json;
    json["username"]=username;
    auto data=QJsonDocument(json).toJson();
    SingleTon<Client>::getReference().write(Streamer::pack(Handler::gift,data));
}

/**
 * @brief ClientHandlerGiftMonney::handle
 * 余额送礼
 * @param data
 */
void ClientHandlerGiftMonney::handle(const QByteArray &data)
{
  QJsonObject json=QJsonDocument::fromJson(data).object();
  QString result=json["result"].toString();
  QString info=json["info"].toString();
  QString gift=json["gift"].toString();
  int monney=json["result_monney"].toInt();
  int integral=json["integral_result"].toInt();


  if(result=="failed")
  {
      if(info.isEmpty())
      {
          QMessageBox::warning(SingleTon<GiftWidget>::getInstance(),"送礼信息","送礼失败");
          return;
      }else
      {
          QMessageBox::warning(SingleTon<GiftWidget>::getInstance(),"送礼信息",info);
          return;
      }

  }


  if(gift=="鱼蛋")
  {

      if(monney>=0){
          SingleTon<GiftWidget>::getReference().setMonney(monney);

          SingleTon<GiftWidget>::getReference().setIntegral(integral);
          return;
      }
  }
  else if(gift=="飞机")
  {

      if(monney>=0){
          SingleTon<GiftWidget>::getReference().setMonney(monney);

          SingleTon<GiftWidget>::getReference().setIntegral(integral);
          return;
      }
  }
  else if(gift=="火箭")
  {

      if(monney>=0){
          SingleTon<GiftWidget>::getReference().setMonney(monney);

          SingleTon<GiftWidget>::getReference().setIntegral(integral);
          return;
      }
  }else{}

}

void ClientHandlerGiftMonney::gift_monney(const QString &giftway, const QString &username, const QString &roomname, const QString &roomusername, const int &gift)
{
    QJsonObject json;
    json["giftway"]=giftway;
    json["username"]=username;
    json["roomname"]=roomname;
    json["roomusername"]=roomusername;

    json["gift"]=gift;
    qDebug()<<gift;
    auto data=QJsonDocument(json).toJson();
    SingleTon<Client>::getReference().write(Streamer::pack(Handler::gift_monney,data));
}








/**
 * @brief ClientHandlerGiftIntegral::handle
 * 积分送礼
 * @param data
 */
void ClientHandlerGiftIntegral::handle(const QByteArray &data)
{
    QJsonObject json=QJsonDocument::fromJson(data).object();
    QString result=json["result"].toString();
    QString info=json["info"].toString();
    QString gift=json["gift"].toString();
    int integral=json["integral_result"].toInt();

    if(result=="failed")
    {
        if(info.isEmpty())
        {
            QMessageBox::warning(SingleTon<GiftWidget>::getInstance(),"送礼信息","送礼失败");
            return;
        }else
        {
            QMessageBox::warning(SingleTon<GiftWidget>::getInstance(),"送礼信息",info);
            return;
        }

    }

    if(gift=="鱼蛋")
    {

        if(integral>=0){
            SingleTon<GiftWidget>::getReference().setIntegral(integral);
            return;
        }
    }
    else if(gift=="飞机")
    {

        if(integral>=0){
            SingleTon<GiftWidget>::getReference().setIntegral(integral);
            return;
        }
    }
    else if(gift=="火箭")
    {

        if(integral>=0){
            SingleTon<GiftWidget>::getReference().setIntegral(integral);
            return;
        }
    }else{}
}

void ClientHandlerGiftIntegral::gift_integral(const QString &giftway, const QString &username, const QString &roomname, const QString &roomusername, const int &gift)
{
    QJsonObject json;
    json["giftway"]=giftway;
    json["username"]=username;
    json["roomname"]=roomname;
    json["roomusername"]=roomusername;

    json["gift"]=gift;
    qDebug()<<gift;
    auto data=QJsonDocument(json).toJson();
    SingleTon<Client>::getReference().write(Streamer::pack(Handler::gift_integral,data));
}


/**
 * @brief ClientHandlerGoaway::goaway
 * 离聊太室策略
 * @param username
 * @param roomname
 */
void ClientHandlerGoaway::handle(const QByteArray &data)
{
    QJsonObject json=QJsonDocument::fromJson(data).object();
    SingleTon<ChatroomWidget>::getReference().clearLvuser();
    SingleTon<ChatroomWidget>::getReference().hide();
    SingleTon<RoomWidget>::getReference().show();

}

void ClientHandlerGoaway::goaway(const QString &username, const QString &roomname)
{
    QJsonObject json;
    json["username"]=username;
    json["roomname"]=roomname;

    auto data=QJsonDocument(json).toJson();
    SingleTon<Client>::getReference().write(Streamer::pack(Handler::goaway,data));
}


/**
 * @brief ClientHandlerExit::handle
 * 退出登录
 * @param data
 */
void ClientHandlerExit::handle(const QByteArray &data)
{

}

void ClientHandlerExit::exit(const QString &username)
{
    QJsonObject json;
    json["username"]=username;

    auto data=QJsonDocument(json).toJson();
    SingleTon<Client>::getReference().write(Streamer::pack(Handler::exit,data));


}
