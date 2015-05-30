#ifndef MANAGEDISCIPLINESDIALOG_H
#define MANAGEDISCIPLINESDIALOG_H

#include <QDialog>

namespace Ui {
class ManageDisciplinesDialog;
}

class ManageDisciplinesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManageDisciplinesDialog(QWidget *parent = 0);
    ~ManageDisciplinesDialog();

private:
    Ui::ManageDisciplinesDialog *ui;
};

#endif // MANAGEDISCIPLINESDIALOG_H
