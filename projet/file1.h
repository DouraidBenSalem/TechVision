#ifndef file1_H
#define file1_H

#include <QMainWindow>
#include <QButtonGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class file1; }
QT_END_NAMESPACE

class file1 : public QMainWindow
{
    Q_OBJECT

public:
    file1(QWidget *parent = nullptr);
    ~file1();

private slots:
    void on_PB0_clicked();
    void on_PB1_clicked();
    void on_PB2_clicked();
    void on_PB3_clicked();
    void on_PB4_clicked();
    void on_PB5_clicked();

private:
    Ui::file1 *ui;
};


#endif // file1_H
