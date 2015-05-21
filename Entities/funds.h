#ifndef FUNDS_H
#define FUNDS_H

#include <QDate>


class Funds
{
public:
    Funds();
    ~Funds();


    QDate getDat() const;
    void setDat(const QDate &value);

    float getFee() const;

    void setFee(float value);

private:
    int  studID;
    QDate dat;
    float fee;

};

#endif // FUNDS_H
