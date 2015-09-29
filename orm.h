

#include "Entities/tablestructs.h"
#include "Entities/departments.h"
#include "Entities/courses.h"
#include "Entities/echelon.h"
#include "Entities/basewages.h"
#include "Entities/wagesschule.h"
#include "Entities/members.h"
#include "Entities/teacher.h"
#include "Entities/languages.h"
#include "Entities/diplomas.h"
#include "Entities/basewages.h"
#include "Entities/days.h"
#include "Entities/hours.h"
#include "Entities/kassen.h"
#include "Entities/requests.h"
#include "Entities/buildings.h"
#include "Entities/rooms.h"
#include "Entities/feeschule.h"
#include "Entities/groups.h"
#include "Entities/payments.h"
#include "Entities/paytype.h"
#include "Entities/permament.h"
#include "Entities/permatimes.h"
#include "Entities/discipline.h"
#include "Entities/discounttype.h"
#include "Entities/student.h"
#include "Entities/funds.h"




#include <exception>
#include <iostream>
#include <QFile>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QComboBox>

namespace ORM {

  
    struct Zukunuft{
        std::vector<long> FutureJulianDays;
        std::vector<int> FutureRoomIDs;
        std::vector<int> FutureHourIDs;
        std::vector<float> Durations;
    };








    void save(Funds f);
    void save(Schwierigkeit schw);
    void save(Departments D);
    void save(Courses C);
    void save(Echelon E);
    void save(BaseWages BW);
    void save(WagesSchule WGS);
    void saveStudent(Members m);
    void save(Kassen K);
    void saveTeacher(Teacher T);
    void save(Requests rec);
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
    Student searchStudentByADT(QString adt);
    Teacher searchteacherByname(QString name);
    QList<Schwierigkeit> getSchwer();
    QList<Departments> getDeps();
    QList<Echelon> getEchels();
    QList<Courses> getSchuleCourses();

    //return a combo box with rgb schwierigkeit colors :)
    QList<Courses> getUniCourses(QString DepName);
    QComboBox* getComboUniCourses(QString DepName);


    QList<Languages> getSprachen();
    QList<QString> getDiplomaForThatLanguage(QString SprachName);

    QList<Diplomas> getDiplomas();
    QList<Courses> getSpecialCourses(QString DepName);
    QList<Days> getDays();
    QList<Hours> getHours();
    QList<WagesSchule> getWagesSchule();
    QList<Kassen> getKassen();
    QList<PayType> getPayTypes();






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
    QString generateADT();
    QString generateAFM();
    QString generatePhone();
    QString generateMobile();
    QString generateAMKA();
    QDate calcEOC(QString tid);






} //END OF NAMESPACE


