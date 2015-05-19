#include "raumedialog.h"
#include "ui_raumedialog.h"

RaumeDialog::RaumeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RaumeDialog)
{
    ui->setupUi(this);
}

RaumeDialog::~RaumeDialog()
{
    delete ui;
}
