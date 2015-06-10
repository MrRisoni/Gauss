#ifndef FUNDS_H
#define FUNDS_H

#include <QDate>


class Funds
{
public:
    Funds();
    ~Funds();



    QString getGroupID() const;
    void setGroupID(QString value);

    float getAmount() const;
    void setAmount(float value);

    QString getADT() const;
    void setADT(const QString &value);

private:
    QString  ADT;
    QString GroupID;
    float amount;

};

#endif // FUNDS_H
