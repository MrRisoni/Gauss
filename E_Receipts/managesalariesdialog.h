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

    void on_pushAddSchuleScheme_clicked();

    void on_tableBase_doubleClicked(const QModelIndex &index);

    void on_tableSchule_doubleClicked(const QModelIndex &index);

    void on_tableUni_doubleClicked(const QModelIndex &index);

    void on_tableView_5_doubleClicked(const QModelIndex &index);

private:
    Ui::ManageSalariesDialog *ui;
    void populateEchelTable();
    void populateBaseTable();
    void populateSchuleTable();
};

#endif // MANAGESALARIESDIALOG_H
