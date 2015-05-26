#include "givemoneydialog.h"
#include "ui_givemoneydialog.h"

#include <QFile>

GiveMoneyDialog::GiveMoneyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GiveMoneyDialog)
{
    ui->setupUi(this);
}

GiveMoneyDialog::~GiveMoneyDialog()
{
    delete ui;
}

void GiveMoneyDialog::on_pushPrint_clicked()
{

    QPixmap pixmap(ui->globalFrame->size());
    ui->globalFrame->render(&pixmap);

    QFile file("/tmp/yourFile.png");
    file.open(QIODevice::WriteOnly);
    pixmap.save(&file, "PNG");

}
