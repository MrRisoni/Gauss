#include "contract.h"

Contract::Contract()
{

}

Contract::~Contract()
{

}
Teacher Contract::getT() const
{
    return T;
}

void Contract::setT(const Teacher &value)
{
    T = value;
}
QDate Contract::getEnde() const
{
    return ende;
}

void Contract::setEnde(const QDate &value)
{
    ende = value;
}



