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

private:
    Ui::CreateSchuleGroupDialog *ui;
    void populateTable();
};

#endif // CREATESCHULEGROUPDIALOG_H
