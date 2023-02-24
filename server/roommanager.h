#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include <QVector>
#include <QList>
#include <QTcpSocket>
#include <QMap>
#include "../common/singleton.h"
/**
 * @brief The RoomManager class
 * @brief 管理聊天室
 */
class RoomManager
{
    friend class SingleTon<RoomManager>;
private:
    RoomManager();
    RoomManager(const RoomManager&)=delete;
    RoomManager(RoomManager&&)=delete;

public:

    bool appendroom(const QString& roomname,const QString& roomusername);
    const QString findroom(const QString& roomname);
    inline const QVector<QString>& getRoomnames(){return this->roomnames;}
    const QMap<QString,QString>& getRooms(){return this->rooms;}

    const QString findroomusername(const QString& roomname);
    //加载数据库中房间信息
    void setRooms();
    void setRoomnames();

private:

    QMap<QString,QString> rooms;
    QVector<QString> roomnames;


};

#endif // ROOMMANAGER_H
