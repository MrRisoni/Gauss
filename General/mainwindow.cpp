#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zeitwandel.h"
#include "geldrechen.h"
#include <tuple>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    connect(ui->actionSchwer_Levels,SIGNAL(triggered()),this,SLOT(addSchwer()));
    connect(ui->actionManage_Departments,SIGNAL(triggered()),this,SLOT(manageDeps()));
    connect(ui->actionManage_Courses,SIGNAL(triggered()),this,SLOT(manageCourses()));
    connect(ui->actionManage_Pay_Schemes,SIGNAL(triggered()),this,SLOT(manageSchemes()));
    connect(ui->actionAdd_Student,SIGNAL(triggered()),this,SLOT(addStudent()));
    connect(ui->actionAdd_Teacher,SIGNAL(triggered()),this,SLOT(addTeacher()));
    connect(ui->actionManage_Kassen,SIGNAL(triggered()),this,SLOT(manageKassen()));
    connect(ui->actionBuildings_and_Rooms,SIGNAL(triggered()),this,SLOT(manageBuildings()));
    connect(ui->actionAdd_Requests,SIGNAL(triggered()),this,SLOT(addrequest()));

    connect(ui->actionCreate_Uni_Group,SIGNAL(triggered()),this,SLOT(createuni()));
    connect(ui->actionCreate_Sprache_Group,SIGNAL(triggered()),this,SLOT(createpsprache()));
    connect(ui->actionCreate_Schule_Group,SIGNAL(triggered()),this,SLOT(createschule()));
    connect(ui->actionManage_Fee_Schemes,SIGNAL(triggered()),this,SLOT(manageFees()));
    connect(ui->actionShow_Teacher,SIGNAL(triggered()),this,SLOT(showTeacher()));


    connect(ui->actionTest_Plot,SIGNAL(triggered()),this,SLOT(showTestPlot()));
    connect(ui->actionMachine_Learning,SIGNAL(triggered()),this,SLOT(MachLearn()));
    connect(ui->actionManage_Instituts,SIGNAL(triggered()),this,SLOT(manageInstituts()));
    connect(ui->actionManage_Langugages,SIGNAL(triggered()),this,SLOT(manageLanguages()));
    connect(ui->actionManage_Diplomas,SIGNAL(triggered()),this,SLOT(manageDiplomas()));

    connect(ui->actionGive_Receipt,SIGNAL(triggered()),this,SLOT(giveMoneyReceipt()));
    connect(ui->actionTake_Money,SIGNAL(triggered()),this,SLOT(takeMoneyReceipt()));
    connect(ui->actionShow_All_Groups,SIGNAL(triggered()),this,SLOT(showAllGroups()));

    connect(ui->actionShow_All_Students,SIGNAL(triggered()),this,SLOT(showAllStudents()));
    connect(ui->actionView_Student,SIGNAL(triggered()),this,SLOT(showStudent()));

    connect(ui->actionSchule_Tests,SIGNAL(triggered()),this,SLOT(SchuleTests()));
    connect(ui->actionSprache_Tests,SIGNAL(triggered()),this,SLOT(SpracheTests()));






    //show timetable
    ZeitWandel ZW = ZeitWandel();

    QStandardItemModel *mod;
    QList<Cell> Zells;

    std::tie(mod,Zells)=ZW.getSchule();

    ui->tableSchule->setModel( mod);

    //set span
    for (Cell z : Zells) {
        ui->tableSchule->setSpan(z.row,z.col,z.row_span,1);
    }

    ui->tableSchule->resizeColumnsToContents();
    ui->tableSchule->resizeRowsToContents();



    //salary update :)

    GeldRechen GD = GeldRechen();
    GD.calcSProfSalaries();
    GD.calcStudentFees();
}

MainWindow::~MainWindow()
{
    delete ui;
}
QSqlDatabase MainWindow::getDb() const
{
    return db;
}


void MainWindow::SchuleTests(){
    ManageSchuleTestsDialog *schTests = new ManageSchuleTestsDialog();
    schTests->setAttribute(Qt::WA_DeleteOnClose);
    schTests->show();
}


void MainWindow::SpracheTests() {
    ManageSpracheTestsDialog *spTests = new ManageSpracheTestsDialog();
    spTests->setAttribute(Qt::WA_DeleteOnClose);
    spTests->show();
}

void MainWindow::warum() {
    ShowStudentsDialog *war = new ShowStudentsDialog();

}

void MainWindow::showAllStudents(){
    qDebug() << "show all students";
    ShowStudentsDialog *showstuds = new ShowStudentsDialog();
    showstuds->show();
    qDebug() << "show all students";

}

void MainWindow::showStudent() {
    ViewStudentDialog *viewstud = new ViewStudentDialog();
    viewstud->setAttribute(Qt::WA_DeleteOnClose);
    viewstud->show();
}

