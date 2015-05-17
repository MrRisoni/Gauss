#ifndef TEACHER_H
#define TEACHER_H

#include "courses.h"
#include "basewages.h"
#include "unavailable.h"
#include "kassen.h"
#include "members.h"
#include "paykassen.h"

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

private:
    BaseWages base_wages;
    QList<Courses> CanTeach;
    Echelon Ech;
    QByteArray photo;
    Kassen Versichern;
    PayKassen payKasse;
    QList<Unavailable> UnAvailability;

    QDate EndOfContract;





};

#endif // TEACHER_H
