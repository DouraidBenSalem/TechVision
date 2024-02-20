#include "file1.h"
#include "ui_file1.h"
#include <QPixmap>
#include <QIcon>
#include <QPushButton>
#include <QDebug>

file1::file1(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::file1)
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

file1::~file1()
{
    delete ui;
}

void file1::on_PB0_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->PB0->setFocus();
}

void file1::on_PB1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->widget1->setCurrentIndex(2);
    ui->PB1->setFocus();
}

void file1::on_PB2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->widget2->setCurrentIndex(2);
    ui->PB2->setFocus();
}

void file1::on_PB3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->widget3->setCurrentIndex(2);
    ui->PB3->setFocus();
}

void file1::on_PB4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->widget4->setCurrentIndex(2);
    ui->PB4->setFocus();
}

void file1::on_PB5_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->widget5->setCurrentIndex(2);
    ui->PB5->setFocus();
}
