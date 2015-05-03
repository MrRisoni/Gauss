#ifndef ORM_H
#define ORM_H

#include "schwierigkeit.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>


class ORM
{
public:
    ORM();
    ~ORM();

    int save(Schwierigkeit schw);


};

#endif // ORM_H
