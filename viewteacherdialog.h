#ifndef VIEWTEACHERDIALOG_H
#define VIEWTEACHERDIALOG_H

#include <QDialog>

namespace Ui {
class ViewTeacherDialog;
}

class ViewTeacherDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewTeacherDialog(QWidget *parent = 0);
    ~ViewTeacherDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushAddAmount_clicked();

    void on_comboDeps_currentIndexChanged(const QString &arg1);

    void on_pushAddCourse_clicked();

private:
    Ui::ViewTeacherDialog *ui;
};

#endif // VIEWTEACHERDIALOG_H
