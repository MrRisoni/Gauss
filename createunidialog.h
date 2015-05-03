#ifndef CREATEUNIDIALOG_H
#define CREATEUNIDIALOG_H

#include <QDialog>

namespace Ui {
class CreateUniDialog;
}

class CreateUniDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateUniDialog(QWidget *parent = 0);
    ~CreateUniDialog();

private:
    Ui::CreateUniDialog *ui;
};

#endif // CREATEUNIDIALOG_H
