#ifndef ADDNEWREQUESTDIALOG_H
#define ADDNEWREQUESTDIALOG_H

#include <QDialog>

namespace Ui {
class AddNewRequestDialog;
}

class AddNewRequestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewRequestDialog(QWidget *parent = 0);
    ~AddNewRequestDialog();

private:
    Ui::AddNewRequestDialog *ui;
};

#endif // ADDNEWREQUESTDIALOG_H
