#include <QCoreApplication>
#include "server.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;
    server.listen("127.0.0.1",2222);

    return a.exec();
}
