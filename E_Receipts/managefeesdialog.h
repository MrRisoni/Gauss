#ifndef MANAGEFEESDIALOG_H
#define MANAGEFEESDIALOG_H

#include <QDialog>

namespace Ui {
class ManageFeesDialog;
}

class ManageFeesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManageFeesDialog(QWidget *parent = 0);
    ~ManageFeesDialog();

private slots:
    void on_pushSaveSchuleFee_clicked();

private:
    Ui::ManageFeesDialog *ui;
    void populateTable();
};

#endif // MANAGEFEESDIALOG_H