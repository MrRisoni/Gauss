#ifndef ORM_H
#define ORM_H

#include "schwierigkeit.h"
#include "departments.h"
#include "courses.h"
#include "echelon.h"
#include "basewages.h"
#include "wagesschule.h"
#include "members.h"
#include "teacher.h"
#include "languages.h"
#include "diplomas.h"
#include "basewages.h"
#include "days.h"
#include "hours.h"
#include "kassen.h"

#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>


class ORM
{
public:
    ORM();
    ~ORM();

    void save(Schwierigkeit schw);
    void save(Departments D);
    void save(Courses C);
    void save(Echelon E);
    void save(BaseWages BW);
    void save(WagesSchule WGS);
    void saveStudent(Members m);
    void save(Kassen K);
    void saveTeacher(Teacher T);



    QList<Schwierigkeit> getSchwer();
    QList<Departments> getDeps();
    QList<Echelon> getEchels();
    QList<Courses> getSchuleCourses();
    QList<Languages> getSprachen();
    QList<Diplomas> getDiplomas();
    QList<Courses> getSpecialCourses(QString DepName);
    QList<BaseWages> getBaseWages();
    QList<Days> getDays();
    QList<Hours> getHours();
    QList<WagesSchule> getWagesSchule();
    QList<Kassen> getKassen();


private:
    void ShowError(QSqlQuery q);
    void ShowSuccess();


};

#endif // ORM_H
