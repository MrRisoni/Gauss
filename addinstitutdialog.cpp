#include "addinstitutdialog.h"
#include "ui_addinstitutdialog.h"



#include "Entities/orm.h"
#include <QStandardItemModel>


AddInstitutDialog::AddInstitutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddInstitutDialog)
{
    ui->setupUi(this);


    ORM o=ORM();
    AddInstitutDialogMVC mvc=o.getAddInstitutMVC();

    QStandardItemModel *model=new QStandardItemModel();


    model->setHorizontalHeaderLabels(mvc.headers);

    int r=0;
    for (InstitutModel view : mvc.InstitutView) {

        QStandardItem *itID = new QStandardItem();
        itID->setText(view.InstitID);
        model->setItem(r,0,itID);

        QStandardItem *itName = new QStandardItem();
        itName->setText(view.InsName);
        model->setItem(r,1,itName);

        QStandardItem *itDiplomas = new QStandardItem();
        itDiplomas->setText(view.NumDiplomas);
        model->setItem(r,2,itDiplomas);

        QStandardItem *itTeachers = new QStandardItem();
        itTeachers->setText(view.NumTeachers);
        model->setItem(r,3,itTeachers);

        QStandardItem *itStudents = new QStandardItem();
        itStudents->setText(view.NumStudents);
        model->setItem(r,4,itStudents);


        QStandardItem *itGroups = new QStandardItem();
        itGroups->setText(view.NumGroups);
        model->setItem(r,5,itGroups);



        //add a combo box
        QStandardItem *itDiploCombo = new QStandardItem();
        itDiploCombo->setText(view.NumGroups);
        model->setItem(r,6,itDiploCombo);

        r++;
    }

    ui->tableInstituts->setModel(model);
    ui->tableInstituts->resizeColumnsToContents();
}

AddInstitutDialog::~AddInstitutDialog()
{
    QAbstractItemModel *mod=ui->tableInstituts->model();
    delete mod;
    delete ui;
}






