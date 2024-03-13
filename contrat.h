#ifndef CONTRAT_H
#define CONTRAT_H
#include<QString>
#include<QDate>
#include <QSqlQueryModel>
#include <QPieSeries>
#include <QPieSlice>
#include <QChart>
#include <QChartView>
#include <QtCharts>
class contrat
{
private:
   int ref_contrat;
   QString title,description,type,transaction;
   QDate DateDebut,DateFin;
   double budget;
public:
    contrat();
    contrat(QString title,QString description,QString type,QDate dateDebut,QDate dateFin,QString transaction,double budget);
    contrat(int ref_contrat,QString title,QString description,QString type,QDate dateDebut,QDate dateFin,QString transaction,double budget);
    QString gettitle();
    QString getdescription();
    QString gettype();
    QDate getDateDebut();
    QDate getDateFin();
    QString gettransaction();
    double getbudget();

    void settitle(QString);
    void setdescription(QString);
    void settype(QString);
    void setDateDebut(QDate);
    void setDateFin(QDate);
    void settransaction(QString);
    void setbudget(double);
    bool ajouter_Contrat();
    QSqlQueryModel* afficher_Contrat();
    bool modif_Contrat();
    bool supprimer_Contrat(int ref_contrat);
    QMap<QString, int> getContractTypeStatistics();
    QMap<QString, int> getContractGainStatistics();
};
#endif // CONTRAT_H
