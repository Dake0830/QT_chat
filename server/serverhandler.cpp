#include "serverhandler.h"

#include <QJsonObject>
#include <QJsonDocument>
#include <QList>
#include <QDebug>

#include "socket.h"
#include "sqldao.h"
#include "roommanager.h"

/**
 * @brief ServerHandler::ServerHandler
 * @param socket
 * @brief
 */
ServerHandler::ServerHandler(Socket *socket)
{
    handlers=QVector<IHandler*>(last,nullptr);

    handlers[regist]=new ServerHandlerRegister(socket);
    handlers[login]=new ServerHandlerLogin(socket);
    handlers[creatroom]=new ServerHandlerCreatroom(socket);
    handlers[refresh]=new ServerHandlerRefresh(socket);
    handlers[join]=new ServerHandlerJoin(socket);
    handlers[chrefresh]=new ServerHandlerChrefresh(socket);
    handlers[chat]=new ServerHandlerChat(socket);
    handlers[recharge]=new ServerHandlerRecharge(socket);
    handlers[gift]=new ServerHandlerGift(socket);

    handlers[gift_monney]=new ServerHandlerGiftMonney(socket);
    handlers[gift_integral]=new ServerHandlerGiftIntegral(socket);
    handlers[goaway]=new ServerHandlerGoaway(socket);
    handlers[exit]=new ServerHandlerExit(socket);
}

/**
 * @brief ServerHandler::reset
 */
void ServerHandler::reset()

{
    for(auto handler:handlers)if(handler)handler->reset();
}
void ServerHandlerRegister::handle(const QByteArray &data)
{
    //注册操作
    QJsonObject json=QJsonDocument::fromJson(data).object();

    QString username=json["username"].toString();
    QString password=json["password"].toString();

   //注册判断
   //数据插入成功--注册成功   失败==注册失败 用户名重复

    json=QJsonObject();
    QString error=SqlDao::selectUser(username);
    if(!error.isEmpty()){
        json["result"]="repeat";

    }else if(SqlDao::insertUser(username,password)){

        json["result"]="success";

    }else{
        json["result"]="failed";
    }


    socket->write(Streamer::pack(Handler::regist,QJsonDocument(json).toJson()));

}

/**
 * @brief ServerHandlerLogin::handle
 * @param data
 *
 */
void ServerHandlerLogin::handle(const QByteArray &data)
{
    //登录处理
    QJsonObject json=QJsonDocument::fromJson(data).object();

    QString username=json["username"].toString();
    QString password=json["password"].toString();

    //查询
    json=QJsonObject();
    QString ret=SqlDao::selectUser(username);

    do{
        if(ret.isEmpty()){
            //没找到
            json["result"]="failed";
            json["info"]="无此用户";
            break;
        }

        if(ret != password){
            //密码错误
            json["result"]="failed";
            json["info"]="密码错误";
            break;
        }

        if(SingleTon<ServerLoginManager>::getReference().loginManager.find(username)
                !=SingleTon<ServerLoginManager>::getReference().loginManager.end()){
            json["result"]="failed";
            json["info"]="重复登录";
            break;
        }

        //登录成功
        json["username"]=username;
        json["result"]="success";
        json["info"]="登录成功";
        u=username;

        SingleTon<ServerLoginManager>::getReference().loginManager[username]=socket;


    }while(0);
    //打开数据库将用户房间信息存入服务器
    SingleTon<RoomManager>::getReference().setRoomnames();
    SingleTon<RoomManager>::getReference().setRooms();
    socket->write(Streamer::pack(Handler::login,QJsonDocument(json).toJson()));
}

/**
 * @brief ServerHandlerLogin::reset
 * @brief 如果当前套接字所绑定的用户已经登录，则需要去除登录状态
 */
void ServerHandlerLogin::reset()
{
    if(u.isEmpty()==false){
       SingleTon<ServerLoginManager>::getReference().loginManager.remove(u);
    }

}


/**
 * @brief ServerHandlerCreatroom::handle
 * 创建房间
 * @param data
 *
 */
