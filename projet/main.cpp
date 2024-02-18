#include "file1.h"
#include "connection.h"
#include <QApplication>
#include <QPushButton>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    file1 w;

    Connection c;
    bool test=c.createconnect();
    if(!test){
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

    w.show();
    return a.exec();
}
