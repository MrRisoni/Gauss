#include "createnewreceiptdialog.h"
#include "ui_createnewreceiptdialog.h"

CreateNewReceiptDialog::CreateNewReceiptDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateNewReceiptDialog)
{
    ui->setupUi(this);

}

CreateNewReceiptDialog::~CreateNewReceiptDialog()
{
    delete ui;
}
int CreateNewReceiptDialog::getReceiptType() const
{
    return ReceiptType;
}

void CreateNewReceiptDialog::setReceiptType(int value)
{
    ReceiptType = value;

    if (ReceiptType>0) {
        // we are getting money
        ui->labPayed->setVisible(false);
        ui->pliromiLabel->setVisible(false);


    }
    if (ReceiptType<0) {
        ui->labGotPayed->setVisible(false);
        ui->eispraxiLabel->setVisible(false);
    }
}


void CreateNewReceiptDialog::on_pushPrint_clicked()
{
    QPixmap pixmap(ui->globalFrame->size());
    ui->globalFrame->render(&pixmap);

    QFile file("/tmp/yourFile.png");
    file.open(QIODevice::WriteOnly);
    pixmap.save(&file, "PNG");
}
