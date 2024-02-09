#ifndef FILE1_H
#define FILE1_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class file1; }
QT_END_NAMESPACE

class file1 : public QMainWindow
{
    Q_OBJECT

public:
    file1(QWidget *parent = nullptr);
    ~file1();

private:
    Ui::file1 *ui;
};
#endif // FILE1_H
