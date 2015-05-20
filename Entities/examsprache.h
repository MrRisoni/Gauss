#ifndef EXAMSPRACHE_H
#define EXAMSPRACHE_H

#include "student.h"
#include "diplomas.h"

class ExamSprache
{
public:
    ExamSprache();
    ~ExamSprache();

    Student getSt() const;
    void setSt(const Student &value);

    QDate getDat() const;
    void setDat(const QDate &value);

    Diplomas getD() const;
    void setD(const Diplomas &value);

    float getGrade() const;
    void setGrade(float value);

private:
    Student st;
    QDate dat;
    Diplomas D;
    float grade;
};

#endif // EXAMSPRACHE_H
