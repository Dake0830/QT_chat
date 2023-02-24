#include "roommanager.h"
#include "sqldao.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPair>
RoomManager::RoomManager()
{

}

bool RoomManager::appendroom(const QString &roomname, const QString &roomusername)
{

     QMap<QString,QString>::iterator pos=this->rooms.find(roomname);
     if(pos == this->rooms.end()){
             //添加后没找到
            this->rooms.insert(roomname,roomusername);
    }else{
        return false;
    }
    this->roomnames.push_back(roomname);
    if(this->findroom(roomname).isEmpty()){
        return false;
    }
    if(SingleTon<SqlDao>::getReference().insertRoom(roomname,roomusername)==false)return false;
    return true;
}

const QString RoomManager::findroom(const QString &roomname)
{
    for(auto room:this->roomnames){
        if(room==roomname)return room;
    }
    return {};
}

/**
 * @brief RoomManager::findroomusername
 * 寻找房主
 * @param roomname
 * @return
 */
const QString RoomManager::findroomusername(const QString &roomname)
{
    QMap<QString,QString>::iterator pos=this->rooms.find(roomname);
    if(pos!=this->rooms.end()){
        return *pos;
    }
    return {};

}

void RoomManager::setRooms()
{
  SingleTon<SqlDao>::getReference().setRooms();
  this->rooms=SingleTon<SqlDao>::getReference().getRooms();
}

void RoomManager::setRoomnames()
{
    SingleTon<SqlDao>::getReference().setRoomnames();
    this->roomnames=SingleTon<SqlDao>::getReference().getRoomnames();
}



