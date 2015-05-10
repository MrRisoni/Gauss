#ifndef BASEWAGES_H
#define BASEWAGES_H

#include <QDate>
#include "echelon.h"


class BaseWages
{
public:
    BaseWages();
    ~BaseWages();
    Echelon getE() const;
    void setE(const Echelon &value);

    QDate getD() const;
    void setD(const QDate &value);

    float getWage() const;
    void setWage(float value);

private:
    Echelon E;
    QDate D;
    float Wage;
};

#endif // BASEWAGES_H
