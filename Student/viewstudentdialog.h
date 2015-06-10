#ifndef VIEWSTUDENTDIALOG_H
#define VIEWSTUDENTDIALOG_H

#include <QDialog>

namespace Ui {
class ViewStudentDialog;
}

class ViewStudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewStudentDialog(QWidget *parent = 0);
    ~ViewStudentDialog();

private slots:
    void on_pushSearch_clicked();

    void on_pushAddPoso_clicked();

private:
    Ui::ViewStudentDialog *ui;
};

#endif // VIEWSTUDENTDIALOG_H
