#ifndef EMPLOYES_H
#define EMPLOYES_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QImage>

class employes
{
    int idemploye;
    QString nom;
    QString prenom;
    QDate date_naissance;
    QImage photo_profile;
    QString email;
    int telephone;
    QString genre;
    QDate date_embauche;
    float salaire;
    QString role;


public:
    employes();
    employes(int, QString, QString, QDate, QImage, QString, int, QString, QDate, float, QString);

    void setNom(QString);
    void setPrenom(QString);
    void setDateNaissance(QDate);
    void setPhotoProfile(QImage);
    void setEmail(QString);
    void setTelephone(int);
    void setGenre(QString);
    void setDateEmbauche(QDate);
    void setSalaire(float);
    void setRole(QString);

    int getIdEmploye();
    QString getNom();
    QString getPrenom();
    QDate getDateNaissance();
    QImage getPhotoProfile();
    QString getEmail();
    int getTelephone();
    QString getGenre();
    QDate getDateEmbauche();
    float getSalaire();
    QString getRole();
};

#endif // EMPLOYES_H