void MainWindow::showAllGroups() {
    ShowGroupsDialog *grp = new ShowGroupsDialog();
    grp->setAttribute(Qt::WA_DeleteOnClose);
    grp->show();
}


void MainWindow::giveMoneyReceipt() {

    CreateNewReceiptDialog *gief = new CreateNewReceiptDialog();
    gief->setReceiptType(-1);
    gief->setAttribute(Qt::WA_DeleteOnClose);
    gief->show();
}

void MainWindow::takeMoneyReceipt() {
    CreateNewReceiptDialog *rec = new CreateNewReceiptDialog();
    rec->setReceiptType(1);
    rec->setAttribute(Qt::WA_DeleteOnClose);
    rec->show();
}

void MainWindow::manageDiplomas() {
    AddNewDiplomaDialog *diplo = new AddNewDiplomaDialog();
    diplo->setAttribute(Qt::WA_DeleteOnClose);
    diplo->show();
}


void MainWindow::manageLanguages() {
    AddLanguageDialog *addLang = new AddLanguageDialog();
    addLang->setAttribute(Qt::WA_DeleteOnClose);
    addLang->show();
}

void MainWindow::MachLearn() {

    std::string filename = "python2  /home/linguine/Gauss/Artif_Intel/test.py";

    system(filename.c_str());
}


void MainWindow::manageInstituts() {
    AddInstitutDialog *instdial = new AddInstitutDialog();
    instdial->setAttribute(Qt::WA_DeleteOnClose);
    instdial->show();
}

void MainWindow::showTestPlot() {
    PlotDialog *plotdial= new PlotDialog();
    plotdial->setAttribute(Qt::WA_DeleteOnClose);
    plotdial->show();
}

void MainWindow::setDb(const QSqlDatabase &value)
{
    db = value;
}


void MainWindow::showTeacher() {
    ViewTeacherDialog *viewTeach = new ViewTeacherDialog();
    viewTeach->setAttribute(Qt::WA_DeleteOnClose);
    viewTeach->show();
}

void MainWindow::manageFees() {
    ManageFeesDialog *feedial=new  ManageFeesDialog();
    feedial->setAttribute(Qt::WA_DeleteOnClose);
    feedial->show();

}

void MainWindow::addrequest() {

    AddNewRequestDialog *addReq = new AddNewRequestDialog();
    addReq->setAttribute(Qt::WA_DeleteOnClose);
    addReq->show();

}

void MainWindow::createuni() {

    CreateUniDialog *crUni = new CreateUniDialog();
    crUni->setAttribute(Qt::WA_DeleteOnClose);
    crUni->show();

}

void MainWindow::createpsprache() {


    CreateSpracheDialog *crSprache =new  CreateSpracheDialog();
    crSprache->setAttribute(Qt::WA_DeleteOnClose);
    crSprache->show();

}

void MainWindow::createschule() {

    CreateSchuleGroupDialog *crSchule = new CreateSchuleGroupDialog();
    crSchule->setAttribute(Qt::WA_DeleteOnClose);
    crSchule->show();
}



void MainWindow::manageBuildings() {
    RaumeDialog *raume = new RaumeDialog();
    raume->setAttribute(Qt::WA_DeleteOnClose);
    raume->show();
}

void MainWindow::manageKassen() {
    KassenDialog *kassDial = new KassenDialog();
    kassDial->setAttribute(Qt::WA_DeleteOnClose);
    kassDial->show();
}

void MainWindow::addTeacher() {
    AddNewTeacherDialog *newteach = new AddNewTeacherDialog();
    newteach->setDb(getDb());
    newteach->setAttribute(Qt::WA_DeleteOnClose);
    newteach->show();

}

void MainWindow::addStudent() {
    AddNewStudentDialog *newstud=new AddNewStudentDialog();
    newstud->setAttribute(Qt::WA_DeleteOnClose);
    newstud->show();

}

void MainWindow::manageSchemes() {
    ManageSalariesDialog *sals=new ManageSalariesDialog();
    sals->setAttribute(Qt::WA_DeleteOnClose);
    sals->show();
}

void MainWindow::manageCourses() {
    ManageCoursesDialog *crs=new ManageCoursesDialog();
    crs->setAttribute(Qt::WA_DeleteOnClose);
    crs->show();
}



void MainWindow::manageDeps() {
    ManageDepsDialog *deps=new ManageDepsDialog();
    deps->setAttribute(Qt::WA_DeleteOnClose);
    deps->show();
}


void MainWindow::addSchwer() {
    AddNewSchwerDialog *sch=new AddNewSchwerDialog();
    sch->setAttribute(Qt::WA_DeleteOnClose);
    sch->show();
}
