#ifndef STUDENT_H
#define STUDENT_H

#include "members.h"

class Student : public Members
{
public:
    Student();

    QList<Student> getSchuleInterested(QString CourseNme); //fetch students from schule
};

#endif // STUDENT_H
