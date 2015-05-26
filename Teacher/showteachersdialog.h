#ifndef SHOWTEACHERSDIALOG_H
#define SHOWTEACHERSDIALOG_H

#include <QDialog>

namespace Ui {
class ShowTeachersDialog;
}

class ShowTeachersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowTeachersDialog(QWidget *parent = 0);
    ~ShowTeachersDialog();

private:
    Ui::ShowTeachersDialog *ui;
};

#endif // SHOWTEACHERSDIALOG_H
