#ifndef GELDRECHEN_H
#define GELDRECHEN_H

#include <QList>
#include <QSqlQuery>
#include <QVariant>

class GeldRechen
{
public:
    GeldRechen();
    void calcStudentFees();
    void calcSProfSalaries();


private:
    QDate minDate(QDate a,QDate b);
    QDate maxDate(QDate a,QDate b);


};

#endif // GELDRECHEN_H
