#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class equipement
{
public:
    equipement();
    equipement(QString,QString,QString,QString,QString,QString,QString,QString);
    equipement(int,QString,QString,QString,QString,QString,QString,QString,QString);
    int get_ref(),get_emp();
    QString get_nom(),get_main(),get_cout();
    QString get_type(),getetat(),getdisp();
    QString getloc();
    QString get_dachat(),get_dmaint();
    QSqlQueryModel * afficher();
    bool ajouter();
    bool supprimer(int ref_equi);
    bool modif();
private:
    int ref_equi,id_emp;
    QString cout,nom,type,etat,disp,localisation;
    QString date_achat,date_maint;
};

#endif // EQUIPEMENT_H
