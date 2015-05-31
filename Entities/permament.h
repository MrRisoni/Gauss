#ifndef PERMAMENT_H
#define PERMAMENT_H


#include <QDate>


class Permament
{
public:
    Permament();
    ~Permament();
    int getGroupID() const;
    void setGroupID(int value);

    QDate getStarts() const;
    void setStarts(const QDate &value);

    QDate getEnds() const;
    void setEnds(const QDate &value);

    int getPermaID() const;
    void setPermaID(int value);

private:
    int PermaID;
    int GroupID;
    QDate starts;
    QDate ends;
};

#endif // PERMAMENT_H
