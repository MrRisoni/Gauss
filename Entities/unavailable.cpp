#include "unavailable.h"

Unavailable::Unavailable()
{

}

Unavailable::~Unavailable()
{

}
Days Unavailable::getTag() const
{
    return Tag;
}

void Unavailable::setTag(const Days &value)
{
    Tag = value;
}
Hours Unavailable::getStartStude() const
{
    return StartStude;
}

void Unavailable::setStartStude(const Hours &value)
{
    StartStude = value;
}
float Unavailable::getDuration() const
{
    return Duration;
}

void Unavailable::setDuration(float value)
{
    Duration = value;
}




