#ifndef GIVEMONEYDIALOG_H
#define GIVEMONEYDIALOG_H

#include <QDialog>

namespace Ui {
class GiveMoneyDialog;
}

class GiveMoneyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GiveMoneyDialog(QWidget *parent = 0);
    ~GiveMoneyDialog();

private:
    Ui::GiveMoneyDialog *ui;
};

#endif // GIVEMONEYDIALOG_H
