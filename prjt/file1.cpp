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
}

file1::~file1()
{
    delete ui;
}

