#ifndef TEACHER_H
#define TEACHER_H

#include "kassen.h"
#include "unavailable.h"
#include "paykassen.h"
#include "members.h"
#include "basewages.h"
#include "courses.h"

class Teacher : public Members
{
public:
    Teacher();
    ~Teacher();

    BaseWages getBase_wages() const;
    void setBase_wages(const BaseWages &value);

    QList<Courses> getCanTeach() const;
    void setCanTeach(const QList<Courses> &value);



    QByteArray getPhoto() const;
    void setPhoto(const QByteArray &value);

    Kassen getVersichern() const;
    void setVersichern(const Kassen &value);

    QList<Unavailable> getUnAvailability() const;
    void setUnAvailability(const QList<Unavailable> &value);

    QDate getEndOfContract() const;
    void setEndOfContract(const QDate &value);

    Echelon getEch() const;
    void setEch(const Echelon &value);

    PayKassen getPayKasse() const;
    void setPayKasse(const PayKassen &value);

    QString getAFM() const;
    void setAFM(const QString &value);

    int getTeacherID() const;
    void setTeacherID(int value);

    int getKasseID() const;
    void setKasseID(int value);

    int getTotalGroups() const;
    void setTotalGroups(int value);

    int getTotalStudents() const;
    void setTotalStudents(int value);

    int getCurrentGroups() const;
    void setCurrentGroups(int value);

    int getCurrentStudents() const;
    void setCurrentStudents(int value);

    int getTotalHours() const;
    void setTotalHours(int value);




    QDate calcEOC(); //fetch end of contract


    float getSalary() const;
    void setSalary(float value);

    int getTeachingHours() const;
    void setTeachingHours(int value);

private:
    int TeacherID;
    BaseWages base_wages;
    QList<Courses> CanTeach;
    Echelon Ech;
    QByteArray photo;
    Kassen Versichern;
    PayKassen payKasse;
    QList<Unavailable> UnAvailability;
    float Salary;
    int KasseID;
    QDate EndOfContract;
    QString AFM; //Greek SSN
    int TeachingHours; // teaching hours for a lesson


    int TotalGroups;
    int TotalStudents;
    int CurrentGroups;
    int CurrentStudents;
    int TotalHours;







};

#endif // TEACHER_H
