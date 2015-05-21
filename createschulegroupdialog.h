#ifndef CREATESCHULEGROUPDIALOG_H
#define CREATESCHULEGROUPDIALOG_H

#include <QDialog>
#include "Entities/orm.h"
#include <QStandardItem>
#include <QStandardItemModel>


namespace Ui {
class CreateSchuleGroupDialog;
}

class CreateSchuleGroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateSchuleGroupDialog(QWidget *parent = 0);
    ~CreateSchuleGroupDialog();

private slots:
    void on_comboCourse_currentTextChanged(const QString &arg1);

    void on_pushAddToGroup_clicked();

    void on_pushRemoveFromGroup_clicked();

    void on_pushClear_clicked();

private:
    Ui::CreateSchuleGroupDialog *ui;
    void populateTable(QString CourseName);
    void populateStudentsTable(QString CourseName);

    int RowAll=0;
    int RowGroup=0;

};

#endif // CREATESCHULEGROUPDIALOG_H
