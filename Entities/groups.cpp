#include "groups.h"

Groups::Groups()
{

}

Groups::~Groups()
{

}
int Groups::getGroupID() const
{
    return GroupID;
}

void Groups::setGroupID(int value)
{
    GroupID = value;
}
QDate Groups::getStartDate() const
{
    return StartDate;
}

void Groups::setStartDate(const QDate &value)
{
    StartDate = value;
}
bool Groups::getActive() const
{
    return Active;
}

void Groups::setActive(bool value)
{
    Active = value;
}
int Groups::getEduType() const
{
    return EduType;
}

void Groups::setEduType(int value)
{
    EduType = value;
}
QString Groups::getTeacherID() const
{
    return teacherID;
}

void Groups::setTeacherID(const QString &value)
{
    teacherID = value;
}
QString Groups::getTeacherName() const
{
    return TeacherName;
}

void Groups::setTeacherName(const QString &value)
{
    TeacherName = value;
}
QList<QString> Groups::getMeliID() const
{
    return meliID;
}

void Groups::setMeliID(const QList<QString> &value)
{
    meliID = value;
}
QString Groups::getCourseName() const
{
    return CourseName;
}

void Groups::setCourseName(const QString &value)
{
    CourseName = value;
}
int Groups::getEnsembleID() const
{
    return EnsembleID;
}

void Groups::setEnsembleID(int value)
{
    EnsembleID = value;
}