void ServerHandlerCreatroom::handle(const QByteArray &data)
{
    QJsonObject json=QJsonDocument::fromJson(data).object();

    QString roomname=json["roomname"].toString();
    QString roomusname=json["username"].toString();
    //qDebug()<<roomname;
    json=QJsonObject();
    QString error=SqlDao::selectRoom(roomname);
   if(SingleTon<RoomManager>::getReference().appendroom(roomname,roomusname)){

       json["result"]="success";
       json["roomname"]=roomname;
   }else{
        if(!SingleTon<RoomManager>::getReference().findroom(roomname).isEmpty()){
            //房名重复
             json["result"]="repeat";
        }else{

            json["result"]="failed";
        }
   }

    socket->write(Streamer::pack(Handler::creatroom,QJsonDocument(json).toJson()));

}


/**
 * @brief ServerHandlerRefresh::handle
 * 刷新处理
 * @param data
 */
void ServerHandlerRefresh::handle(const QByteArray &data)
{
    QJsonObject json = QJsonDocument::fromJson(data).object();

   QVector<QString> roomnames=SingleTon<RoomManager>::getReference().getRoomnames();//存放房间名字的容器
   if(roomnames.isEmpty()){
       socket->write(Streamer::pack(Handler::refresh,data));
   }else{
        //把房间名转成json格式存进json容器中
       for(auto i:roomnames){
           json[i]=i;
       }
       socket->write(Streamer::pack(Handler::refresh,QJsonDocument(json).toJson()));//打包发给客户端
   }
}

/**
 * @brief ServerHandlerJoin::handle
 * 加入房间，房间在线列表管理
 * @param data
 */
void ServerHandlerJoin::handle(const QByteArray &data)
{
   QJsonObject json=QJsonDocument::fromJson(data).object();
   QString username=json["username"].toString();
   QString roomname=json["roomname"].toString();


   json=QJsonObject();
   //查找房间，添加进房间在线列表
   do{
   if(SingleTon<RoomManager>::getReference().findroom(roomname).isEmpty()){
           //没有房间
       json["result"]="failed";
       json["info"]="没有该聊天室";
       break;
   }
   SingleTon<ServerJoinManager>::getReference().JoinManager[roomname].insert(username,socket);
   //SingleTon<ServerJoinManager>::getReference().onlineus[roomname].append(username);
   }while (0);
//加入结果和房主信息，客户信息打包

    json["roomusername"]=SingleTon<RoomManager>::getReference().findroomusername(roomname);
    json["username"]=username;

  for(auto s: SingleTon<ServerJoinManager>::getReference().JoinManager[roomname]){
      s->write(Streamer::pack(Handler::join,QJsonDocument(json).toJson()));
  }

}


/**
 * @brief ServerHandlerChrefresh::handle
 * 刷新在线成员
 * @param data
 */
void ServerHandlerChrefresh::handle(const QByteArray &data)
{
     QJsonObject json = QJsonDocument::fromJson(data).object();
     QString roomname=json["roomname"].toString();

     json=QJsonObject();
     for(auto o:SingleTon<ServerHandlerJoin::ServerJoinManager>::getReference().JoinManager[roomname].keys()){
         json[o]=o;
     }

     socket->write(Streamer::pack(Handler::chrefresh,QJsonDocument(json).toJson()));
}

/**
 * @brief ServerHandlerChat::handle
 * 聊天策略处理
 * @param data
 */
void ServerHandlerChat::handle(const QByteArray &data)
{
    QJsonObject json=QJsonDocument::fromJson(data).object();
    QString roomname=json["roomname"].toString();
    //qDebug()<<roomname;
    for(auto s:SingleTon<ServerHandlerJoin::ServerJoinManager>::getReference().JoinManager[roomname].values()){
        s->write(Streamer::pack(Handler::chat,data));
    }
}

/**
 * @brief ServerHandlerRecharge::handle
 * 充值策略
 * @param data
 */
void ServerHandlerRecharge::handle(const QByteArray &data)
{
    QJsonObject json=QJsonDocument::fromJson(data).object();
    QString username=json["username"].toString();
    int usermonney=json["monney"].toInt();
    if(username.isEmpty()){
       qDebug()<<"客户端数据有误";
    }
    //修改用户余额
    int monney=SingleTon<SqlDao>::getReference().selectUsermonney(username)+usermonney;
    json=QJsonObject();
    if(SingleTon<SqlDao>::getReference().updateUsermonney(username,monney)){
        json["result"]="success";
        json["monney"]=monney;

    }else{
        json["result"]="failed";

    }
     socket->write(Streamer::pack(Handler::recharge,QJsonDocument(json).toJson()));
}

