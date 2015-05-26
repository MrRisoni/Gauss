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

    int getReceiptType() const;
    void setReceiptType(int value);

private slots:
    void on_pushPrint_clicked();

private:
    Ui::CreateNewReceiptDialog *ui;
    int ReceiptType; // -1 give money to profs ,1 receive money from parents
};

#endif // CREATENEWRECEIPTDIALOG_H
