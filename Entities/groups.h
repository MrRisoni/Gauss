#ifndef GROUPS_H
#define GROUPS_H

#include <QDate>

class Groups
{
public:
    Groups();
    ~Groups();
    int getGroupID() const;
    void setGroupID(int value);

    QDate getStartDate() const;
    void setStartDate(const QDate &value);

    bool getActive() const;
    void setActive(bool value);

    int getEduType() const;
    void setEduType(int value);



    QString getTeacherID() const;
    void setTeacherID(const QString &value);

    QString getTeacherName() const;
    void setTeacherName(const QString &value);

    QList<QString> getMeliID() const;
    void setMeliID(const QList<QString> &value);

    QString getCourseName() const;
    void setCourseName(const QString &value);

    int getEnsembleID() const;
    void setEnsembleID(int value);

private:
    int GroupID;
    QString teacherID;
    QString TeacherName;
    int EnsembleID;

    QList<QString> meliID;
    int courseID;
    QString CourseName;
    QString DepName;
    QString LangName;
    QDate StartDate;
    bool Active;
    int EduType;



};

#endif // GROUPS_H
