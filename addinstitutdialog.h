#ifndef ADDINSTITUTDIALOG_H
#define ADDINSTITUTDIALOG_H

#include <QDialog>

namespace Ui {
class AddInstitutDialog;
}

class AddInstitutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddInstitutDialog(QWidget *parent = 0);
    ~AddInstitutDialog();

private:
    Ui::AddInstitutDialog *ui;
};

#endif // ADDINSTITUTDIALOG_H
