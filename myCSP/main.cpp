#include <QCoreApplication>
#include <cspsolver.h>

//Timetabling via backtracking Forward checking


//Very simple at first
//All Hours and all days are possible!!!!!
//Only one class per week !!!!!!
//So each class has 3 variables that need to be set Day,Hour,Buidling
//Duration for ALL classes is 2 hours

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CspSolver *csp=new CspSolver();
    csp->GeneratePossibleVals();
    return a.exec();
}
