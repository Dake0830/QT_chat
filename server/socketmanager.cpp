#include "socketmanager.h"

SocketManager::SocketManager()
{

}

void SocketManager::append(QTcpSocket *socket)
{
    this->sockets.append(socket);
}

void SocketManager::remove(QTcpSocket *socket)
{
    this->sockets.removeOne(socket);
}

QList<QTcpSocket *> SocketManager::getSockets()
{
    return sockets;
}
