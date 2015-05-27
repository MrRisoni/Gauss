#include "showteachersdialog.h"
#include "ui_showteachersdialog.h"

ShowTeachersDialog::ShowTeachersDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowTeachersDialog)
{
    ui->setupUi(this);
    /*
     * teacherid
     * name
     * address
     * #courses + #diplomas
     * Courses tooltip
     * salary
     * total money payed
     * debt
     * xp years
     */
}

ShowTeachersDialog::~ShowTeachersDialog()
{
    delete ui;
}
