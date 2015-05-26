#ifndef RECEIPTVIEWERDIALOG_H
#define RECEIPTVIEWERDIALOG_H

#include <QDialog>

namespace Ui {
class ReceiptViewerDialog;
}

class ReceiptViewerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReceiptViewerDialog(QWidget *parent = 0);
    ~ReceiptViewerDialog();

private:
    Ui::ReceiptViewerDialog *ui;
};

#endif // RECEIPTVIEWERDIALOG_H
