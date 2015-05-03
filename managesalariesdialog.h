#ifndef MANAGESALARIESDIALOG_H
#define MANAGESALARIESDIALOG_H

#include <QDialog>

namespace Ui {
class ManageSalariesDialog;
}

class ManageSalariesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManageSalariesDialog(QWidget *parent = 0);
    ~ManageSalariesDialog();

private:
    Ui::ManageSalariesDialog *ui;
};

#endif // MANAGESALARIESDIALOG_H
