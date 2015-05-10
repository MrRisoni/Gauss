#ifndef MANAGESALARIESDIALOG_H
#define MANAGESALARIESDIALOG_H

#include <QDialog>

namespace Ui {
class ManageSalariesDialog;
}

class ManageSalariesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManageSalariesDialog(QWidget *parent = 0);
    ~ManageSalariesDialog();

private slots:
    void on_pushNewEchel_clicked();

    void on_pushAddBaseScheme_clicked();

private:
    Ui::ManageSalariesDialog *ui;
    void populateEchelTable();
    void populateBaseTable();
};

#endif // MANAGESALARIESDIALOG_H
