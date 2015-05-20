#include "managefeesdialog.h"
#include "ui_managefeesdialog.h"

ManageFeesDialog::ManageFeesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageFeesDialog)
{
    ui->setupUi(this);
}

ManageFeesDialog::~ManageFeesDialog()
{
    delete ui;
}


void ManageFeesDialog::populateTable() {
    /*Show
     * CourseID
     * Name
     * Latest update date
     * fee
     * #Number of times changes
     * db click on row shows progression :)
     */
}