/**
 * @brief ServerHandlerGift::handle
 * 送礼策略
 * @param data
 */
void ServerHandlerGift::handle(const QByteArray &data)
{
    QJsonObject json=QJsonDocument::fromJson(data).object();
    QString username=json["username"].toString();
    if(username.isEmpty()){
       qDebug()<<"客户端数据有误";
       return;
    }
    json=QJsonObject();
    int monney=SingleTon<SqlDao>::getReference().selectUsermonney(username);
    int integral=SingleTon<SqlDao>::getReference().selectUserintegral(username);
    //查找失败
    if(monney<0 || integral<0){
        qDebug()<<"数据库没找到余额和积分信息";
        return;
    }
    json["monney"]=monney;
    json["integral"]=integral;
     socket->write(Streamer::pack(Handler::gift,QJsonDocument(json).toJson()));

}




/**
 * @brief ServerHandlerGift::handle
 * 余额送礼策略
 * @param data
 */

void ServerHandlerGiftMonney::handle(const QByteArray &data)
{
     QJsonObject json=QJsonDocument::fromJson(data).object();
     QString username=json["username"].toString();
     QString roomname=json["roomname"].toString();
     QString roomusername=json["roomusername"].toString();
     QString giftway=json["giftway"].toString();
     int gift=json["gift"].toInt();


     json=QJsonObject();
     json["username"]=username;
     QString res;
     do{
        //用户扣钱
           int result=SingleTon<SqlDao>::getReference().selectUsermonney(username)-gift;

           if(result<0)
           {
               json["result"]="failed";
               json["info"]="金额余额不足";
               break;
           }
            if(SingleTon<SqlDao>::getReference().updateUsermonney(username,result)==false)
            {
                //失败
                res="failed";
                json["result"]=res;
                break;
            }


          json["result_monney"]=result;
      //房主加钱
         result=SingleTon<SqlDao>::getReference().selectUsermonney(roomusername)+gift;

         if(SingleTon<SqlDao>::getReference().updateUsermonney(roomusername,result)==false)
         {
             //失败
             res="failed";
             json["result"]=res;
             break;
         }

      //用户加积分
         //金钱转积分
         if(gift==10)
         {
             gift=100;
             json["gift"]="鱼蛋";
         }
         if(gift==200)
         {
             gift=1019;
             json["gift"]="飞机";

         }
         if(gift==999)
         {
             gift=16666;
             json["gift"]="火箭";
         }

         result=SingleTon<SqlDao>::getReference().selectUserintegral(username)+gift;
         if(SingleTon<SqlDao>::getReference().updateUserintegral(username,result)==false)
         {
             //失败
             res="failed";
             json["result"]=res;
             break;
         }
        json["integral_result"]=result;
     }while(0);

    //像客户端发送结果
     if(res=="failed")
     {
         //失败
         socket->write(Streamer::pack(Handler::gift_monney,QJsonDocument(json).toJson()));
         return;
     }
     //循环发送给所有聊天室用户消息
     for(auto s:SingleTon<ServerHandlerJoin::ServerJoinManager>::getReference().JoinManager[roomname].values())
     {

         s->write(Streamer::pack(Handler::chat,QJsonDocument(json).toJson()));
     }

     socket->write(Streamer::pack(Handler::gift_monney,QJsonDocument(json).toJson()));

     //如果房主在线，刷新房主信息
    for(auto roomuser:SingleTon<ServerHandlerJoin::ServerJoinManager>::getReference().JoinManager[roomname].keys())
    {
        if(roomuser==roomusername)
        {
            json=QJsonObject();
            int monney=SingleTon<SqlDao>::getReference().selectUsermonney(roomusername);
            int integral=SingleTon<SqlDao>::getReference().selectUserintegral(roomusername);
            //查找失败
            if(monney<0 || integral<0){
                qDebug()<<"数据库没找到余额和积分信息";
                return;
            }
            json["monney"]=monney;
            json["integral"]=integral;
            SingleTon<ServerHandlerJoin::ServerJoinManager>::getReference().JoinManager[roomname].value(roomuser)->write(Streamer::pack(Handler::gift,QJsonDocument(json).toJson()));

        }
    }


}

/**
 * @brief ServerHandlerGiftIntegral::handle
 * 积分送礼
 * @param data
 */
