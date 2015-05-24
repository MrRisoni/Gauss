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


    QStandardItemModel *kassenModel = new QStandardItemModel();

    ORM O=ORM();
    KassenMVC mvc= O.getKassenMVC();
    kassenModel->setHorizontalHeaderLabels(mvc.headers);

    int row=0;
    for (KasseModel K : mvc.KasseView) {
        QStandardItem *itID = new QStandardItem();
        itID->setText(K.ID);
        kassenModel->setItem(row,0,itID);

        QStandardItem *itKasse = new QStandardItem();
        itKasse->setText(K.Name);
        kassenModel->setItem(row,1,itKasse);

        QStandardItem *itTeachers = new QStandardItem();
        itTeachers->setText(K.NumTeachers);
        kassenModel->setItem(row,2,itTeachers);

        QStandardItem *itPays = new QStandardItem();
        itPays->setText(K.Pays);
        kassenModel->setItem(row,3,itPays);

        QStandardItem *itDebt= new QStandardItem();
        itDebt->setText(K.Debt);
        kassenModel->setItem(row,4,itDebt);


        row++;
    }




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
