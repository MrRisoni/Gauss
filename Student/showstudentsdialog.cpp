#include "showstudentsdialog.h"
#include "ui_showstudentsdialog.h"
#include <QDebug>
#include "../mvc.h"


ShowStudentsDialog::ShowStudentsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowStudentsDialog)
{
    ui->setupUi(this);

    ui->tableView->setModel(MVC::getGeneral_ShowStudents_Model());
    ui->tableView->resizeColumnsToContents();
    qDebug() << "show all studentssss";

}

ShowStudentsDialog::~ShowStudentsDialog()
{
    delete ui;
}
