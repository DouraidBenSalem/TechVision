#include "application.h"
#include "ui_application.h"
#include "contrat.h"
#include <QVBoxLayout>
#include <QPixmap>
#include <QIcon>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QTabWidget>
#include <QMap>
#include<QSqlError>
#include <QSqlQuery>
#include <QPieSlice>



application::application(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::application),animationEnabled(false)
{
     createPieChart();


    ui->setupUi(this);
    ui->tab_Contrat->verticalHeader()->setVisible(false);
    ui->tab_Contrat->viewport()->update();


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

void application::update(){
    contrat C;
    ui->tab_Contrat->setModel(C.afficher_Contrat());
    ui->tab_Contrat->resizeColumnsToContents();

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

    ui->CNR_Aff->setCurrentIndex(2);
    ui->PB4->setFocus();
    update();


}

void application::on_PB5_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->widget5->setCurrentIndex(2);
    ui->PB5->setFocus();
}

void application::on_EMP_BM_clicked()
{
    ui->EMP_Aff->setCurrentIndex(1);
    ui->PB1->setFocus();
}

void application::on_CNT_BM_clicked()
{
    ui->CNT_Aff->setCurrentIndex(1);
    ui->PB2->setFocus();
}

void application::on_DIF_BM_clicked()
{
    ui->DIF_Aff->setCurrentIndex(1);
    ui->PB3->setFocus();
}

void application::on_CNR_Modif_clicked()
{

    ui->PB4->setFocus();
    QModelIndex index = ui->tab_Contrat->selectionModel()->currentIndex();

    // Vérifiez si un élément est sélectionné
    if (index.isValid()) {
        // Récupérez l'ID ou l'indice de la ligne sélectionnée
        int row = index.row();
        // Supposez que row est l'indice de la ligne sélectionnée dans votre tableau
        int ref_contrat = ui->tab_Contrat->model()->data(ui->tab_Contrat->model()->index(row, 0)).toInt();
        QString title = ui->tab_Contrat->model()->data(ui->tab_Contrat->model()->index(row, 1)).toString();
        QString description = ui->tab_Contrat->model()->data(ui->tab_Contrat->model()->index(row, 2)).toString();
        QString type = ui->tab_Contrat->model()->data(ui->tab_Contrat->model()->index(row, 3)).toString();
        QDate dateDebut = ui->tab_Contrat->model()->data(ui->tab_Contrat->model()->index(row, 4)).toDate();
        QDate dateFin = ui->tab_Contrat->model()->data(ui->tab_Contrat->model()->index(row, 5)).toDate();
        QString transaction = ui->tab_Contrat->model()->data(ui->tab_Contrat->model()->index(row, 6)).toString();
        double budget = ui->tab_Contrat->model()->data(ui->tab_Contrat->model()->index(row, 7)).toDouble();


        ui->CNR_Aff->setCurrentIndex(1);
        contrat C(ref_contrat,title,description,type,dateDebut,dateFin,transaction,budget);
        QString budgetString = QString::number(budget);
        QString refString = QString::number(ref_contrat);
        ui->lineEdit_3->setText(refString);
        ui->lineEdit->setText(title);
        ui->CTR_description_3->setText(description);
        int index = ui->CTR_type_2->findText(type);
        if (index != -1) {
            ui->CTR_type_2->setCurrentIndex(index);
        }
        ui->CTR_DD_3->setDate(dateDebut);
        ui->CTR_DF_3->setDate(dateFin);
        // Assuming transaction is a QString indicating the state of the checkbox
        if (transaction == "+") {
            ui->CTR_checkBox_5->setChecked(true); // Assuming checkBox is the correct pointer to your QCheckBox widget
        } else {
            ui->CTR_checkBox_5->setChecked(false);
        }
        if (transaction == "-") {
            ui->CTR_checkBox_6->setChecked(true); // Assuming checkBox is the correct pointer to your QCheckBox widget
        } else {
            ui->CTR_checkBox_6->setChecked(false);
        }

        ui->lineEdit_2->setText(budgetString);

    } else {
        // Aucune ligne sélectionnée, affichez un message d'erreur ou avertissement si nécessaire
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une ligne à modifier.");
    }
}

