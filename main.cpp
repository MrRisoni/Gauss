#include "General/mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <QTextStream>
#include "mongo/client/dbclient.h" // for the driver

QSqlDatabase vasi;

QFile logFile;



void run() {
  mongo::DBClientConnection c;
  c.connect("localhost");

}




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    try {
         run();
          std::cout << "connected ok" << std::endl;
        } catch( const mongo::DBException &e ) {
          std::cout << "caught " << e.what() << std::endl;
        }




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

