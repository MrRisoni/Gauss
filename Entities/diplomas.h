#ifndef DIPLOMAS_H
#define DIPLOMAS_H

#include "languages.h"
#include "schwierigkeit.h"
#include "instituts.h"

class Diplomas
{
public:
    Diplomas();
    ~Diplomas();
    Languages getLang() const;
    void setLang(const Languages &value);

    Instituts getIns() const;
    void setIns(const Instituts &value);

    int getActive() const;
    void setActive(int value);

    QString getName() const;
    void setName(const QString &value);

private:
    Languages lang;
    Instituts Ins;
    int Active;
    QString Name;

};

#endif // DIPLOMAS_H
