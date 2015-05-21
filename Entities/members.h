#ifndef MEMBERS_H
#define MEMBERS_H

#include <QString>
#include <QDate>

class Members
{
public:
    Members();
    ~Members();

    QString getName() const;
    void setName(const QString &value);

    QString getFName() const;
    void setFName(const QString &value);

    QString getMName() const;
    void setMName(const QString &value);

    QString getAddress() const;
    void setAddress(const QString &value);

    QString getMobile() const;
    void setMobile(const QString &value);

    QString getEmail() const;
    void setEmail(const QString &value);

    QDate getRegDate() const;
    void setRegDate(const QDate &value);

    QDate getBirthDate() const;
    void setBirthDate(const QDate &value);

    QString getPhone() const;
    void setPhone(const QString &value);

    QString getADT() const;
    void setADT(const QString &value);





    int getMembID() const;
    void setMembID(int value);

private:
    int MembID;
    QString Name;
    QString FName;
    QString MName;
    QString Address;
    QString Phone;
    QString Mobile;
    QString Email;
    QDate RegDate;
    QDate BirthDate;
    float TotHours;
    float TotPaidHours;
    QString ADT; // AusweisID



};

#endif // MEMBERS_H
