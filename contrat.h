#ifndef CONTRAT_H
#define CONTRAT_H
#include<QString>
#include<QDate>
#include <QSqlQueryModel>

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
<<<<<<< HEAD
    bool ajouter_Contrat();
    QSqlQueryModel* afficher_Contrat();
    bool modif_Contrat();
    bool supprimer_Contrat(int ref_contrat);
    QMap<QString, int> getContractTypeStatistics();
    QMap<QString, int> getContractGainStatistics();
=======
    bool ajouter();
    QSqlQueryModel* afficher();
    bool modif();
    bool supprimer(int ref_contrat);

>>>>>>> 0f2cb5c9bf17c2bfae17bd6f7c809abad0d8fb73
};
#endif // CONTRAT_H
