#include "file1.h"
#include "ui_file1.h"
#include <QPixmap>
#include<QIcon>
#include<QPushButton>
file1::file1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::file1)
{
    ui->setupUi(this);
   /* QPixmap pix(":/img/img/logo.png");
    int h=ui->logo_pic->width();
    int w=ui->logo_pic->height();
    ui->logo_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));*/
   /* ui->pushButton->setIcon(QIcon(":/img/img/utilisateur.png")); // Chemin vers l'icône FontAwesome

            // Définition de la taille de l'icône
    ui->pushButton->setIconSize(QSize(20, 20)); // Taille de l'icône*/
}

file1::~file1()
{
    delete ui;
}

