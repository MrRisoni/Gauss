#ifndef MANAGEDEPSDIALOG_H
#define MANAGEDEPSDIALOG_H

#include <QDialog>
#include "Entities/orm.h"


namespace Ui {
class ManageDepsDialog;
}

class ManageDepsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManageDepsDialog(QWidget *parent = 0);
    ~ManageDepsDialog();


private slots:
    void on_pushSaveDep_clicked();

private:
    Ui::ManageDepsDialog *ui;
    void populateTable();
};

#endif // MANAGEDEPSDIALOG_H
