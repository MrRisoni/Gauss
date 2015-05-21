#ifndef DEPARTMENTS_H
#define DEPARTMENTS_H


#include <QString>

class Departments
{
public:
    Departments();
    ~Departments();


    QString getDepName() const;
    void setDepName(const QString &value);

    int getDepID() const;
    void setDepID(int value);

private:
    int DepID;
    QString DepName;
};

#endif // DEPARTMENTS_H
