
#include "client.h"
#include "loginwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SingleTon<LoginWidget>::getReference().show();
    SingleTon<Client>::getReference().connectToHost("127.0.0.1",2222);

    return a.exec();
}
