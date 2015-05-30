#ifndef DISCOUNTTYPE_H
#define DISCOUNTTYPE_H

#include <QString>

class DiscountType
{
public:
    DiscountType();
    QString getDescription() const;
    void setDescription(const QString &value);

    int getTypeID() const;
    void setTypeID(int value);

private:
    int TypeID;
    QString Description;
};

#endif // DISCOUNTTYPE_H
