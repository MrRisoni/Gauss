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
#include "permament.h"
#include "permatimes.h"
#include "discipline.h"
#include "discounttype.h"

#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QComboBox>


struct Zukunuft{
    std::vector<long> FutureJulianDays;
    std::vector<int> FutureRoomIDs;
    std::vector<int> FutureHourIDs;
    std::vector<float> Durations;
};




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
    void saveSchule(Groups g, Permament Perma, QList<Permatimes> Programma);
    void saveUni(Groups g);
    void saveSprache(Groups g);
    void saveSchuleStudent(Members m, QString kateuthinsi, QString specialcat);
    void save(Diplomas d);
    void save(Payments p);


    // get TableModels code
    QList<ManageCourseTable>  getManageCourseTable();
    //


    QList<Discipline> getDisciplines();
    QList<DiscountType> getDiscountTypes();

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
    QList<Days> getDays();
    QList<Hours> getHours();
    QList<WagesSchule> getWagesSchule();
    QList<Kassen> getKassen();
    QList<PayType> getPayTypes();


    QSqlDatabase getDb() const;
    void setDb(const QSqlDatabase &value);


    QString getSetFacesPath();


    //  MVC


    SchuleTeacherMVC getCanTeachSchuleMVC(QString CourseName);

    AddInstitutDialogMVC  getAddInstitutMVC();

    KassenMVC getKassenMVC();



    QPixmap getSignaturePic(QString TeacherID);



    void CancelLesson(QString GroupID,QList<QString> dats);
    void AddTempLesson(QString GroupID,QDate dat,QString hour,float duration);
    //check if overlap with add temporary lesson!!!!
    //bool checkOverlapWithTempLesson()

    //check if overlap with permaments :)
    //bool QtFoundOverlap(QList<QtFach> ExistingSchedules,QList<QtFach> NewSchedule) {

    Zukunuft createFutureDatesAndRooms(QList<Permatimes> Settings,QDate startDate,QDate endDate);

    void ShowError(QSqlQuery q);
    void ShowSuccess();
    QSqlDatabase db;
    QString generateADT();
    QString generateAFM();
    QString generatePhone();
    QString generateMobile();
    QString generateAMKA();
    QDate calcEOC(QString tid);






};

#endif // ORM_H
