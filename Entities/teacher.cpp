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
int Teacher::getKasseID() const
{
    return KasseID;
}

void Teacher::setKasseID(int value)
{
    KasseID = value;
}
int Teacher::getTotalGroups() const
{
    return TotalGroups;
}

void Teacher::setTotalGroups(int value)
{
    TotalGroups = value;
}
int Teacher::getTotalStudents() const
{
    return TotalStudents;
}

void Teacher::setTotalStudents(int value)
{
    TotalStudents = value;
}
int Teacher::getCurrentGroups() const
{
    return CurrentGroups;
}

void Teacher::setCurrentGroups(int value)
{
    CurrentGroups = value;
}
int Teacher::getCurrentStudents() const
{
    return CurrentStudents;
}

void Teacher::setCurrentStudents(int value)
{
    CurrentStudents = value;
}
int Teacher::getTotalHours() const
{
    return TotalHours;
}

void Teacher::setTotalHours(int value)
{
    TotalHours = value;
}
QList<Groups> Teacher::getHasTaught() const
{
    return HasTaught;
}

void Teacher::setHasTaught(const QList<Groups> &value)
{
    HasTaught = value;
}
QList<History> Teacher::getTeachingHistory() const
{
    return TeachingHistory;
}

void Teacher::setTeachingHistory(const QList<History> &value)
{
    TeachingHistory = value;
}
QList<Erlaubnis> Teacher::getErlaubHistory() const
{
    return ErlaubHistory;
}

void Teacher::setErlaubHistory(const QList<Erlaubnis> &value)
{
    ErlaubHistory = value;
}





















