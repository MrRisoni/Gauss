#ifndef ADDNEWDIPLOMADIALOG_H
#define ADDNEWDIPLOMADIALOG_H

#include <QDialog>

namespace Ui {
class AddNewDiplomaDialog;
}

class AddNewDiplomaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewDiplomaDialog(QWidget *parent = 0);
    ~AddNewDiplomaDialog();

private slots:
    void on_pushSave_clicked();

private:
    Ui::AddNewDiplomaDialog *ui;
};

#endif // ADDNEWDIPLOMADIALOG_H
