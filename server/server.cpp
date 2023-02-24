#include "server.h"
#include "socket.h"
#include <QHostAddress>
Server::Server(QObject *parent)
    :QObject(parent)
{
    server=new QTcpServer(this);

    QObject::connect(server,&QTcpServer::newConnection,this,&Server::onNewConnection);

}

bool Server::listen(const QString &addr, qint16 port)
{
    if(server->isListening())return false;
    return server->listen(QHostAddress(addr),port);
}

void Server::onNewConnection()
{
    while(server->hasPendingConnections()){
        QTcpSocket* socket=server->nextPendingConnection();

        if(socket)new Socket(socket,this);
    }
}
