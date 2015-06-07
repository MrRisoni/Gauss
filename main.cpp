#include "General/mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <QTextStream>


QSqlDatabase vasi;

QFile logFile;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);






    vasi= QSqlDatabase::addDatabase("QMYSQL");
    vasi.setHostName("localhost");
    vasi.setDatabaseName("Gauss");
    vasi.setUserName("jamie");
    vasi.setPassword("jamie");

    vasi.open();


    QFile file( "/tmp/log.txt" );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream << "connected with sql" << endl;
    }





    MainWindow w;






    w.setDb(vasi);



 w.show();

    return a.exec();


    //destroy db release memory
    vasi.close();
    QSqlDatabase::removeDatabase("Gauss");
}

