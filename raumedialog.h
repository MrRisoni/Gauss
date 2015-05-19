#ifndef RAUMEDIALOG_H
#define RAUMEDIALOG_H

#include <QDialog>

namespace Ui {
class RaumeDialog;
}

class RaumeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RaumeDialog(QWidget *parent = 0);
    ~RaumeDialog();

private:
    Ui::RaumeDialog *ui;
};

#endif // RAUMEDIALOG_H
