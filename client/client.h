#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

#include "../common/singleton.h"
#include "../common/streamer.h"
#include "clienthandler.h"

/**
 * @brief The Client class
 * @brief 管理连接之后的操作
 */
class Client :public QObject
{
    Q_OBJECT
private:
    friend class SingleTon<Client>;
    explicit Client(QObject *parent=nullptr);
    Client(const Client&)=delete;
    Client(Client&&)=delete;

private slots:
    void onReadyRead();

public:
    bool connectToHost(const QString& addr,qint16 port);
    inline qint64 write(const QByteArray& data){return socket->write(data);}

    Streamer& getStreamer(){return streamer;}

signals:

private:
    QTcpSocket* socket;

    Streamer streamer;

    ClientHandler handler;
};

#endif // CLIENT_H
