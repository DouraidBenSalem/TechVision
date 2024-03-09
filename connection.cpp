#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("PRJ");
    db.setUserName("system");
    db.setPassword("azerty123");

    if (db.open())
        test=true;

    return test;
}
