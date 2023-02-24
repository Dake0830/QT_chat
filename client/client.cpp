#include "client.h"

Client::Client(QObject *parent)
    :QObject(parent),
      streamer(),handler(this)
{
    //创建套接字
    socket=new QTcpSocket(this);

    QObject::connect(socket,&QTcpSocket::readyRead,
                     this,&Client::onReadyRead);

}

void Client::onReadyRead()
{
    streamer.attach(socket->readAll());
    while(1){
        int type;
        QByteArray data;
        if(streamer.unpack(type,data)){
            handler.handle(type,data);
        }else{
            //false
            break;
        }

    }
}

bool Client::connectToHost(const QString &addr, qint16 port)
{
    if(socket->isValid())return false;

    socket->connectToHost(addr,port);
    return socket->waitForConnected(1000);
}


