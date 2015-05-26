#include "General/mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase vasi;

    vasi= QSqlDatabase::addDatabase("QMYSQL");
    vasi.setHostName("localhost");
    vasi.setDatabaseName("Gauss");
    vasi.setUserName("jamie");
    vasi.setPassword("jamie");

    vasi.open();



    MainWindow w;
    w.setDb(vasi);
    w.show();

    return a.exec();


    //destroy db release memory
    vasi.close();
    QSqlDatabase::removeDatabase("Gauss");
}
