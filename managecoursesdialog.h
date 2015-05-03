#ifndef MANAGECOURSESDIALOG_H
#define MANAGECOURSESDIALOG_H

#include <QDialog>

namespace Ui {
class ManageCoursesDialog;
}

class ManageCoursesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManageCoursesDialog(QWidget *parent = 0);
    ~ManageCoursesDialog();

private:
    Ui::ManageCoursesDialog *ui;
};

#endif // MANAGECOURSESDIALOG_H
