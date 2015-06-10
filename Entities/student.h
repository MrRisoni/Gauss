#ifndef STUDENT_H
#define STUDENT_H

#include "members.h"

class Student : public Members
{
public:
    Student();

    QList<Student> getSchuleInterested(QString CourseNme); //fetch students from schule
    QList<QString> getGroupIDs() const;
    void setGroupIDs(const QList<QString> &value);

private:
    QList<QString> GroupIDs;
};

#endif // STUDENT_H