void application::on_EQU_BM_clicked()
{
    ui->EQU_Aff->setCurrentIndex(1);
    ui->PB5->setFocus();
}

void showMessage(const QString &title, const QString &message, QWidget *parent = nullptr) {
    QMessageBox msgBox(parent);
    msgBox.setWindowTitle(title);
    msgBox.setText(message);
    msgBox.setWindowFlags(Qt::FramelessWindowHint);

    // Apply basic styles for debugging
     msgBox.setStyleSheet("QMessageBox { background-color: #65a6fa; color: white; border"
                          " }"
                          "QMessageBox QLabel { color: white; font-family: 'Montserrat', sans-serif;font-weight: bold; }"
                                                   "QMessageBox QFrame { border: none; background-color:#65a6fa }"
                                               "QPushButton { background-color: #1e90ff; color: white; border: none; padding: 5px 10px; }"
                                               "QPushButton:hover { background-color: #0e70ff; }");

    msgBox.exec();
}

void application::on_CTR_ajout_clicked() {
    // Vérifiez si les champs sont vides
    if (ui->CTR_titre->text().isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez remplir le champ 'Titre'.");

        return;
    }
    if (ui->CTR_description->toPlainText().isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez remplir le champ 'Description'.");

        return;
    }
    if (ui->CTR_type->currentText().isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez sélectionner un 'Type'.");

        return;
    }
    if (!ui->CTR_checkBox->isChecked() && !ui->CTR_checkBox_2->isChecked()) {
            showMessage("Erreur d'ajout", "Au moins une des cases à cocher doit être cochée.", this);
            return;
        }
    if (ui->CTR_Budget->text().isEmpty()) {
            showMessage("Erreur d'ajout", "Veuillez Entrer Un Budget", this);
            return;
        }
    // Vérifiez les autres champs si nécessaire

    // Si tous les champs sont remplis, continuez avec l'ajout
    QString title = ui->CTR_titre->text();
    QString description = ui->CTR_description->toPlainText();
    QString type = ui->CTR_type->currentText();
    QDate DateDebut = ui->CTR_DD->date();
    QDate DateFin = ui->CTR_DF->date();
    QString transaction;
    if (ui->CTR_checkBox->isChecked()) {
        transaction = ui->CTR_checkBox->text();
    } else if (ui->CTR_checkBox_2->isChecked()) {
        transaction = ui->CTR_checkBox_2->text();
    }
    double budget = ui->CTR_Budget->text().toDouble();
    contrat C(title, description, type, DateDebut, DateFin, transaction, budget);
    if (C.ajouter_Contrat()) {
        // La fonction ajouter a réussi
        showMessage("Ajout réussi", "Contrat a été ajouté avec succès.", this);
        ui->widget4->setCurrentIndex(2);
        update();
    } else {
        // La fonction ajouter a échoué
        showMessage("Erreur d'ajout", "Erreur lors de l'ajout de Contrat.", this);
    }
}
void application::showError(const QString &fieldName) {
    // Affichez un message d'erreur dans la console ou dans une zone de texte dédiée
    qDebug() << "Le champ" << fieldName << "n'est pas rempli !";

    // Changez la couleur du texte ou du fond du widget correspondant pour indiquer l'erreur
    if (fieldName == "Title") {
        ui->CTR_titre->setStyleSheet("color: red");
    } else if (fieldName == "Description") {
        ui->CTR_description->setStyleSheet("color: red");
    } else if (fieldName == "Type") {
        ui->CTR_type->setStyleSheet("color: red");
    }
    // Ajoutez d'autres champs si nécessaire
}


void application::on_CTR_ajout_3_clicked()
{
    int ref_contrat = ui->lineEdit_3->text().toInt();
    QString title = ui->lineEdit->text();
    QString description = ui->CTR_description_3->toPlainText();
    QString type = ui->CTR_type_2->currentText();
    QDate DateDebut = ui->CTR_DD_3->date();
    QDate DateFin = ui->CTR_DF_3->date();
    QString transaction;
    if (ui->CTR_checkBox_5->isChecked()){
        transaction = ui->CTR_checkBox_5->text();
    }
    else if (ui->CTR_checkBox_6->isChecked()){
         transaction = ui->CTR_checkBox_6->text();
    }
    double budget = ui->lineEdit_2->text().toDouble();
    contrat C(ref_contrat,title,description,type,DateDebut,DateFin,transaction,budget);
    if (C.modif_Contrat()) {
            // La fonction ajouter a réussi

            QMessageBox::information(this, "Modification réussi", "Contrat a été modifié avec succès.");
            update();
            ui->CNR_Aff->setCurrentIndex(0);

        } else {
            // La fonction ajouter a échoué
            QMessageBox::critical(this, "Erreur de modifier", "Erreur lors de modifier de Contrat.");
        }
}

