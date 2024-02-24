#ifndef application_H
#define application_H
#include <QMainWindow>
#include <QButtonGroup>
#include "equipement.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
QT_BEGIN_NAMESPACE
namespace Ui { class application; }
QT_END_NAMESPACE

class application : public QMainWindow
{
    Q_OBJECT

public:
    application(QWidget *parent = nullptr);
    ~application();

private slots:
    void on_PB0_clicked();
    void on_PB1_clicked();
    void on_PB2_clicked();
    void on_PB3_clicked();
    void on_PB4_clicked();
    void on_PB5_clicked();
    void on_ajouter_clicked();
    void update();

    void on_sup_but_clicked();

    void on_line_rech_textChanged(const QString &arg1);

    void on_ajouter_3_clicked();

    void on_ajouter_2_clicked();

private:
    Ui::application *ui;
};


#endif // application_H
