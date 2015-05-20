#include "feesprache.h"

FeeSprache::FeeSprache()
{

}

FeeSprache::~FeeSprache()
{

}
Diplomas FeeSprache::getDiplo() const
{
    return diplo;
}

void FeeSprache::setDiplo(const Diplomas &value)
{
    diplo = value;
}
QDate FeeSprache::getDat() const
{
    return dat;
}

void FeeSprache::setDat(const QDate &value)
{
    dat = value;
}
float FeeSprache::getFee() const
{
    return fee;
}

void FeeSprache::setFee(float value)
{
    fee = value;
}




