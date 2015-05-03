#ifndef MANAGEDEPSDIALOG_H
#define MANAGEDEPSDIALOG_H

#include <QDialog>

namespace Ui {
class ManageDepsDialog;
}

class ManageDepsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManageDepsDialog(QWidget *parent = 0);
    ~ManageDepsDialog();

private:
    Ui::ManageDepsDialog *ui;
};

#endif // MANAGEDEPSDIALOG_H
