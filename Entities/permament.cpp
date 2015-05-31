#include "permament.h"

Permament::Permament()
{

}

Permament::~Permament()
{

}
int Permament::getGroupID() const
{
    return GroupID;
}

void Permament::setGroupID(int value)
{
    GroupID = value;
}
QDate Permament::getStarts() const
{
    return starts;
}

void Permament::setStarts(const QDate &value)
{
    starts = value;
}
QDate Permament::getEnds() const
{
    return ends;
}

void Permament::setEnds(const QDate &value)
{
    ends = value;
}
int Permament::getPermaID() const
{
    return PermaID;
}

void Permament::setPermaID(int value)
{
    PermaID = value;
}





