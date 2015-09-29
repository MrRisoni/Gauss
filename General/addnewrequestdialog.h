#ifndef ADDNEWREQUESTDIALOG_H
#define ADDNEWREQUESTDIALOG_H

#include <QDialog>

namespace Ui {
class AddNewRequestDialog;
}

class AddNewRequestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewRequestDialog(QWidget *parent = 0);
    ~AddNewRequestDialog();

private slots:
    void on_pushSearch_clicked();

    void on_pushAddSchule_clicked();

    void on_pushAddUni_clicked();

    void on_pushButton_3_clicked();

    void on_comboDep_activated(const QString &arg1);

    void on_comboCourses_activated(const QString &arg1);

private:
    Ui::AddNewRequestDialog *ui;
};

#endif // ADDNEWREQUESTDIALOG_H
