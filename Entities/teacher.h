#ifndef TEACHER_H
#define TEACHER_H

#include "courses.h"
#include "basewages.h"
#include "unavailable.h"
#include "kassen.h"
#include "members.h"
#include "paykassen.h"
#include "groups.h"
#include "history.h"
#include "payments.h"
#include "erlaubnis.h"

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

    QList<Groups> getHasTaught() const;
    void setHasTaught(const QList<Groups> &value);

    QList<History> getTeachingHistory() const;
    void setTeachingHistory(const QList<History> &value);

    QList<Erlaubnis> getErlaubHistory() const;
    void setErlaubHistory(const QList<Erlaubnis> &value);

private:
    int TeacherID;
    BaseWages base_wages;
    QList<Courses> CanTeach;
    Echelon Ech;
    QByteArray photo;
    Kassen Versichern;
    PayKassen payKasse;
    QList<Unavailable> UnAvailability;

    int KasseID;
    QDate EndOfContract;
    QString AFM; //Greek SSN


    int TotalGroups;
    int TotalStudents;
    int CurrentGroups;
    int CurrentStudents;
    int TotalHours;



    //we need a history of teaching
    QList<Groups> HasTaught;

    QList<History> TeachingHistory;

    //payment history
    QList<Payments> PayHistory;

    //erlaubnis history
    QList<Erlaubnis> ErlaubHistory;




};

#endif // TEACHER_H
