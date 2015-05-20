#include "buildings.h"

Buildings::Buildings()
{

}

Buildings::~Buildings()
{

}
int Buildings::getBuildingID() const
{
    return BuildingID;
}

void Buildings::setBuildingID(int value)
{
    BuildingID = value;
}
QString Buildings::getName() const
{
    return Name;
}

void Buildings::setName(const QString &value)
{
    Name = value;
}
int Buildings::getRoomsNum() const
{
    return RoomsNum;
}

void Buildings::setRoomsNum(int value)
{
    RoomsNum = value;
}




