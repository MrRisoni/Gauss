#include "student.h"

Student::Student():
    Members()
{

}
QList<QString> Student::getGroupIDs() const
{
    return GroupIDs;
}

void Student::setGroupIDs(const QList<QString> &value)
{
    GroupIDs = value;
}


