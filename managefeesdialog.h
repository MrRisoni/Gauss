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

private:
    Ui::ManageFeesDialog *ui;
};

#endif // MANAGEFEESDIALOG_H
