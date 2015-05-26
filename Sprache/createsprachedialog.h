#ifndef CREATESPRACHEDIALOG_H
#define CREATESPRACHEDIALOG_H

#include <QDialog>

namespace Ui {
class CreateSpracheDialog;
}

class CreateSpracheDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateSpracheDialog(QWidget *parent = 0);
    ~CreateSpracheDialog();

private:
    Ui::CreateSpracheDialog *ui;
};

#endif // CREATESPRACHEDIALOG_H
