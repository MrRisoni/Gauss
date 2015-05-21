#include "feeuni.h"

FeeUni::FeeUni()
{

}

FeeUni::~FeeUni()
{

}


QDate FeeUni::getDat() const
{
    return dat;
}

void FeeUni::setDat(const QDate &value)
{
    dat = value;
}
float FeeUni::getFee() const
{
    return fee;
}

void FeeUni::setFee(float value)
{
    fee = value;
}




