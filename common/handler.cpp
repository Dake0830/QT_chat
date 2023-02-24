#include "handler.h"

Handler::Handler()
{

}

void Handler::handle(int type, const QByteArray &data)
{
    if(type<0 || type>=handlers.size())return;
    if(handlers[type]==nullptr)return;

    handlers[type]->handle(data);
}

