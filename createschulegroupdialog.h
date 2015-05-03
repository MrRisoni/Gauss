#ifndef CREATESCHULEGROUPDIALOG_H
#define CREATESCHULEGROUPDIALOG_H

#include <QDialog>

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
};

#endif // CREATESCHULEGROUPDIALOG_H
