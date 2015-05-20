#include "diplomas.h"

Diplomas::Diplomas()
{

}

Diplomas::~Diplomas()
{

}
Languages Diplomas::getLang() const
{
    return lang;
}

void Diplomas::setLang(const Languages &value)
{
    lang = value;
}
Instituts Diplomas::getIns() const
{
    return Ins;
}

void Diplomas::setIns(const Instituts &value)
{
    Ins = value;
}
int Diplomas::getActive() const
{
    return Active;
}

void Diplomas::setActive(int value)
{
    Active = value;
}
QString Diplomas::getName() const
{
    return Name;
}

void Diplomas::setName(const QString &value)
{
    Name = value;
}





