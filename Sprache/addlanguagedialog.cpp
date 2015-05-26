#include "addlanguagedialog.h"
#include "ui_addlanguagedialog.h"

AddLanguageDialog::AddLanguageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLanguageDialog)
{
    ui->setupUi(this);
}

AddLanguageDialog::~AddLanguageDialog()
{
    delete ui;
}



void AddLanguageDialog::on_pushAddSprache_clicked()
{

}

void AddLanguageDialog::on_tableSprachen_doubleClicked(const QModelIndex &index)
{
    //show the success rate and failure rate so far for every diploma of that language
}
