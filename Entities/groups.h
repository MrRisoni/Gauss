#ifndef GROUPS_H
#define GROUPS_H

#include "courses.h"
#include "ensembles.h"
#include "student.h"
#include <QDate>
#include "teacher.h"

class Groups
{
public:
    Groups();
    ~Groups();
    int getGroupID() const;
    void setGroupID(int value);

    QDate getStartDate() const;
    void setStartDate(const QDate &value);

    bool getActive() const;
    void setActive(bool value);

    int getEduType() const;
    void setEduType(int value);

    Teacher getTeacher() const;
    void setTeacher(const Teacher &value);

private:
    int GroupID;
    Teacher teacher;
    QList<Student> meli;
    Courses course;
    QDate StartDate;
    bool Active;
    int EduType;



};

#endif // GROUPS_H
