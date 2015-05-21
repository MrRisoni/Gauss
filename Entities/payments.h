#ifndef PAYMENTS_H
#define PAYMENTS_H


#include <QString>
#include <QDate>


class Payments
{
public:
    Payments();
    ~Payments();


    QDate getDat() const;
    void setDat(const QDate &value);

    float getMoney() const;
    void setMoney(float value);

    QString getPayType() const;
    void setPayType(const QString &value);

private:
    int teacherID;
    QDate dat;
    float Money;
    QString PayType;

};

#endif // PAYMENTS_H
