#ifndef ORM_H
#define ORM_H


#include "tablestructs.h"

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
#include "requestschule.h"
#include "buildings.h"
#include "rooms.h"
#include "feeschule.h"
#include "groups.h"
#include "payments.h"
#include "paytype.h"

#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QComboBox>


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
    void save(RequestSchule rec);
    void save(Buildings B);
    void save(Rooms R);
    void save(FeeSchule fsh);
    void saveSchule(Groups g);
    void saveUni(Groups g);
    void saveSprache(Groups g);
    void saveSchuleStudent(Members m);
    void save(Diplomas d);
    void save(Payments p);


    // get TableModels code
    QList<ManageCourseTable>  getManageCourseTable();
    //

    QList<Teacher> getCanTeachUni(QString DepName, QString CourseName);
    QList<Members> getRequestsUni(QString DepName, QString CourseName);



    QList<Teacher> getCanTeachThis(QString CourseName);
    QList<Members> getRequestsSchule(QString CourseName);



   TimeTableHeaders getTimeTableHeaders();


    QList<Rooms> getRooms();
    QList<Buildings> getBuildings();
    Members searchStudentByName(QString name);
    Teacher searchteacherByname(QString name);
    QList<Schwierigkeit> getSchwer();
    QList<Departments> getDeps();
    QList<Echelon> getEchels();
    QList<Courses> getSchuleCourses();

    //return a combo box with rgb schwierigkeit colors :)
    QList<Courses> getUniCourses(QString DepName);
    QComboBox* getComboUniCourses(QString DepName);


    QList<Languages> getSprachen();
    QList<Diplomas> getDiplomas();
    QList<Courses> getSpecialCourses(QString DepName);
    QList<BaseWages> getBaseWages();
    QList<Days> getDays();
    QList<Hours> getHours();
    QList<WagesSchule> getWagesSchule();
    QList<Kassen> getKassen();
    QList<PayType> getPayTypes();


    QSqlDatabase getDb() const;
    void setDb(const QSqlDatabase &value);





    //  MVC

    FeeSchuleMVC  getManageFeeSchuleMVC();

    SchuleTeacherMVC getCanTeachSchuleMVC(QString CourseName);

    AddInstitutDialogMVC  getAddInstitutMVC();
    AddSchwerDialogMVC getSchwerMVC();

    KassenMVC getKassenMVC();


    DiplomaModelMVC getDiplomaMVC();

private:
    void ShowError(QSqlQuery q);
    void ShowSuccess();
    QSqlDatabase db;
    QString generateADT();
    QString generateAFM();
    QString generatePhone();
    QString generateMobile();
    QDate calcEOC(QString tid);






};

#endif // ORM_H
