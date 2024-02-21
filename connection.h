#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlQuery>

class Connection
{
public:
    Connection();
    bool createconnect();
};

#endif // CONNECTION_H
