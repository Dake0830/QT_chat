#include "socket.h"
#include "socketmanager.h"

#include <QHostAddress>
#include <QDebug>
Socket::Socket(QTcpSocket* socket,QObject *parent)
    :QObject(parent),socket(socket),
      streamer(),handler(this)
{
    qDebug()<<"[socket] 新的连接<IP> "
            <<socket->peerAddress().toString()<<" <PORT> "
            <<socket->peerPort();

    QObject::connect(socket,&QTcpSocket::disconnected,
                     this,&Socket::onDisconnected);
    QObject::connect(socket,&QTcpSocket::readyRead,
                     this,&Socket::onReadyRead);

    // 单列模式调用SocketManager
    SingleTon<SocketManager>::getReference().append(socket);
}



void Socket::onReadyRead()
{
    streamer.attach(socket->readAll());
    while(1){
        int type;
        QByteArray data;
        if(streamer.unpack(type,data)){
            handler.handle(type,data);
        }else{
            //失败
            break;
        }
    }
}

void Socket::onDisconnected()
{
    qDebug()<<"[socket] 断开连接 <IP> "
            <<socket->peerAddress().toString()<<" <PORT> "
            <<socket->peerPort();

    SingleTon<SocketManager>::getReference().remove(socket);

    //回收状态
    handler.reset();
    socket->deleteLater();
    this->deleteLater();
}

