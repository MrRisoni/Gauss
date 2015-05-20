#ifndef ABSENT_H
#define ABSENT_H

#include "student.h"
#include "history.h"

class Absent
{
public:
    Absent();
    ~Absent();
    int getStudentID() const;
    void setStudentID(int value);

    Student getSt() const;
    void setSt(const Student &value);

    History getH() const;
    void setH(const History &value);

private:
    int StudentID;
    Student st;
    History h;
};

#endif // ABSENT_H
