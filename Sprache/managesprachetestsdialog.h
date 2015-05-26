#ifndef MANAGESPRACHETESTSDIALOG_H
#define MANAGESPRACHETESTSDIALOG_H

#include <QDialog>

namespace Ui {
class ManageSpracheTestsDialog;
}

class ManageSpracheTestsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManageSpracheTestsDialog(QWidget *parent = 0);
    ~ManageSpracheTestsDialog();

private:
    Ui::ManageSpracheTestsDialog *ui;
};

#endif // MANAGESPRACHETESTSDIALOG_H
