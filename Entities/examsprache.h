#ifndef EXAMSPRACHE_H
#define EXAMSPRACHE_H

#include <QDate>

class ExamSprache
{
public:
    ExamSprache();
    ~ExamSprache();


    QDate getDat() const;
    void setDat(const QDate &value);



    float getGrade() const;
    void setGrade(float value);

private:
    int studID;
    QDate dat;
    int diploID;
    float grade;
};

#endif // EXAMSPRACHE_H
