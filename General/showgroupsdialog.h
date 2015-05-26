#ifndef SHOWGROUPSDIALOG_H
#define SHOWGROUPSDIALOG_H

#include <QDialog>

namespace Ui {
class ShowGroupsDialog;
}

class ShowGroupsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowGroupsDialog(QWidget *parent = 0);
    ~ShowGroupsDialog();

private:
    Ui::ShowGroupsDialog *ui;
};

#endif // SHOWGROUPSDIALOG_H
