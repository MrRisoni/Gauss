#include "basewages.h"

BaseWages::BaseWages()
{

}

BaseWages::~BaseWages()
{

}
Echelon BaseWages::getE() const
{
    return E;
}

void BaseWages::setE(const Echelon &value)
{
    E = value;
}
QDate BaseWages::getD() const
{
    return D;
}

void BaseWages::setD(const QDate &value)
{
    D = value;
}
float BaseWages::getWage() const
{
    return Wage;
}

void BaseWages::setWage(float value)
{
    Wage = value;
}






