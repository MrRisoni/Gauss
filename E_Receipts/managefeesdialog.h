#ifndef MANAGEFEESDIALOG_H
#define MANAGEFEESDIALOG_H

#include <QDialog>

namespace Ui {
class ManageFeesDialog;
}

class ManageFeesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManageFeesDialog(QWidget *parent = 0);
    ~ManageFeesDialog();

private slots:
    void on_pushSaveSchuleFee_clicked();

    void on_tableCourses_doubleClicked(const QModelIndex &index);

    void on_tableUniCourses_doubleClicked(const QModelIndex &index);

    void on_tableSpracheCourses_doubleClicked(const QModelIndex &index);

private:
    Ui::ManageFeesDialog *ui;
    void populateTable();
};

#endif // MANAGEFEESDIALOG_H
