#include "paytype.h"

PayType::PayType()
{

}
QString PayType::getComment() const
{
    return Comment;
}

void PayType::setComment(const QString &value)
{
    Comment = value;
}


