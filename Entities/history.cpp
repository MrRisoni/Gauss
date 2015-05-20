#include "history.h"

History::History()
{

}

History::~History()
{

}
int History::getHistID() const
{
    return HistID;
}

void History::setHistID(int value)
{
    HistID = value;
}
int History::getGroupID() const
{
    return GroupID;
}

void History::setGroupID(int value)
{
    GroupID = value;
}
QDate History::getDat() const
{
    return dat;
}

void History::setDat(const QDate &value)
{
    dat = value;
}
QString History::getHour() const
{
    return Hour;
}

void History::setHour(const QString &value)
{
    Hour = value;
}
float History::getDuration() const
{
    return Duration;
}

void History::setDuration(float value)
{
    Duration = value;
}
int History::getRoomID() const
{
    return RoomID;
}

void History::setRoomID(int value)
{
    RoomID = value;
}
Rooms History::getR() const
{
    return R;
}

void History::setR(const Rooms &value)
{
    R = value;
}








