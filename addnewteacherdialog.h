#ifndef ADDNEWTEACHERDIALOG_H
#define ADDNEWTEACHERDIALOG_H

#include <QDialog>

namespace Ui {
class AddNewTeacherDialog;
}

class AddNewTeacherDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewTeacherDialog(QWidget *parent = 0);
    ~AddNewTeacherDialog();

private:
    Ui::AddNewTeacherDialog *ui;
};

#endif // ADDNEWTEACHERDIALOG_H