void application::on_CTR_ajout_4_clicked()
{
    ui->CNR_Aff->setCurrentIndex(0);
}
void application::supprimerLigne(const QModelIndex &index) {
    // Vérifiez si un élément est sélectionné
    if (index.isValid()) {
        // Afficher une boîte de dialogue de confirmation
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer cette ligne?",
                                      QMessageBox::Yes|QMessageBox::No);
        // Si l'utilisateur confirme la suppression, procédez à la suppression
        if (reply == QMessageBox::Yes) {
            // Récupérez l'ID ou l'indice de la ligne sélectionnée
            int row = index.row();

            // Récupérez le modèle de données de votre QTableView
            QAbstractItemModel *model = ui->tab_Contrat->model();

            // Vérifiez que le modèle est valide
            if (model) {
                // Récupérez les données de cette ligne depuis votre modèle de données
                QVariant data = model->data(model->index(row, 0));

                // Utilisez ces données pour construire votre requête de suppression
                int ref_contrat = data.toInt();
                QString refString =QString::number(ref_contrat);
                ui->CNR_line_supp->setText(refString);
                // Supposons que l'ID est de type int



                // Exécutez la requête de suppression

            }
        }
    }
}
void application::on_CNR_Modif_2_clicked()
{
    int ref_contrat = ui->CNR_line_supp->text().toInt();
    QModelIndex index = ui->tab_Contrat->selectionModel()->currentIndex();
    contrat c;
    if (checkIfIdExists(ui->CNR_line_supp->text().toInt())){
             c.supprimer_Contrat(ref_contrat);
    //if (index.isValid()) {
        // Récupérez l'ID ou l'indice de la ligne sélectionnée
        //int row = index.row();
        //int ref_contrat = ui->tab_Contrat->model()->data(ui->tab_Contrat->model()->index(row, 0)).toInt();
    //if (c.supprimer(ref_contrat)){
         QMessageBox::information(this, "Suppression réussi", "Contrat a été supprimé avec succès.");
        update();}
   // }
    else {
        QMessageBox::critical(this, "Erreur de suppression", "Erreur lors de supprimer de contrat.");
    }
    //else {
            // Aucune ligne sélectionnée, affichez un message d'erreur ou avertissement si nécessaire
            //QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une ligne à modifier.");}

}


void application::displayContractStatistics(){
    contrat C;
    QMap<QString, int> statistics = C.getContractTypeStatistics();

       // Display statistics (e.g., in a message box)
       QString message = "Contract Statistics:\n";
       for (auto it = statistics.begin(); it != statistics.end(); ++it) {
           message += it.key() + ": " + QString::number(it.value()) + "\n";
       }

       QMessageBox::information(this, "Contract Statistics", message);
}
void application::createPieChart()
{
    // Create a pie series and populate it with data
    QPieSeries *series = new QPieSeries();
    series->append("Programme", 30);  // Example data
    series->append("Publicite", 20);  // Example data

    // Create a chart and add the pie series to it
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Contract Types Distribution");  // Chart title

    // Create a chart view and set the chart
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Set the chart view as the central widget
    setCentralWidget(chartView);
    QVBoxLayout *layout = new QVBoxLayout(ui->Aff_Contrat);
    layout->addWidget(chartView);
}



