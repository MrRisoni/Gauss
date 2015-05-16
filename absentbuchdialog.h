#ifndef ABSENTBUCHDIALOG_H
#define ABSENTBUCHDIALOG_H

#include <QDialog>

namespace Ui {
class AbsentBuchDialog;
}

class AbsentBuchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AbsentBuchDialog(QWidget *parent = 0);
    ~AbsentBuchDialog();

private:
    Ui::AbsentBuchDialog *ui;
};

#endif // ABSENTBUCHDIALOG_H
