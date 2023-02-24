#ifndef SOCKETMANAGER_H
#define SOCKETMANAGER_H

#include <QList>
#include <QTcpSocket>

#include "../common/singleton.h"
/**
 * @brief The SocketManager class
 * @brief 管理已连接的套接字
 *
 */
class SocketManager
{
    friend class SingleTon<SocketManager>;
public:
    SocketManager();
    SocketManager(const SocketManager&)=delete;
    SocketManager(SocketManager&&)=delete;

public:
    void append(QTcpSocket* socket);//套接字链表添加
    void remove(QTcpSocket* socket);//断开连接套接字删除
    QList<QTcpSocket*> getSockets();//获取套接字链表
private:

    QList<QTcpSocket*>sockets;
};


#endif // SOCKETMANAGER_H
