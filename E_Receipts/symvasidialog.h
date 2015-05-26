#ifndef SYMVASIDIALOG_H
#define SYMVASIDIALOG_H

#include <QDialog>

namespace Ui {
class SymvasiDialog;
}

class SymvasiDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SymvasiDialog(QWidget *parent = 0);
    ~SymvasiDialog();

private:
    Ui::SymvasiDialog *ui;
};

#endif // SYMVASIDIALOG_H
