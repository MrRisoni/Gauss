#ifndef GROUPS_H
#define GROUPS_H

#include <QDate>

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



private:
    int GroupID;
    int teacherID;
    QList<int> meliID;
    int courseID;
    QDate StartDate;
    bool Active;
    int EduType;



};

#endif // GROUPS_H
