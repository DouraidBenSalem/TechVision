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
    ui->widget->tabBar()->setTabEnabled(0, false);

    // Set the second tab as the default selected tab
    ui->widget->setCurrentIndex(2);


    // Connect the clicked signals of PB1 to PB5 to the selectSecondTab slot
   /* connect(ui->PB1, &QPushButton::clicked, this, &file1::selectSecondTab);
    connect(ui->PB2, &QPushButton::clicked, this, &file1::selectSecondTab);
    connect(ui->PB3, &QPushButton::clicked, this, &file1::selectSecondTab);
    connect(ui->PB4, &QPushButton::clicked, this, &file1::selectSecondTab);
    connect(ui->PB5, &QPushButton::clicked, this, &file1::selectSecondTab);*/

    ui->PB1->setFocus();
}

file1::~file1()
{
    delete ui;
}

// Implement the selectSecondTab slot
void file1::selectSecondTab()
{
    ui->widget->setCurrentIndex(2);
}
