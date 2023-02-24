#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
/**
 *
 * @brief The Server class
 * 管理建立连接
 */
class Server :public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent=nullptr);

    bool listen(const QString& addr,qint16 port);

signals:

private slots:
    void onNewConnection();

private:
    QTcpServer* server;
};

#endif // SERVER_H
