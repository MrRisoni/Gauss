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



/* TO DO
  Language
  Instituts
  #Teachers
  #Total Groups
  #Total Active Groups
  #Total Students
  #Diplomas ( ComboBox???)

}
 */