void application::retrieveContractData() {
    // Connectez-vous à votre base de données ici (assurez-vous que la connexion est déjà établie)

    // Préparez votre requête SQL pour récupérer les données des contrats
    QSqlQuery query;
    query.prepare("SELECT * FROM CONTRAT");

    // Exécutez la requête SQL
    if (query.exec()) {
        // Parcourez les résultats de la requête et traitez-les
        while (query.next()) {
            // Récupérez les valeurs des colonnes pour chaque contrat
            int ref_contrat = query.value("REFCONTRAT").toInt();
            QString title = query.value("TITLE").toString();
            QString description = query.value("DESCRIPTION").toString();
            QString type = query.value("TYPE").toString();
            QDate dateDebut = query.value("DATEDEBUT").toDate();
            QDate dateFin = query.value("DATEFIN").toDate();
            QString transaction = query.value("TRANSACTION").toString();
            double budget = query.value("BUDGET").toDouble();

            // Vous pouvez faire ce que vous voulez avec ces données
            // Par exemple, vous pouvez les stocker dans une liste ou les utiliser pour créer des objets contrat, etc.
        }
    } else {
        // Gérez les erreurs si la requête échoue
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
    }
}

void application::on_widget4_currentChanged(int index)
{
    if (index == 3 || ui->widget4->currentIndex() == 3) {
                   contrat C;
                   QMap<QString, int> statistics = C.getContractTypeStatistics();


                   QPieSeries *series = new QPieSeries();
                   double totalContracts = 0;

                   for (auto it = statistics.constBegin(); it != statistics.constEnd(); ++it) {
                       totalContracts += it.value();
                   }

                   for (auto it = statistics.constBegin(); it != statistics.constEnd(); ++it) {
                       double percentage = (it.value() / totalContracts) * 100.0 ;
                       QString label = QString("%1 (%2%)").arg(it.key()).arg(percentage, 0, 'f', 1);
                       series->append(label, it.value());
                   }

                   QChart *chart = new QChart();
                   chart->addSeries(series);
                   chart->setTitle("Contrat Types Distribution");


                   chart->setAnimationOptions(QChart::AllAnimations);

                   QChartView *chartView = new QChartView(chart);
                   chartView->setRenderHint(QPainter::Antialiasing);

                   QLayout *existingLayout = ui->Aff_Contrat->layout();
                           if (existingLayout) {
                               QLayoutItem *child;
                               while ((child = existingLayout->takeAt(0)) != nullptr) {
                                   delete child->widget();
                                   delete child;
                               }
                               delete existingLayout;
                           }


                   chartView->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
                   chartView->resize(300, 300);

                   QVBoxLayout *layout = new QVBoxLayout(ui->Aff_Contrat);
                   layout->addWidget(chartView);


                   animationEnabled = false;
               }
}
bool application::checkIfIdExists(int id) {
    // Query the database to check if the ID exists
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM CONTRATS WHERE REFCONTRAT = ?");
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }

    return false; // Error occurred or ID not found
}



void application::on_lineEdit_4_editingFinished()
{
    QString text = ui->CNR_line_supp->text();
        if (text.isEmpty()) {
            // Empty input, do nothing or show a message
            return;
        }

        bool idExists = checkIfIdExists(text.toInt());
        if (!idExists) {
            QMessageBox::warning(this, "ID Not Found", "The entered ID does not exist in the database.");
            // Optionally, clear the line edit or reset its contents here
        }
}

void application::on_CNR_Recherche_textChanged(const QString &arg1)
{
    QSqlQueryModel *model = new QSqlQueryModel();
     model->setQuery("SELECT REFCONTRAT, TITRE, DESCRIPTION, TYPE, DATE_DEBUT, DATE_FIN, TRANSACTION , BUDGET  FROM CONTRATS WHERE REFCONTRAT LIKE '%" + arg1 + "%' OR TITRE LIKE '%" + arg1 + "%' OR DESCRIPTION LIKE '%" + arg1 + "%' OR TYPE LIKE '%" + arg1 + "%' OR TRANSACTION LIKE '%" + arg1 + "%' OR BUDGET LIKE '%" + arg1 + "%'");
     ui->tab_Contrat->setModel(model);
}

void application::on_CTR_Renitialiser_clicked()
{
    ui->CTR_titre->clear();
    ui->CTR_description->clear();
    ui->CTR_checkBox->setChecked(false);
    ui->CTR_checkBox_2->setChecked(false);
    ui->CTR_Budget->clear();
    ui->CTR_DD->setDate(QDate::currentDate());
    ui->CTR_DF->setDate(QDate::currentDate());
    ui->CTR_type->setCurrentText(0);
}
