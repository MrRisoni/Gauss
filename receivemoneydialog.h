#ifndef RECEIVEMONEYDIALOG_H
#define RECEIVEMONEYDIALOG_H

#include <QDialog>

namespace Ui {
class ReceiveMoneyDialog;
}

class ReceiveMoneyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReceiveMoneyDialog(QWidget *parent = 0);
    ~ReceiveMoneyDialog();

private:
    Ui::ReceiveMoneyDialog *ui;
};

#endif // RECEIVEMONEYDIALOG_H
