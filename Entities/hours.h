#ifndef HOURS_H
#define HOURS_H

#include <QString>

class Hours
{
public:
    Hours();
    ~Hours();

    int getHourID() const;
    void setHourID(int value);

    QString getName() const;
    void setName(const QString &value);

private:
    int HourID;
    QString Name;
};

#endif // HOURS_H
