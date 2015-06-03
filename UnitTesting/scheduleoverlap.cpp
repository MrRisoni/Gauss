#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE Main
#endif



#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <QList>
#include <QDate>

//given a list of dates,rooms,hours test overlap algorithm
//this is the permement table
//the only difference with the add temporary function is the comparison of dates
struct Fach {
    short DayID;
    short RoomID;
    short StartHour;
    float Duration;
};


short SegmentOverpap(short a_start,short a_end,short b_start,short b_end) {
    return std::max(0, std::min(a_end, b_end) - std::max(a_start, b_start));

}

bool FoundOverlap(QList<Fach> ExistingSchedules,QList<Fach> NewSchedule) {
    bool problem = false;

    for (Fach exF : ExistingSchedules) {

        for (Fach newF : NewSchedule) {
            //check of dayid
            if (newF.DayID==exF.DayID) {
                //check room id
                if (newF.RoomID==exF.RoomID) {
                    //finally check hours
                    if (SegmentOverpap(newF.StartHour,newF.StartHour+newF.Duration,exF.StartHour,exF.StartHour+exF.Duration)>0) {
                       //exit since you found at least one overlap
                        return true;

                    }
                }

            }
        }
    }


    return problem;
}




struct QtFach {
    QDate dat;
    short RoomID;
    short StartHour;
    float Duration;
};






bool QtFoundOverlap(QList<QtFach> ExistingSchedules,QList<QtFach> NewSchedule) {
    bool problem = false;

    for (QtFach exF : ExistingSchedules) {

        for (QtFach newF : NewSchedule) {
            //check of dayid
            if (newF.dat == exF.dat) {
                //check room id
                if (newF.RoomID==exF.RoomID) {
                    //finally check hours
                    if (SegmentOverpap(newF.StartHour,newF.StartHour+newF.Duration,exF.StartHour,exF.StartHour+exF.Duration)>0) {
                       //exit since you found at least one overlap
                        return true;

                    }
                }

            }
        }
    }


    return problem;
}





BOOST_AUTO_TEST_SUITE(epikalypsi)


BOOST_AUTO_TEST_CASE(dif_all)
{

    QList<Fach> existing;
    QList<Fach> nouveau;

    Fach exF=Fach();
    exF.DayID=1;
    exF.RoomID=12;
    exF.StartHour=5;
    exF.Duration=2.5;

    existing.append(exF);

    exF=Fach();
    exF.DayID=6;
    exF.RoomID=8;
    exF.StartHour=6;
    exF.Duration=3.5;

    existing.append(exF);


    //------------------------

    Fach newF=Fach();
    newF.DayID=1;
    newF.RoomID=12;
    newF.StartHour=10;
    newF.Duration=3.5;

    nouveau.append(newF);

    newF=Fach();
    newF.DayID=9;
    newF.RoomID=1;
    newF.StartHour=6;
    newF.Duration=3.5;


    nouveau.append(newF);


    BOOST_CHECK_EQUAL(false,FoundOverlap(existing,nouveau));


}



BOOST_AUTO_TEST_CASE(same_hour__diff_rooms)
{

    QList<Fach> existing;
    QList<Fach> nouveau;

    Fach exF=Fach();
    exF.DayID=1;
    exF.RoomID=12;
    exF.StartHour=5;
    exF.Duration=2.5;

    existing.append(exF);

    exF=Fach();
    exF.DayID=6;
    exF.RoomID=8;
    exF.StartHour=6;
    exF.Duration=3.5;

    existing.append(exF);


    //------------------------

    Fach newF=Fach();
    newF.DayID=1;
    newF.RoomID=3;
    newF.StartHour=5;
    newF.Duration=2.5;

    nouveau.append(newF);

    newF=Fach();
    newF.DayID=6;
    newF.RoomID=9;
    newF.StartHour=6;
    newF.Duration=3.5;


    nouveau.append(newF);


    BOOST_CHECK_EQUAL(false,FoundOverlap(existing,nouveau));


}





BOOST_AUTO_TEST_CASE(overlap_last)
{

    QList<Fach> existing;
    QList<Fach> nouveau;

    Fach exF=Fach();
    exF.DayID=1;
    exF.RoomID=12;
    exF.StartHour=5;
    exF.Duration=2.5;

    existing.append(exF);

    exF=Fach();
    exF.DayID=6;
    exF.RoomID=8;
    exF.StartHour=6;
    exF.Duration=4;

    existing.append(exF);


    //------------------------

    Fach newF=Fach();
    newF.DayID=1;
    newF.RoomID=12;
    newF.StartHour=10;
    newF.Duration=3.5;

    nouveau.append(newF);

    newF=Fach();
    newF.DayID=6;
    newF.RoomID=8;
    newF.StartHour=9;
    newF.Duration=3.5;


    nouveau.append(newF);


    BOOST_CHECK_EQUAL(true,FoundOverlap(existing,nouveau));

}




BOOST_AUTO_TEST_CASE(qt_overlap_last)
{

    QList<QtFach> existing;
    QList<QtFach> nouveau;

    QtFach exF=QtFach();
    exF.dat=QDate(2015,06,02);
    exF.RoomID=12;
    exF.StartHour=5;
    exF.Duration=2.5;

    existing.append(exF);

    exF=QtFach();
    exF.dat=QDate(2015,06,22);
    exF.RoomID=8;
    exF.StartHour=6;
    exF.Duration=4;

    existing.append(exF);


    //------------------------

    QtFach newF=QtFach();
    newF.dat=QDate(2015,06,12);
    newF.RoomID=12;
    newF.StartHour=10;
    newF.Duration=3.5;

    nouveau.append(newF);

    newF=QtFach();
    newF.dat=QDate(2015,06,22);
    newF.RoomID=8;
    newF.StartHour=9;
    newF.Duration=3.5;


    nouveau.append(newF);


    BOOST_CHECK_EQUAL(true,QtFoundOverlap(existing,nouveau));

}

BOOST_AUTO_TEST_SUITE_END()
