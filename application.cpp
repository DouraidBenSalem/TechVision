#include "application.h"
#include "equipement.h"
#include "connection.h"
#include "ui_application.h"
#include <QPixmap>
#include <QIcon>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QTabWidget>
#include <QTableView>
application::application(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::application)
{
    ui->setupUi(this);
    ui->tableGue->verticalHeader()->setVisible(false);
    ui->stackedWidget->setCurrentIndex(0);
    ui->widget1->tabBar()->setTabEnabled(0, false);
    ui->widget2->tabBar()->setTabEnabled(0, false);
    ui->widget3->tabBar()->setTabEnabled(0, false);
    ui->widget4->tabBar()->setTabEnabled(0, false);
    ui->widget5->tabBar()->setTabEnabled(0, false);
    ui->PB0->setFocus();
    update();



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
    update();
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
        update();
    }
    else{
        QMessageBox::critical(this, "Erreur d'ajout", "Erreur lors de l'ajout");
    }
}
void application::update()
{
    equipement p;
    ui->tableGue->setModel(p.afficher());
    ui->tableGue->resizeColumnsToContents();
}
void application::on_sup_but_clicked()
{
    equipement p;
    int ref_equi = ui->line_id->text().toInt();
    if(p.supprimer(ref_equi)){
            QMessageBox::information(this, "suppresion réussi", "ajout avec succès.");
            update();
        }
        else{
            QMessageBox::critical(this, "Erreur d'ajout", "Erreur lors de l'ajout");
        }
}
void application::on_line_rech_textChanged(const QString &arg1)
{
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM EQUIPEMENTS WHERE NOM LIKE '%"+arg1+"%'");
     ui->tableGue->setModel(model);
}

void application::on_ajouter_3_clicked()
{
    QModelIndex index=ui->tableGue->selectionModel()->currentIndex();
    if(index.isValid()){
        int row=index.row();

        int ref_equi=ui->tableGue->model()->data(ui->tableGue->model()->index(row,0)).toInt();
        QString cout=ui->tableGue->model()->data(ui->tableGue->model()->index(row,3)).toString();
        QString nom=ui->tableGue->model()->data(ui->tableGue->model()->index(row,1)).toString();
        QString type=ui->tableGue->model()->data(ui->tableGue->model()->index(row,2)).toString();
        QString etat=ui->tableGue->model()->data(ui->tableGue->model()->index(row,6)).toString();
        QString disp=ui->tableGue->model()->data(ui->tableGue->model()->index(row,5)).toString();
        QString localisation=ui->tableGue->model()->data(ui->tableGue->model()->index(row,7)).toString();
        QString date_achat=ui->tableGue->model()->data(ui->tableGue->model()->index(row,4)).toString();
        QString date_maint=ui->tableGue->model()->data(ui->tableGue->model()->index(row,8)).toString();
        ui->widget5->setCurrentIndex(1);
        equipement p(ref_equi,cout,nom,type,date_achat,date_maint,etat,disp,localisation);
        QString refString = QString::number(ref_equi);
        QDate date_achatt= QDate::fromString(date_achat, "dd/MM/yyyy");
        QDate date_maintt= QDate::fromString(date_maint, "dd/MM/yyyy");
        ui->edit_nomequi->setText(nom);
        ui->edit_etat->setText(etat);
        ui->edit_locali->setText(localisation);
        ui->dateEdit_achat->setDate(date_achatt);
        ui->dateEdit_achat->setDate(date_maintt);
        ui->edit_typequip->setText(type);
        ui->edit_coutequi->setText(cout);
        ui->edit_disp->setText(disp);
        ui->lineEdit->setText(refString);
    }
    else {
        QMessageBox::warning(this,"Aucune selection","Veuillez sélectionner une ligne à modifier.");
    }

}

void application::on_ajouter_2_clicked()
{   int ref_equi = ui->lineEdit->text().toInt();
    QString cout=ui->edit_coutequi->text();
    QString nom=ui->edit_nomequi->text();
    QString type=ui->edit_typequip->text();
    QString datach=ui->dateEdit_achat->text();
    QString datmain=ui->dateEdit_main->text();
    QString disp=ui->edit_disp->text();
    QString loca=ui->edit_locali->text();
    QString etat=ui->edit_etat->text();
    equipement p(ref_equi,cout,nom,type,datach,datmain,etat,disp,loca);
    if(p.modif()){
        QMessageBox::information(this, " réussi", "Modification avec succès.");
        ui->widget5->setCurrentIndex(2);
        update();
    }
    else{
        QMessageBox::critical(this, "Erreur d'ajout", "Erreur lors de modification");
    }
}
