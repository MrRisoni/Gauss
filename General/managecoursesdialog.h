#ifndef MANAGECOURSESDIALOG_H
#define MANAGECOURSESDIALOG_H

#include <QDialog>
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

    void on_tableCourses_doubleClicked(const QModelIndex &index);

private:
    Ui::ManageCoursesDialog *ui;
    void populateTable();


};

#endif // MANAGECOURSESDIALOG_H
