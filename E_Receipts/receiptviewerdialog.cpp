#include "receiptviewerdialog.h"
#include "ui_receiptviewerdialog.h"

ReceiptViewerDialog::ReceiptViewerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReceiptViewerDialog)
{
    ui->setupUi(this);
}

ReceiptViewerDialog::~ReceiptViewerDialog()
{
    delete ui;
}
