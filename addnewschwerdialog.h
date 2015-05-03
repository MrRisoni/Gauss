#ifndef ADDNEWSCHWERDIALOG_H
#define ADDNEWSCHWERDIALOG_H

#include <QDialog>

namespace Ui {
class AddNewSchwerDialog;
}

class AddNewSchwerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewSchwerDialog(QWidget *parent = 0);
    ~AddNewSchwerDialog();

private:
    Ui::AddNewSchwerDialog *ui;
};

#endif // ADDNEWSCHWERDIALOG_H
