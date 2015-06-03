#include "showgroupsdialog.h"
#include "ui_showgroupsdialog.h"
#include <QMessageBox>
#include  "../mvc.h"
#include "../validator.h"
#include "Entities/orm.h"


ShowGroupsDialog::ShowGroupsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowGroupsDialog)
{
    ui->setupUi(this);

    ui->tableAllGroups->setModel(MVC::getGeneral_ShowGroup_Model());

    ui->tableAllGroups->resizeColumnsToContents();


    ORM o = ORM();

    for (Hours h : o.getHours()) {
        ui->comboStart->addItem(h.getName());
    }
}

ShowGroupsDialog::~ShowGroupsDialog()
{
    delete ui->tableAllGroups->model();
    delete ui;
}

void ShowGroupsDialog::on_pushCancel_clicked()
{

    QList<QString> dats;
    for (QListWidgetItem* it : ui->listFutureDates->selectedItems()) {
        dats.append(it->text());
    }

    ORM o = ORM ();

    o.CancelLesson( group_id,dats) ;

    qDebug () << "example for empty form validation";
}

void ShowGroupsDialog::on_tableAllGroups_doubleClicked(const QModelIndex &index)
{
    //get group id , teacher name , course name
    QAbstractItemModel* model =  ui->tableAllGroups->model();

    QModelIndex group_index =  model->index(index.row(), 0);
    QModelIndex teacher_index = model->index(index.row(), 1);
    QModelIndex course_index =  model->index(index.row(), 4);

    qDebug() << "clicked on " << index.row() << " " << index.column();


    qDebug() << " groupid " << ui->tableAllGroups->model()->data(group_index).toString();
    qDebug() << " Course Name " << ui->tableAllGroups->model()->data(teacher_index).toString();
    qDebug() << " Teacher Name " << ui->tableAllGroups->model()->data(course_index).toString();

    QString tmp=ui->tableAllGroups->model()->data(group_index).toString();
    tmp+= " " + ui->tableAllGroups->model()->data(teacher_index).toString();
    tmp+= " " + ui->tableAllGroups->model()->data(course_index).toString();



    group_id= ui->tableAllGroups->model()->data(group_index).toString();
    ui->labelSelectedDetails->setText(tmp);


    ui->tablePastLessons->setModel(MVC::getGeneral_ShowPastHistory(group_id));
    ui->tablePastLessons->resizeColumnsToContents();



    ui->listFutureDates->clear();
    for (QListWidgetItem *it : MVC::getGeneral_ShowFutureHistoryDates(group_id) ) {
            ui->listFutureDates->addItem(it);

    }

}

void ShowGroupsDialog::on_pushAddTempo_clicked()
{


    Validator Val= Validator();
    if (Val.ValidateFields(this->findChildren<QLineEdit*>())==false) {
        QMessageBox msgBox;
        msgBox.setText("Some fields are empty");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setIcon( QMessageBox::Critical);

        int ret = msgBox.exec();
    }

    qDebug() << "go on ";

    ORM o = ORM();
    o.AddTempLesson(group_id,ui->calendarTempo->selectedDate(),ui->comboStart->currentText(),ui->lineDuration->text().toFloat());

}
