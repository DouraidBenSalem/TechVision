#include "contrat.h"
#include<QString>
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
#include <QMap>
#include <QSqlQueryModel>
contrat::contrat()
{
  title="";description="";type="";transaction="";budget=0.0;transaction="";
}
contrat::contrat(QString title,QString description,QString type,QDate DateDebut,QDate DateFin,QString transaction,double budget){

    this->title=title;
    this->description=description;
    this->type=type;
    this->DateDebut=DateDebut;
    this->DateFin=DateFin;
    this->transaction=transaction;
    this->budget=budget;
}
contrat::contrat(int ref_contrat,QString title,QString description,QString type,QDate DateDebut,QDate DateFin,QString transaction,double budget){
    this->ref_contrat=ref_contrat;
    this->title=title;
    this->description=description;
    this->type=type;
    this->DateDebut=DateDebut;
    this->DateFin=DateFin;
    this->transaction=transaction;
    this->budget=budget;
}

QString contrat::gettitle(){
    return title;
}
QString contrat::getdescription(){
    return description;
}
QString contrat::gettype(){
    return type;
}
QDate contrat::getDateDebut(){
    return DateDebut;
}
QDate contrat::getDateFin(){
    return DateFin;
}
QString contrat::gettransaction(){
    return transaction;
}
double contrat::getbudget(){
    return budget;
}

void contrat::settitle(QString title){
    this->title=title;
}
void contrat::setdescription(QString description){
    this->description=description;
}
void contrat::settype(QString type){
    this->type=type;
}
void contrat::setDateDebut(QDate DateDebut){
    this->DateDebut=DateDebut;
}
void contrat::setDateFin(QDate DateFin){
    this->DateFin=DateFin;
}
void contrat::settransaction(QString transaction){
    this->transaction=transaction;
}
void contrat::setbudget(double budget){
    this->budget=budget;
}
bool contrat::ajouter_Contrat(){

     QSqlQuery query;
           query.prepare("INSERT INTO CONTRATS (TITRE,DESCRIPTION,TYPE,DATE_DEBUT,DATE_FIN,TRANSACTION,BUDGET) "
                         "VALUES ( :title, :description, :type, :datedebut, :datefin, :transaction, :budget)");

           query.bindValue(":title", title);
           query.bindValue(":description", description);
           query.bindValue(":type", type);
           query.bindValue(":datedebut", DateDebut);
           query.bindValue(":datefin", DateFin);
           query.bindValue(":transaction", transaction);
           query.bindValue(":budget", budget);
           return query.exec();

}
QSqlQueryModel* contrat::afficher_Contrat(){
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CONTRATS");
    return model;
}

bool contrat::modif_Contrat(){
    QSqlQuery query;
    query.prepare("UPDATE CONTRATS SET   TITRE= :title, DESCRIPTION = :description, TYPE = :type, DATE_DEBUT = :datedebut, DATE_FIN= :datefin,TRANSACTION= :transaction, BUDGET= :budget WHERE REFCONTRAT = :id");
    query.bindValue(":id",ref_contrat);
    query.bindValue(":title", title);
    query.bindValue(":description", description);
    query.bindValue(":type", type);
    query.bindValue(":datedebut", DateDebut);
    query.bindValue(":datefin", DateFin);
    query.bindValue(":transaction", transaction);
    query.bindValue(":budget", budget);
    return query.exec();
}
bool contrat::supprimer_Contrat(int ref_contrat){
    QSqlQuery query;
    query.prepare("Delete from CONTRATS where REFCONTRAT=:id");
    query.bindValue(":id",ref_contrat);
    return query.exec();
}
QMap<QString, int> contrat::getContractTypeStatistics() {
    QMap<QString, int> statistics;

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) AS count FROM CONTRATS WHERE TYPE = 'Programme'");
    if (query.exec() && query.next()) {
        statistics["Programme"] = query.value("count").toInt();
    }

    query.prepare("SELECT COUNT(*) AS count FROM CONTRATS WHERE TYPE = 'Publicite'");
    if (query.exec() && query.next()) {
        statistics["Publicite"] = query.value("count").toInt();
    }

    // Add more queries for other contract types as needed

    return statistics;
}
QMap<QString, int> contrat::getContractGainStatistics() {
    QMap<QString, int> statistics;

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) AS count FROM CONTRATS WHERE TRANSACTION = '+'");
    if (query.exec() && query.next()) {
        statistics["+"] = query.value("count").toInt();
    }

    query.prepare("SELECT COUNT(*) AS count FROM CONTRATS WHERE TRANSACTION = '-'");
    if (query.exec() && query.next()) {
        statistics["-"] = query.value("count").toInt();
    }

    // Add more queries for other contract types as needed

    return statistics;
}
