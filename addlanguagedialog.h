#ifndef ADDLANGUAGEDIALOG_H
#define ADDLANGUAGEDIALOG_H

#include <QDialog>

namespace Ui {
class AddLanguageDialog;
}

class AddLanguageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddLanguageDialog(QWidget *parent = 0);
    ~AddLanguageDialog();

private:
    Ui::AddLanguageDialog *ui;
};

#endif // ADDLANGUAGEDIALOG_H
