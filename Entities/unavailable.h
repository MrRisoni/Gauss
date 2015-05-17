#ifndef UNAVAILABLE_H
#define UNAVAILABLE_H

#include "days.h"
#include  "hours.h"

class Unavailable
{
public:
    Unavailable();
    ~Unavailable();
    Days getTag() const;
    void setTag(const Days &value);

    Hours getStartStude() const;
    void setStartStude(const Hours &value);

    float getDuration() const;
    void setDuration(float value);

private:
    Days Tag; //what day can toy not work
    Hours StartStude; //start hour
    float Duration; // THIS IS IN HALF HOURS...
};

#endif // UNAVAILABLE_H
