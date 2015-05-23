#include "kassendialog.h"
#include "ui_kassendialog.h"


#include "Entities/orm.h"
#include <QStandardItem>
#include <QStandardItemModel>

KassenDialog::KassenDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KassenDialog)
{
    ui->setupUi(this);
    populateKassenTable();

}


void KassenDialog::populateKassenTable() {
    /*Show
     * Kasse name
     * #Techers
     * Money Spent
     */

    QStringList headers;
    headers.append("Kasse");
    headers.append("#Teachers");
    headers.append("Money");

    QStandardItemModel *kassenModel = new QStandardItemModel();

    kassenModel->setHorizontalHeaderLabels(headers);
    ui->tableKassen->setModel(kassenModel);
    ui->tableKassen->resizeColumnsToContents();
}


KassenDialog::~KassenDialog()
{
    delete ui;
}

void KassenDialog::on_pushSave_clicked()
{
    ORM o = ORM();
    Kassen K = Kassen();
    K.setName(ui->lineKasse->text());
    o.save(K);

}

void KassenDialog::on_tableKassen_doubleClicked(const QModelIndex &index)
{
    //show a diagram of how much we have payed wrt time
}
