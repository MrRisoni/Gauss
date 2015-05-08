#ifndef ORM_H
#define ORM_H

#include "schwierigkeit.h"
#include "departments.h"
#include "courses.h"


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

    QList<Schwierigkeit> getSchwer();
    QList<Departments> getDeps();

private:
    void ShowError(QSqlQuery q);
    void ShowSuccess();


};

#endif // ORM_H
