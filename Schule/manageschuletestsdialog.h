#ifndef MANAGESCHULETESTSDIALOG_H
#define MANAGESCHULETESTSDIALOG_H

#include <QDialog>

namespace Ui {
class ManageSchuleTestsDialog;
}

class ManageSchuleTestsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManageSchuleTestsDialog(QWidget *parent = 0);
    ~ManageSchuleTestsDialog();

private:
    Ui::ManageSchuleTestsDialog *ui;
};

#endif // MANAGESCHULETESTSDIALOG_H
