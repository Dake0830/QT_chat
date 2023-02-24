#ifndef HANDLER_H
#define HANDLER_H

#include <QByteArray>
#include <QVector>

/**
 * @brief The Handler class
 * @brief 抽象策略，根据type解析，转到相应的具体策略
 */


class IHandler
{
public:
    virtual void handle(const QByteArray& data)=0;

    virtual void reset(){};

};

/**
 * @brief The Handler class
 * @brief 管理策略
 *  具体策略通过handler调度
 */

class Handler
{
public:
    enum Type{
        regist=0,//注册
        login=1,//登录
        creatroom,//创建房间
        refresh,//房间列表刷新
        join,//加入聊天室
        chrefresh,//在线成员列表
        chat,//聊天
        recharge,//充值
        gift,//送礼
        gift_monney,//余额送礼物
        gift_integral,//积分送礼
        goaway,//离开聊天室
        exit,//退出系统
        last
    };
    Handler();

    void handle(int type,const QByteArray& data);

protected:
    QVector<IHandler*>handlers;

};



#endif // HANDLER_H
