#include "discounttype.h"

DiscountType::DiscountType()
{

}
QString DiscountType::getDescription() const
{
    return Description;
}

void DiscountType::setDescription(const QString &value)
{
    Description = value;
}
int DiscountType::getTypeID() const
{
    return TypeID;
}

void DiscountType::setTypeID(int value)
{
    TypeID = value;
}



