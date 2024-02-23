#include "equipement.h"
#include <QString>
#include <QSqlQuery>
#include <QTableView>
equipement::equipement()
{

}
equipement::equipement(QString cout,QString nom,QString type,QString date_achat,QString date_maint,QString etat,QString disp,QString localisation)
{
    this->cout=cout;
    this->nom=nom;
    this->type=type;
    this->date_achat=date_achat;
    this->date_maint=date_maint;
    this->etat=etat;
    this->disp=disp;
    this->localisation=localisation;
}

int equipement::get_ref() {return ref_equi;}
QString equipement::get_cout(){return cout;}
QString equipement::get_nom(){return nom;}
QString equipement:: get_type(){return type;}
QString equipement::get_dachat(){return date_achat;}
QString equipement::get_dmaint(){return date_maint;}
int equipement::get_emp(){return id_emp;}
QString equipement::getetat(){return etat;}
QString equipement::getdisp(){return disp;}
QString equipement::getloc(){return localisation;}

bool equipement::ajouter()
{
    QSqlQuery query ;
    query.prepare("INSERT INTO EQUIPEMENTS(NOM,TYPE,COUT,DATE_ACHAT,DISPONIBILITE,ETAT,LOCALISATION,DATE_MAINTENANCE)"
                  "VALUES(:nom, :type, :cout, :dmain, :dachat, :loc, :etat, :disp)") ;
    query.bindValue(":nom", nom) ;
    query.bindValue(":type", type) ;
    query.bindValue(":cout", cout) ;
    query.bindValue(":dmain", date_maint) ;
    query.bindValue(":dachat", date_achat) ;
    query.bindValue(":loc", localisation) ;
    query.bindValue(":etat", etat) ;
    query.bindValue(":disp", disp) ;
    return  query.exec() ;

}



