#include "discount.h"

Discount::Discount()
{

}
int Discount::getDiscountID() const
{
    return DiscountID;
}

void Discount::setDiscountID(int value)
{
    DiscountID = value;
}
int Discount::getDiscountTypeID() const
{
    return DiscountTypeID;
}

void Discount::setDiscountTypeID(int value)
{
    DiscountTypeID = value;
}
float Discount::getReduce() const
{
    return reduce;
}

void Discount::setReduce(float value)
{
    reduce = value;
}
QDate Discount::getDat() const
{
    return dat;
}

void Discount::setDat(const QDate &value)
{
    dat = value;
}





