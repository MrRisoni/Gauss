#ifndef EXAMSCHULE_H
#define EXAMSCHULE_H

#include "student.h"

class ExamSchule
{
public:
    ExamSchule();
    ~ExamSchule();

    Student getSt() const;
    void setSt(const Student &value);

    QDate getDat() const;
    void setDat(const QDate &value);

    Courses getC() const;
    void setC(const Courses &value);

    float getGrade() const;
    void setGrade(float value);

private:
    Student st;
    QDate dat;
    Courses C;
    float grade;

};

#endif // EXAMSCHULE_H
