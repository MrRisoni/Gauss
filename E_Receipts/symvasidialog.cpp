#include "symvasidialog.h"
#include "ui_symvasidialog.h"

SymvasiDialog::SymvasiDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SymvasiDialog)
{
    ui->setupUi(this);
}

SymvasiDialog::~SymvasiDialog()
{
    delete ui;
}
