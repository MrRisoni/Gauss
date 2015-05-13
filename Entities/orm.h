#ifndef ORM_H
#define ORM_H

#include "schwierigkeit.h"
#include "departments.h"
#include "courses.h"
#include "echelon.h"
#include "basewages.h"
#include "wagesschule.h"

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




    QList<Schwierigkeit> getSchwer();
    QList<Departments> getDeps();
    QList<Echelon> getEchels();
    QList<Courses> getSchuleCourses();

private:
    void ShowError(QSqlQuery q);
    void ShowSuccess();


};

#endif // ORM_H
