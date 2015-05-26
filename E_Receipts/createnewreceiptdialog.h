#ifndef CREATENEWRECEIPTDIALOG_H
#define CREATENEWRECEIPTDIALOG_H

#include <QDialog>

namespace Ui {
class CreateNewReceiptDialog;
}

class CreateNewReceiptDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateNewReceiptDialog(QWidget *parent = 0);
    ~CreateNewReceiptDialog();

private:
    Ui::CreateNewReceiptDialog *ui;
};

#endif // CREATENEWRECEIPTDIALOG_H
