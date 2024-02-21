#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("PRJ");
    db.setUserName("fares");
    db.setPassword("123f");

    if (db.open())
        test=true;

    return test;
}
