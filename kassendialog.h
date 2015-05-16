#ifndef KASSENDIALOG_H
#define KASSENDIALOG_H

#include <QDialog>

namespace Ui {
class KassenDialog;
}

class KassenDialog : public QDialog
{
    Q_OBJECT

public:
    explicit KassenDialog(QWidget *parent = 0);
    ~KassenDialog();

private slots:
    void on_pushSave_clicked();

private:
    Ui::KassenDialog *ui;
    void populateKassenTable();
};

#endif // KASSENDIALOG_H