void ServerHandlerGiftIntegral::handle(const QByteArray &data)
{
    QJsonObject json=QJsonDocument::fromJson(data).object();
    QString username=json["username"].toString();
    QString roomname=json["roomname"].toString();
    QString roomusername=json["roomusername"].toString();
    QString giftway=json["giftway"].toString();
    int gift=json["gift"].toInt();//积分


    json=QJsonObject();
    QString res;
    json["username"]=username;

    do{
       //用户扣积分
          int result=SingleTon<SqlDao>::getReference().selectUserintegral(username)-gift;
          if(result<0)
          {
              json["result"]="failed";
              json["info"]="积分不足";
              break;
          }
           if(SingleTon<SqlDao>::getReference().updateUserintegral(username,result)==false)
           {
               //失败
               res="failed";
               json["result"]=res;
               break;
           }
         json["integral_result"]=result;
     //房主加钱
           //积分转金钱
           if(gift==100)
           {
               gift=10;
               json["gift"]="鱼蛋";
           }
           if(gift==1019)
           {
               gift=200;
               json["gift"]="飞机";

           }
           if(gift==16666)
           {
               gift=999;
               json["gift"]="火箭";
           }
        result=SingleTon<SqlDao>::getReference().selectUsermonney(roomusername)+gift;

        if(SingleTon<SqlDao>::getReference().updateUsermonney(roomusername,result)==false)
        {
            //失败
            res="failed";
            json["result"]=res;
            break;
        }

    }while(0);

   //像客户端发送结果
    if(res=="failed"){
        //失败
        socket->write(Streamer::pack(Handler::gift_integral,QJsonDocument(json).toJson()));
        return;
    }
    //循环发送给所有聊天室用户消息

    for(auto s:SingleTon<ServerHandlerJoin::ServerJoinManager>::getReference().JoinManager[roomname].values())
    {
        s->write(Streamer::pack(Handler::chat,QJsonDocument(json).toJson()));
    }

   socket->write(Streamer::pack(Handler::gift_integral,QJsonDocument(json).toJson()));

   //如果房主在线，刷新房主信息
  for(auto roomuser:SingleTon<ServerHandlerJoin::ServerJoinManager>::getReference().JoinManager[roomname].keys())
  {
      if(roomuser==roomusername)
      {
          json=QJsonObject();
          int monney=SingleTon<SqlDao>::getReference().selectUsermonney(roomusername);
          int integral=SingleTon<SqlDao>::getReference().selectUserintegral(roomusername);
          //查找失败
          if(monney<0 || integral<0){
              qDebug()<<"数据库没找到余额和积分信息";
              return;
          }
          json["monney"]=monney;
          json["integral"]=integral;
          SingleTon<ServerHandlerJoin::ServerJoinManager>::getReference().JoinManager[roomname].value(roomuser)->write(Streamer::pack(Handler::gift,QJsonDocument(json).toJson()));

      }
  }

}

/**
 * @brief ServerHandlerGoaway::handle
 * 离开策略
 * @param data
 */
void ServerHandlerGoaway::handle(const QByteArray &data)
{
    QJsonObject json=QJsonDocument::fromJson(data).object();
    QString roomname=json["roomname"].toString();
    QString username=json["username"].toString();

    json=QJsonObject();
    //删除在线状态
    for(auto user:SingleTon<ServerHandlerJoin::ServerJoinManager>::getReference().JoinManager[roomname].keys())
    {
        if(user==username)
        {
            SingleTon<ServerHandlerJoin::ServerJoinManager>::getReference().JoinManager[roomname].remove(user);

            socket->write(Streamer::pack(Handler::goaway,QJsonDocument(json).toJson()));
            continue;
        }

        json[user]=user;

    }
    for(auto s:SingleTon<ServerHandlerJoin::ServerJoinManager>::getReference().JoinManager[roomname].values())
    {
        s->write(Streamer::pack(Handler::chrefresh,QJsonDocument(json).toJson()));
    }

}





/**
 * @brief ServerHandlerExit::handle
 * 退出登录状态
 * @param data
 */
void ServerHandlerExit::handle(const QByteArray &data)
{
     QJsonObject json=QJsonDocument::fromJson(data).object();
     QString username=json["username"].toString();

     //删除登录在线套接字
    SingleTon<ServerHandlerLogin::ServerLoginManager>::getReference().loginManager.remove(username);


}
