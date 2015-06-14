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

    QString getTeacherName() const;
    void setTeacherName(const QString &value);

    int getGroupID() const;
    void setGroupID(const int &value);

private:
    int teacherID;
    QString ADT;
    QString TeacherName;
    QDate dat;
    float Money;
    QString PayType;
    int GroupID;

};

#endif // PAYMENTS_H
