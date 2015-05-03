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

private:
    Ui::AddNewDiplomaDialog *ui;
};

#endif // ADDNEWDIPLOMADIALOG_H
