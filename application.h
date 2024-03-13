#ifndef application_H
#define application_H

#include <QMainWindow>
#include <QButtonGroup>
#include<QtCharts>
#include <QChart>
#include <QChartView>
#include <QtCharts/QChartView>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

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

   void supprimerLigne(const QModelIndex &index) ;

    void on_CTR_ajout_3_clicked();

    void on_CTR_ajout_4_clicked();

    void on_CNR_Modif_2_clicked();

    void retrieveContractData();



    void showError(const QString &fieldName);
    void on_widget4_currentChanged(int index);





    void on_lineEdit_4_editingFinished();

    void on_CNR_Recherche_textChanged(const QString &arg1);

    void on_CTR_Renitialiser_clicked();

private:
    Ui::application *ui;
    void displayContractStatistics();
    void displayContractStatisticsGain();
    void createPieChartGain();
    QChartView *chartView;
        void createPieChart();
        bool animationEnabled;
};


#endif // application_H
