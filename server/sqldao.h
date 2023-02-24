#ifndef SQLDAO_H
#define SQLDAO_H

#include <QString>
#include <QSqlDatabase>
#include <QMap>
#include <QVector>

#include <QDebug>
#include <QSqlError>

#include "../common/singleton.h"

/**
 * @brief The SqlDao class
 *
 * @brief  数据接口层，保存到数据库
 *
 *
 */


class SqlDao
{

private:
    //数据库管理
    struct SqlDaoDb{
      QSqlDatabase db;

      inline SqlDaoDb()
        :db(QSqlDatabase::addDatabase("QMYSQL"))
      {
          db.setUserName("root");
          db.setPassword("wdx123");
          db.setDatabaseName("chatsystem");
      }

      inline bool open(){
          if(!db.isOpen()){
              if(!db.open())qDebug()<< db.lastError().text();
          }
          return db.isOpen();
      }

      inline void close(){ db.close();}
    };
public:
    SqlDao();

    //判断添加成功
    static bool insertUser(const QString& username,const QString& password);

    //查看用户
    static QString selectUser(const QString& username);

    //用户余额操作
        //查看余额
    static int selectUsermonney(const QString& username);
        //修改余额
    static bool updateUsermonney(const QString& username,const int& monney);

    //用户积分操作
    static int selectUserintegral(const QString& username);
    static bool updateUserintegral(const QString& username,const int& integral);



    //判断聊天室添加成功
    static bool insertRoom(const QString& roomname,const QString& roomusname);

    //查看房间

    static QString selectRoom(const QString& roomname);


    //加载数据库
    inline QVector<QString>& getRoomnames(){return this->roomnames;}
    QMap<QString,QString>& getRooms(){return this->rooms;}

    //更新数据
    void setRoomnames();
    void setRooms();
private:
    QVector<QString>roomnames;
    QMap<QString,QString>rooms;

};

#endif // SQLDAO_H
