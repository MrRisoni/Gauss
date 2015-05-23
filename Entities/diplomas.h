#ifndef DIPLOMAS_H
#define DIPLOMAS_H

#include <QString>


class Diplomas
{
public:
    Diplomas();
    ~Diplomas();



    int getActive() const;
    void setActive(int value);

    QString getName() const;
    void setName(const QString &value);

    QString getLanguage() const;
    void setLanguage(const QString &value);

    QString getInstitutName() const;
    void setInstitutName(const QString &value);

    QString getSchwerID() const;
    void setSchwerID(const QString &value);

private:
    QString Language;
    int Active;
    QString InstitutName;
    QString Name;
    QString SchwerID;


};

#endif // DIPLOMAS_H
