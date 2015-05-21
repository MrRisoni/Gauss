#include "feesprache.h"

FeeSprache::FeeSprache()
{

}

FeeSprache::~FeeSprache()
{

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




