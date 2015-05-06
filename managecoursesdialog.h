#ifndef MANAGECOURSESDIALOG_H
#define MANAGECOURSESDIALOG_H

#include <QDialog>
#include "Entities/orm.h"
#include "Entities/courses.h"
#include <QDebug>


namespace Ui {
class ManageCoursesDialog;
}

class ManageCoursesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManageCoursesDialog(QWidget *parent = 0);
    ~ManageCoursesDialog();

private slots:
    void on_pushSaveCourses_clicked();

private:
    Ui::ManageCoursesDialog *ui;
    void populateTable();
    QList<Schwierigkeit> Stuffen;
    QList<Departments> Deps;

};

#endif // MANAGECOURSESDIALOG_H
