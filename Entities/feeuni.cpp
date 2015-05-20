#include "feeuni.h"

FeeUni::FeeUni()
{

}

FeeUni::~FeeUni()
{

}
Courses FeeUni::getC() const
{
    return C;
}

void FeeUni::setC(const Courses &value)
{
    C = value;
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




