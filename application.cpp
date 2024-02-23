#include "application.h"
#include "equipement.h"
#include "ui_application.h"
#include <QPixmap>
#include <QIcon>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>

application::application(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::application)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    ui->widget1->tabBar()->setTabEnabled(0, false);
    ui->widget2->tabBar()->setTabEnabled(0, false);
    ui->widget3->tabBar()->setTabEnabled(0, false);
    ui->widget4->tabBar()->setTabEnabled(0, false);
    ui->widget5->tabBar()->setTabEnabled(0, false);

    ui->PB0->setFocus();
}

application::~application()
{
    delete ui;
}

void application::on_PB0_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->PB0->setFocus();
}

void application::on_PB1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->widget1->setCurrentIndex(2);
    ui->PB1->setFocus();
}

void application::on_PB2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->widget2->setCurrentIndex(2);
    ui->PB2->setFocus();
}

void application::on_PB3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->widget3->setCurrentIndex(2);
    ui->PB3->setFocus();
}

void application::on_PB4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->widget4->setCurrentIndex(2);
    ui->PB4->setFocus();
}

void application::on_PB5_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->widget5->setCurrentIndex(2);
    ui->PB5->setFocus();
}

void application::on_ajouter_clicked()
{
    QString cout=ui->edit_coutequi->text();
    QString nom=ui->edit_nomequi->text();
    QString type=ui->edit_typequip->text();
    QString datach=ui->dateEdit_achat->text();
    QString datmain=ui->dateEdit_main->text();
    QString disp=ui->edit_disp->text();
    QString loca=ui->edit_locali->text();
    QString etat=ui->edit_etat->text();
    equipement p(cout,nom,type,datach,datmain,etat,disp,loca);
    if(p.ajouter()){
        QMessageBox::information(this, "Ajout réussi", "ajout avec succès.");
    }
    else{
        QMessageBox::critical(this, "Erreur d'ajout", "Erreur lors de l'ajout");
    }


}
