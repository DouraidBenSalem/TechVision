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
    void update();
    void on_PB0_clicked();
    void on_PB1_clicked();
    void on_PB2_clicked();
    void on_PB3_clicked();
    void on_PB4_clicked();
    void on_PB5_clicked();
   bool checkIfIdExists(int id);
    void on_EMP_BM_clicked();

    void on_CNT_BM_clicked();

    void on_DIF_BM_clicked();

    void on_CNR_Modif_clicked();

    void on_EQU_BM_clicked();

    void on_CTR_ajout_clicked();

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_lineEdit_4_editingFinished();

    void on_CTR_modif_2_clicked();

    void on_CTR_supprimer_clicked();

    void on_Renitialiser_clicked();

<<<<<<< HEAD


    void showError(const QString &fieldName);
    void on_widget4_currentChanged(int index);
=======
    void on_CTR_annuler_clicked();
>>>>>>> 0f2cb5c9bf17c2bfae17bd6f7c809abad0d8fb73

    void on_pushButton_2_clicked();



    void on_lineEdit_4_editingFinished();

private:
    Ui::application *ui;
<<<<<<< HEAD
    void displayContractStatistics();
    void displayContractStatisticsGain();
    void createPieChartGain();
    QChartView *chartView;
        void createPieChart();
        bool animationEnabled;
=======

>>>>>>> 0f2cb5c9bf17c2bfae17bd6f7c809abad0d8fb73
};


#endif // application_H
