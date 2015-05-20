#ifndef PAYMENTS_H
#define PAYMENTS_H


#include "teacher.h"

class Payments
{
public:
    Payments();
    ~Payments();
    Teacher getTeacher() const;
    void setTeacher(const Teacher &value);

    QDate getDat() const;
    void setDat(const QDate &value);

    float getMoney() const;
    void setMoney(float value);

    QString getPayType() const;
    void setPayType(const QString &value);

private:
    Teacher teacher;
    QDate dat;
    float Money;
    QString PayType;

};

#endif // PAYMENTS_H
