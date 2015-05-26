#ifndef ADDSPRACHESCHEDULEDIALOG_H
#define ADDSPRACHESCHEDULEDIALOG_H

#include <QDialog>

namespace Ui {
class AddSpracheScheduleDialog;
}

class AddSpracheScheduleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddSpracheScheduleDialog(QWidget *parent = 0);
    ~AddSpracheScheduleDialog();

private:
    Ui::AddSpracheScheduleDialog *ui;
};

#endif // ADDSPRACHESCHEDULEDIALOG_H
