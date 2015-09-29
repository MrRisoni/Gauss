#ifndef ADDNEWTEACHERDIALOG_H
#define ADDNEWTEACHERDIALOG_H

#include <QDialog>
#include <QStandardItemModel>
#include <QListWidgetItem>
#include <QListWidgetItem>
#include <QModelIndexList>
#include <QBuffer>

namespace Ui {
class AddNewTeacherDialog;
}

class AddNewTeacherDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewTeacherDialog(QWidget *parent = 0);
    ~AddNewTeacherDialog();


private slots:
    void on_comboDeps_currentTextChanged(const QString &arg1);


    void on_listAllCourses_itemDoubleClicked(QListWidgetItem *item);

    void on_pushSaveTeacher_clicked();

    void on_pushLoadPic_clicked();

    void on_pushESymvasis_clicked();

    void on_pushLoadPic_2_clicked();

    void on_comboSprachen_activated(const QString &arg1);

    void on_listAllDiplomas_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::AddNewTeacherDialog *ui;
    QStandardItemModel *coursesModel;
    int row=0; //row for can teach courses model
};

#endif // ADDNEWTEACHERDIALOG_H
