#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include "../common/handler.h"
class Client;

class ClientHandler : public Handler
{
public:
    ClientHandler(Client* client);
};

class ClientIHandler : public IHandler
{
public:
    ClientIHandler(Client* client):client(client){}

protected:
    Client* client;//依赖Client,用于发送数据
};

/**
 * @brief The ClientHandlerRegister class
 * @brief 注册具体策略
 */
class ClientHandlerRegister:public ClientIHandler
{
public:
    ClientHandlerRegister(Client* client):ClientIHandler(client){}

    virtual void handle(const QByteArray& data)override;
    static void regist(const QString& username,const QString& password);
};

/**
 * @brief The ClientHandlerLogin class
 * @brief 登录具体策略
 */
class ClientHandlerLogin : public ClientIHandler
{
public:
    ClientHandlerLogin(Client* client):ClientIHandler(client){}

    virtual void handle(const QByteArray& data)override;
    static void login(const QString& username,const QString& password);
};

/**
 * @brief The ClientHandlerCreatroom class
 * @brief 创建房间策略
 */
class ClientHandlerCreatroom : public ClientIHandler
{
public:
    ClientHandlerCreatroom(Client* client):ClientIHandler(client){}

    virtual void handle(const QByteArray& data)override;
    static void creatroom(const QString& username,const QString& roomname);

};


/**
 * @brief The ClientHandlerRefresh class
 * 刷新房间列表策略
 *
 */
class ClientHandlerRefresh : public ClientIHandler
{
public:
    ClientHandlerRefresh(Client* client):ClientIHandler(client){}

    virtual void handle(const QByteArray& data)override;
    static void refresh();
};

/**
 * @brief The ClientHandlerJoin class
 * 加入房间策略
 */
class ClientHandlerJoin :public ClientIHandler
{
public:
    ClientHandlerJoin(Client* client):ClientIHandler(client){}

    virtual void handle(const QByteArray& data)override;
    static void joinchat(const QString& username,const QString& roomname);
};

/**
 * @brief The ClientHandlerChrefresh class
 * 刷新在线成员列表
 */
class ClientHandlerChrefresh :public ClientIHandler
{
public:
    ClientHandlerChrefresh(Client* client):ClientIHandler(client){}

    virtual void handle(const QByteArray& data)override;
    static void chrefresh(const QString& roomname);

};


/**
 * @brief The ClientHandlerChat class
 * 聊天策略
 */
class ClientHandlerChat :public ClientIHandler
{
public:
    ClientHandlerChat(Client* client):ClientIHandler(client){}

    virtual void handle(const QByteArray& data)override;
    static void chat(const QString& username,const QString& roomname,const QString& message);
};

/**
 * @brief The ClientHandlerRecharge class
 * 充值策略
 */
class ClientHandlerRecharge :public ClientIHandler
{
public:
    ClientHandlerRecharge(Client* client):ClientIHandler(client){}
   virtual void handle(const QByteArray& data)override;
    static void recharge(const int& monney,const QString& username);


};

class ClientHandlerGift :public ClientIHandler
{
public:
    ClientHandlerGift(Client* client):ClientIHandler(client){}
    virtual void handle(const QByteArray& data)override;

    static void gif(const QString& username);

};
/**
 * @brief The ClientHandlerGift class
 * 余额送礼策略
 */
class ClientHandlerGiftMonney :public ClientIHandler
{
public:
    ClientHandlerGiftMonney(Client* client):ClientIHandler(client){}
    virtual void handle(const QByteArray& data)override;

    static void gift_monney(const QString& giftway,const QString& username,const QString& roomname,const QString& roomusername,const int& gift);
};

/**
 * @brief The ClientHandlerGiftIntegral class
 * 积分送礼
 */
class ClientHandlerGiftIntegral :public ClientIHandler
{
public:
    ClientHandlerGiftIntegral(Client* client):ClientIHandler(client){}
    virtual void handle(const QByteArray& data)override;
    static void gift_integral(const QString& giftway,const QString& username,const QString& roomname,const QString& roomusername,const int& gift);

};



/**
 * @brief The ClientHandlerGoaway class
 * 离开聊天室策略
 */
class ClientHandlerGoaway :public ClientIHandler
{
public:
    ClientHandlerGoaway(Client* client):ClientIHandler(client){}
    virtual void handle(const QByteArray& data)override;
    static void goaway(const QString& username,const QString& roomname);
};

/**
 * @brief The ClientHandlerExit class
 * 退出登录状态
 */
class ClientHandlerExit :public ClientIHandler
{
public:
    ClientHandlerExit(Client* client):ClientIHandler(client){}
    virtual void handle(const QByteArray& data)override;
    static void exit(const QString& username);
};
#endif // CLIENTHANDLER_H

