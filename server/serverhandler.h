#ifndef SERVERHANDLER_H
#define SERVERHANDLER_H

#include "../common/handler.h"
#include <QMap>
#include <QList>
#include <QVector>
class Socket;

class ServerHandler : public Handler
{
public:
    ServerHandler(Socket* socket);
    void reset();
};

class ServerIHandler : public IHandler
{
public:
    ServerIHandler(Socket* socket):socket(socket){}

protected:
    Socket* socket;
};

/**
 * @brief The ServerHandlerRegister class
 * @brief 服务器处理用户注册的具体策略
 */
class ServerHandlerRegister : public ServerIHandler
{
public:
    ServerHandlerRegister(Socket* socket):ServerIHandler(socket){}
    virtual void handle(const QByteArray& data)override;
};

/**
 * @brief The ServerHandlerLogin class
 * @brief 服务器处理用户登录的具体策略
 */
class ServerHandlerLogin : public ServerIHandler
{
public:
    struct ServerLoginManager{
      QMap<QString,Socket*>loginManager;
    };
    ServerHandlerLogin(Socket* socket):ServerIHandler(socket){}
    virtual void handle(const QByteArray& data)override;
    virtual void reset()override;

private:
    QString u;
};

/**
 * @brief The ServerHandlerCreatroom class
 * @brief 服务器处理用户创建房间策略
 */
class ServerHandlerCreatroom : public ServerIHandler
{
public:
    ServerHandlerCreatroom(Socket* socket):ServerIHandler(socket){}
    virtual void handle(const QByteArray& data)override;

};

/**
 * @brief The ServerHandlerRefresh class
 * @brief 刷新操作
 */
class ServerHandlerRefresh : public ServerIHandler
{
public:
    ServerHandlerRefresh(Socket* socket):ServerIHandler(socket){}
    virtual void handle(const QByteArray& data)override;
};

/**
 * @brief The ServerHandlerJoin class
 * 加入房间的在线列表管理
 */
class ServerHandlerJoin :public ServerIHandler
{
public:
    struct ServerJoinManager{
      QMap<QString,QMap<QString,Socket*>>JoinManager;
      //QMap<QString,QList<QString>> onlineus;
    };
    ServerHandlerJoin(Socket* socket):ServerIHandler(socket){}
    virtual void handle(const QByteArray& data)override;
    //virtual void reset()override;
private:

};

/**
 * @brief The ServerHandlerChrefresh class
 * 刷新在线列表处理
 */
class ServerHandlerChrefresh :public ServerIHandler
{
public:
    ServerHandlerChrefresh(Socket* socket):ServerIHandler(socket){}
    virtual void handle(const QByteArray& data)override;
};

/**
 * @brief The ServerHandlerChat class
 * 聊天策略处理
 */
class ServerHandlerChat :public ServerIHandler
{
public:
    ServerHandlerChat(Socket* socket):ServerIHandler(socket){}
    virtual void handle(const QByteArray& data);
};

/**
 * @brief The ServerHandlerRecharge class
 * 用户充值策略
 */
class ServerHandlerRecharge :public ServerIHandler
{
public:
    ServerHandlerRecharge(Socket* socket):ServerIHandler(socket){}
    virtual void handle(const QByteArray& data);
};

/**
 * @brief The ServerHandlerGift class
 * 送礼策略设置客户端余额和积分值
 */
class ServerHandlerGift :public ServerIHandler
{
public:
    ServerHandlerGift(Socket* socket):ServerIHandler(socket){}
    virtual void handle(const QByteArray& data)override;
};


/**
 * @brief The ServerHandlerGift class
 * 余额送礼策略
 */
class ServerHandlerGiftMonney :public ServerIHandler
{
public:
    ServerHandlerGiftMonney(Socket* socket):ServerIHandler(socket){}
    virtual void handle(const QByteArray& data)override;
};

/**
 * @brief The ServerHandlerGiftIntegral class
 * 积分送礼
 */
class ServerHandlerGiftIntegral :public ServerIHandler
{
public:
    ServerHandlerGiftIntegral(Socket* socket):ServerIHandler(socket){}
    virtual void handle(const QByteArray& data)override;
};


/**
 * @brief The ServerHandlerGoaway class
 * 离开聊天室策略
 */
class ServerHandlerGoaway :public ServerIHandler
{
public:
    ServerHandlerGoaway(Socket* socket):ServerIHandler(socket){}
    virtual void handle(const QByteArray& data)override;
};


class ServerHandlerExit :public ServerIHandler
{
public:
    ServerHandlerExit(Socket* socket):ServerIHandler(socket){}
    virtual void handle(const QByteArray& data)override;
};
#endif // SERVERHANDLER_H
