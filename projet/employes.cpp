#include "employes.h"

#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QImage>

employes::employes()
{
    nom = "";
    prenom = "";
    date_naissance = QDate(2000, 1, 1);
    photo_profile = QImage();
    email = "";
    telephone = 00000000;
    genre = "";
    date_embauche = QDate(2000, 1, 1);
    salaire = 0;
    role = "";

}

employes::employes(int id, QString n, QString p, QDate dn, QImage pp, QString e, int tel, QString g, QDate de, float sal, QString r)
    : idemploye(id), nom(n), prenom(p), date_naissance(dn), photo_profile(pp), email(e), telephone(tel), genre(g), date_embauche(de), salaire(sal), role(r)
{
    // Constructor with parameters to initialize member variables
}

void employes::setNom(QString n)
{
    nom = n;
}

void employes::setPrenom(QString p)
{
    prenom = p;
}

void employes::setDateNaissance(QDate dn)
{
    date_naissance = dn;
}

void employes::setPhotoProfile(QImage pp)
{
    photo_profile = pp;
}

void employes::setEmail(QString e)
{
    email = e;
}

void employes::setTelephone(int tel)
{
    telephone = tel;
}

void employes::setGenre(QString g)
{
    genre = g;
}

void employes::setDateEmbauche(QDate de)
{
    date_embauche = de;
}

void employes::setSalaire(float sal)
{
    salaire = sal;
}

void employes::setRole(QString r)
{
    role = r;
}

int employes::getIdEmploye()
{
    return idemploye;
}

QString employes::getNom()
{
    return nom;
}

QString employes::getPrenom()
{
    return prenom;
}

QDate employes::getDateNaissance()
{
    return date_naissance;
}

QImage employes::getPhotoProfile()
{
    return photo_profile;
}

QString employes::getEmail()
{
    return email;
}

int employes::getTelephone()
{
    return telephone;
}

QString employes::getGenre()
{
    return genre;
}

QDate employes::getDateEmbauche()
{
    return date_embauche;
}

float employes::getSalaire()
{
    return salaire;
}

QString employes::getRole()
{
    return role;
}

