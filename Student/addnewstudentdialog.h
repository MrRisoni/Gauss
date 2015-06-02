#ifndef ADDNEWSTUDENTDIALOG_H
#define ADDNEWSTUDENTDIALOG_H

#include <QDialog>

namespace Ui {
class AddNewStudentDialog;
}

class AddNewStudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewStudentDialog(QWidget *parent = 0);
    ~AddNewStudentDialog();

private slots:
    void on_pushAddStudent_clicked();

    void on_checkSchule_clicked();

private:
    Ui::AddNewStudentDialog *ui;
};

#endif // ADDNEWSTUDENTDIALOG_H
