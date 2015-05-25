#ifndef SHOWSTUDENTSDIALOG_H
#define SHOWSTUDENTSDIALOG_H

#include <QDialog>

namespace Ui {
class ShowStudentsDialog;
}

class ShowStudentsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowStudentsDialog(QWidget *parent = 0);
    ~ShowStudentsDialog();

private:
    Ui::ShowStudentsDialog *ui;
};

#endif // SHOWSTUDENTSDIALOG_H
