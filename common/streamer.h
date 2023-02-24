#ifndef STREAMER_H
#define STREAMER_H

#include <QByteArray>
#include <QPair>

/**
 * @brief The Streamer class
 * 数据流的打包与拆包，粘包
 */
class Streamer
{
public:
    Streamer();

    static QByteArray pack(int type,const QByteArray& data);//打包
    bool unpack(int& type,QByteArray& data);//解压

    inline void attach(const QByteArray& stream){this->buffer+=stream;}//添加数据
    inline void clear(){this->buffer.clear();}//清空缓存

private:
    QByteArray buffer;//缓存

};



#endif // STREAMER_H
