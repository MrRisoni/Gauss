#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();

    int Day; // an int representing the day 0 is Sunday 1 Monday etc
    float StartHour; // Hour e.g 9 to 22 step 0.5 aka 30 minutes maybe use real minutes it will be easier
    int BuildingID;
};

#endif // POINT_H
