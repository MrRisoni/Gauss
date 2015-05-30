#ifndef DISCOUNT_H
#define DISCOUNT_H

#include <QDate>


class Discount
{
public:
    Discount();
    int getDiscountID() const;
    void setDiscountID(int value);

    int getDiscountTypeID() const;
    void setDiscountTypeID(int value);

    float getReduce() const;
    void setReduce(float value);

    QDate getDat() const;
    void setDat(const QDate &value);

private:
    int DiscountID;
    int DiscountTypeID;
    float reduce;
    QDate dat;
};

#endif // DISCOUNT_H
