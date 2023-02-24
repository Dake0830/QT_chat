#include "streamer.h"

Streamer::Streamer()
{

}

QByteArray Streamer::pack(int type, const QByteArray &data)
{
    // 包头+数据
    QByteArray head(8,0);
    memcpy(head.data(),&type,sizeof(int));

    int len=data.size();
    memcpy(head.data()+4,&len,sizeof(int));

    return head+data;
}

bool Streamer::unpack(int &type, QByteArray &data)
{
    if(buffer.size()<8)return false;

    int t,l;
    memcpy(&t,buffer.data(),sizeof(int));
    memcpy(&l,buffer.data()+4,sizeof(int));

    if(buffer.size()<(8+l))return false;

    data=buffer.mid(8,l);
    type=t;

    buffer=buffer.mid(8+l);
    return true;
}
