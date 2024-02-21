#include "application.h"
#include "ui_application.h"
#include <QPixmap>
#include <QIcon>
#include <QPushButton>
#include <QDebug>

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

void application::on_CNR_BM_clicked()
{
    ui->CNR_Aff->setCurrentIndex(1);
    ui->PB4->setFocus();
}

void application::on_EQU_BM_clicked()
{
    ui->EQU_Aff->setCurrentIndex(1);
    ui->PB5->setFocus();
}
