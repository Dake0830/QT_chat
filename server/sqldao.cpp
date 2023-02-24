#include "sqldao.h"
#include <QSqlDatabase>
#include <QSqlQuery>

SqlDao::SqlDao()
{

}

bool SqlDao::insertUser(const QString &username, const QString &password)
{
    //打开数据库
    if(SingleTon<SqlDaoDb>::getReference().open()==false)return false;

    //语句
    QSqlQuery query;
    query.prepare("insert into tb_usdata(username,password)"
                  "values(:0, :1);");
    query.bindValue(":0",username);
    query.bindValue(":1",password);

    if(query.exec()==false){
        qDebug()<<query.lastError().text();

        return false;

    }else{}

    return true;
}



QString SqlDao::selectUser(const QString &username)
{
    //打开数据库
    if(SingleTon<SqlDaoDb>::getReference().open()==false)return {};

    //语句
    QSqlQuery query;
    query.prepare("select password from tb_usdata where username= :0;");
    query.bindValue(":0",username);

    if(query.exec()==false){
        qDebug()<<query.lastError().text();

        return {};
    }else{
        if(query.next()){
            return query.value(0).toString();
        }
    }
    return {};
}

int SqlDao::selectUsermonney(const QString &username)
{
    //打开数据库
    if(SingleTon<SqlDaoDb>::getReference().open()==false)return -1;

    //语句
    QSqlQuery query;
    query.prepare("select monney from tb_usdata where username= :0;");
    query.bindValue(":0",username);
    if(query.exec()==false){
        qDebug()<<query.lastError().text();

        return -1;
    }else{
        if(query.next()){
            return query.value("monney").toInt();
        }
    }
    return -1;
}


bool SqlDao::updateUsermonney(const QString &username, const int& monney)
{
    //打开数据库
    if(SingleTon<SqlDaoDb>::getReference().open()==false)return false;

    //语句
    QSqlQuery query;
    query.prepare("update tb_usdata set monney=:1 where username=:2 ;");
    query.bindValue(":1",monney);
    query.bindValue(":2",username);

    if(query.exec()==false){
        qDebug()<<query.lastError().text();
        qDebug()<<"this";
        return false;

    }else{}

    return true;

}

int SqlDao::selectUserintegral(const QString &username)
{
    //打开数据库
    if(SingleTon<SqlDaoDb>::getReference().open()==false)return -1;

    //语句
    QSqlQuery query;
    query.prepare("select integral from tb_usdata where username= :0;");
    query.bindValue(":0",username);
    if(query.exec()==false){
        qDebug()<<query.lastError().text();

        return -1;
    }else{
        if(query.next()){
            return query.value("integral").toInt();
        }
    }
    return -1;
}

bool SqlDao::updateUserintegral(const QString &username, const int &integral)
{
    //打开数据库
    if(SingleTon<SqlDaoDb>::getReference().open()==false)return false;

    //语句
    QSqlQuery query;
    query.prepare("update tb_usdata set integral=:1 where username=:2 ;");
    query.bindValue(":1",integral);
    query.bindValue(":2",username);

    if(query.exec()==false){
        qDebug()<<query.lastError().text();
        return false;

    }else{}

    return true;
}

/**
 * @brief SqlDao::insertRoom
 * 判断添加房间是否成功
 * @param roomname
 * @param roomusname
 * @return
 */
bool SqlDao::insertRoom(const QString &roomname, const QString &roomusname)
{
    // 1. 打开数据库
    if(SingleTon<SqlDaoDb>::getReference().open()
            == false) return false;

    // 2. 语句
    QSqlQuery query;
    query.prepare("insert into tb_usroom(roomname, roomusername)"
                  "values(:1, :2);");
    query.bindValue(":1", roomname);
    query.bindValue(":2", roomusname);
    if(query.exec()==false){
        qDebug()<<query.lastError().text();
        return false;
    }else{}

    return true;
}

/**
 * @brief SqlDao::selectRoom
 *查找房间
 * @param roomname
 * @return
 */
QString SqlDao::selectRoom(const QString &roomname)
{
    // 1. 打开数据库
    if(SingleTon<SqlDaoDb>::getReference().open()
            == false) return {};

    // 2. 语句
    QSqlQuery query;
    query.prepare("select roomusername from tb_usroom where roomname= :1");
    query.bindValue(":1", roomname);

    if(query.exec()==false){
        qDebug()<<query.lastError().text();
        return {};
    }else{

        if(query.next()){
            return query.value(0).toString();
        }
    }

    return {};
}



void SqlDao::setRoomnames()
{
    // 1. 打开数据库
    if(SingleTon<SqlDaoDb>::getReference().open()
            == false) return;
    QString roomname;
    if(!this->roomnames.isEmpty())this->roomnames.clear();
    QSqlQuery query;
    query.exec("select *from tb_usroom;");
    while(query.next()){
        roomname=query.value("roomname").toString();
        this->roomnames.push_back(roomname);
    }
}

void SqlDao::setRooms()
{
    if(SingleTon<SqlDaoDb>::getReference().open()==false)return;
    if(!this->rooms.isEmpty())this->rooms.clear();
    QString roomname,roomusername;
    QSqlQuery query;
    query.exec("select * from tb_usroom;");
    while(query.next()){
        roomname=query.value("roomname").toString();
        roomusername=query.value("roomusername").toString();
        this->rooms.insert(roomname,roomusername);
    }

}
