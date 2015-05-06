#ifndef ORM_H
#define ORM_H

#include "schwierigkeit.h"
#include "departments.h"


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

    QList<Schwierigkeit> getSchwer();
    QList<Departments> getDeps();

private:
    void ShowError(QSqlQuery q);

};

#endif // ORM_H
