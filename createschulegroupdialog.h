#ifndef CREATESCHULEGROUPDIALOG_H
#define CREATESCHULEGROUPDIALOG_H

#include <QDialog>
#include "Entities/orm.h"

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

private:
    Ui::CreateSchuleGroupDialog *ui;
    void populateTable(QString CourseName);
    void populateStudentsTable(QString CourseName);

};

#endif // CREATESCHULEGROUPDIALOG_H
