#ifndef application_H
#define application_H

#include <QMainWindow>
#include <QButtonGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class application; }
QT_END_NAMESPACE

class application : public QMainWindow
{
    Q_OBJECT

public:
    application(QWidget *parent = nullptr);
    ~application();

private slots:
    void on_PB0_clicked();
    void on_PB1_clicked();
    void on_PB2_clicked();
    void on_PB3_clicked();
    void on_PB4_clicked();
    void on_PB5_clicked();

    void on_EMP_BM_clicked();

    void on_CNT_BM_clicked();

    void on_DIF_BM_clicked();

    void on_CNR_BM_clicked();

    void on_EQU_BM_clicked();

private:
    Ui::application *ui;
};


#endif // application_H
