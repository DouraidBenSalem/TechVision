#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("PRJ");
    db.setUserName("username");
    db.setPassword("password");

    if (db.open())
        test=true;

    return test;
}
