#include "teacher.h"

Teacher::Teacher():
    Members()
{

}

Teacher::~Teacher()
{

}
BaseWages Teacher::getBase_wages() const
{
    return base_wages;
}

void Teacher::setBase_wages(const BaseWages &value)
{
    base_wages = value;
}
QList<Courses> Teacher::getCanTeach() const
{
    return CanTeach;
}

void Teacher::setCanTeach(const QList<Courses> &value)
{
    CanTeach = value;
}

QByteArray Teacher::getPhoto() const
{
    return photo;
}

void Teacher::setPhoto(const QByteArray &value)
{
    photo = value;
}
Kassen Teacher::getVersichern() const
{
    return Versichern;
}

void Teacher::setVersichern(const Kassen &value)
{
    Versichern = value;
}
QList<Unavailable> Teacher::getUnAvailability() const
{
    return UnAvailability;
}

void Teacher::setUnAvailability(const QList<Unavailable> &value)
{
    UnAvailability = value;
}
QDate Teacher::getEndOfContract() const
{
    return EndOfContract;
}

void Teacher::setEndOfContract(const QDate &value)
{
    EndOfContract = value;
}
Echelon Teacher::getEch() const
{
    return Ech;
}

void Teacher::setEch(const Echelon &value)
{
    Ech = value;
}
PayKassen Teacher::getPayKasse() const
{
    return payKasse;
}

void Teacher::setPayKasse(const PayKassen &value)
{
    payKasse = value;
}
QString Teacher::getAFM() const
{
    return AFM;
}

void Teacher::setAFM(const QString &value)
{
    AFM = value;
}
int Teacher::getTeacherID() const
{
    return TeacherID;
}

void Teacher::setTeacherID(int value)
{
    TeacherID = value;
}












