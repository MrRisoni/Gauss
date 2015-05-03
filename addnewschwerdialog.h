#ifndef ADDNEWSCHWERDIALOG_H
#define ADDNEWSCHWERDIALOG_H

#include <QDialog>
#include "Entities/orm.h"



namespace Ui {
class AddNewSchwerDialog;
}

class AddNewSchwerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewSchwerDialog(QWidget *parent = 0);
    ~AddNewSchwerDialog();

private slots:
    void on_pushPickColor_clicked();

    void on_pushSave_clicked();

private:
    Ui::AddNewSchwerDialog *ui;
    int red,green,blue;
    void LoadColors();

};

#endif // ADDNEWSCHWERDIALOG_H
