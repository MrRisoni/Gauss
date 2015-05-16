#ifndef LANGUAGES_H
#define LANGUAGES_H

#include <QString>

class Languages
{
public:
    Languages();
    ~Languages();
    QString getName() const;
    void setName(const QString &value);

private:
    int LanguageID;
    QString Name;
};

#endif // LANGUAGES_H
