#include "mainwindow.h"
#include "ui_mainwindow.h"



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
}

MainWindow::~MainWindow()
{
    delete ui;
}
QSqlDatabase MainWindow::getDb() const
{
    return db;
}


void MainWindow::giveMoneyReceipt() {
    GiveMoneyDialog *gief = new GiveMoneyDialog();
    gief->setAttribute(Qt::WA_DeleteOnClose);
    gief->show();
}

void MainWindow::takeMoneyReceipt() {
    ReceiveMoneyDialog *rec = new ReceiveMoneyDialog();
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