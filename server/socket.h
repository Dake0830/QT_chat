#ifndef SOCKET_H
#define SOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QList>

#include "../common/streamer.h"
#include "serverhandler.h"
/**
 * @brief The Socket class
 * @brief 管理连接（套接字）
 */

class Socket :public QObject
{
    Q_OBJECT
private:
    friend class Server;
    explicit Socket(QTcpSocket* socket,QObject* parent=nullptr);

public:
    inline qint64 write(const QByteArray& data){return socket->write(data);}
private slots:
    void onReadyRead();//读包
    void onDisconnected();//断连操作

signals:

private:
    QTcpSocket* socket;
    Streamer streamer;

    ServerHandler handler;

};

#endif // SOCKET_H
