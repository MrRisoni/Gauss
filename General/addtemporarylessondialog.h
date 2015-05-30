#ifndef ADDTEMPORARYLESSONDIALOG_H
#define ADDTEMPORARYLESSONDIALOG_H

#include <QDialog>

namespace Ui {
class AddTemporaryLessonDialog;
}

class AddTemporaryLessonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTemporaryLessonDialog(QWidget *parent = 0);
    ~AddTemporaryLessonDialog();

private:
    Ui::AddTemporaryLessonDialog *ui;
};

#endif // ADDTEMPORARYLESSONDIALOG_H
