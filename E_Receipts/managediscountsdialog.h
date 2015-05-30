#ifndef MANAGEDISCOUNTSDIALOG_H
#define MANAGEDISCOUNTSDIALOG_H

#include <QDialog>

namespace Ui {
class ManageDiscountsDialog;
}

class ManageDiscountsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManageDiscountsDialog(QWidget *parent = 0);
    ~ManageDiscountsDialog();

private:
    Ui::ManageDiscountsDialog *ui;
};

#endif // MANAGEDISCOUNTSDIALOG_H
