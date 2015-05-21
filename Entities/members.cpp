#include "members.h"
#include <QDebug>


Members::Members()
{

}

Members::~Members()
{

}
QString Members::getName() const
{
    return Name;
}

void Members::setName(const QString &value)
{
    Name = value;
}
QString Members::getFName() const
{
    return FName;
}

void Members::setFName(const QString &value)
{
    FName = value;
}
QString Members::getMName() const
{
    return MName;
}

void Members::setMName(const QString &value)
{
    MName = value;
}
QString Members::getAddress() const
{
    return Address;
}

void Members::setAddress(const QString &value)
{
    Address = value;
}
QString Members::getMobile() const
{
    return Mobile;
}

void Members::setMobile(const QString &value)
{
    Mobile = value;
}
QString Members::getEmail() const
{
    return Email;
}

void Members::setEmail(const QString &value)
{
    Email = value;
}
QDate Members::getRegDate() const
{
    return RegDate;
}

void Members::setRegDate(const QDate &value)
{
    RegDate = value;
}
QDate Members::getBirthDate() const
{
    return BirthDate;
}

void Members::setBirthDate(const QDate &value)
{
    BirthDate = value;
}
QString Members::getPhone() const
{
    return Phone;
}

void Members::setPhone(const QString &value)
{
    Phone = value;
}
QString Members::getADT() const
{
    return ADT;
}

void Members::setADT(const QString &value)
{
    ADT = value;
}
int Members::getMembID() const
{
    return MembID;
}

void Members::setMembID(int value)
{
    MembID = value;
}




QDebug operator<< (QDebug d, const Members &student) {
    d << " Name " + student.getName() + " ADT " + student.getADT();
    return d ;
}






