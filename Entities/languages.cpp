#include "languages.h"

Languages::Languages()
{

}

Languages::~Languages()
{

}
QString Languages::getName() const
{
    return Name;
}

void Languages::setName(const QString &value)
{
    Name = value;
}


