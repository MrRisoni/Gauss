#ifndef SHOWGROUPSDIALOG_H
#define SHOWGROUPSDIALOG_H

#include <QDialog>

namespace Ui {
class ShowGroupsDialog;
}

class ShowGroupsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowGroupsDialog(QWidget *parent = 0);
    ~ShowGroupsDialog();

private slots:
    void on_pushCancel_clicked();

    void on_tableAllGroups_doubleClicked(const QModelIndex &index);

    void on_pushAddTempo_clicked();

    void on_pushCharts_clicked();

private:
    Ui::ShowGroupsDialog *ui;
    QString group_id;
};

#endif // SHOWGROUPSDIALOG_H
