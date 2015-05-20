#include "feeschule.h"

FeeSchule::FeeSchule()
{

}

FeeSchule::~FeeSchule()
{

}
Courses FeeSchule::getC() const
{
    return C;
}

void FeeSchule::setC(const Courses &value)
{
    C = value;
}
QDate FeeSchule::getDat() const
{
    return dat;
}

void FeeSchule::setDat(const QDate &value)
{
    dat = value;
}
float FeeSchule::getFee() const
{
    return fee;
}

void FeeSchule::setFee(float value)
{
    fee = value;
}




