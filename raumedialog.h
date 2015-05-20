#ifndef RAUMEDIALOG_H
#define RAUMEDIALOG_H

#include <QDialog>
#include "Entities/orm.h"


namespace Ui {
class RaumeDialog;
}

class RaumeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RaumeDialog(QWidget *parent = 0);
    ~RaumeDialog();

private slots:
    void on_pushAdd_clicked();

    void on_pushAddRoom_clicked();

private:
    Ui::RaumeDialog *ui;
    void populateTable();
    void populateRoomTable();
};

#endif // RAUMEDIALOG_H
