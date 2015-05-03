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

private:
    Ui::AddNewStudentDialog *ui;
};

#endif // ADDNEWSTUDENTDIALOG_H
