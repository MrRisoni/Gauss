#ifndef EXAMSCHULE_H
#define EXAMSCHULE_H


#include <QDate>

class ExamSchule
{
public:
    ExamSchule();
    ~ExamSchule();



    QDate getDat() const;
    void setDat(const QDate &value);



    float getGrade() const;
    void setGrade(float value);

private:
    int studID;
    QDate dat;
    int CourseID;
    float grade;

};

#endif // EXAMSCHULE_H
