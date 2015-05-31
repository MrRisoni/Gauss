#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE Main
#endif

#include <boost/test/unit_test.hpp>

#include <QDate>
#include <vector>
#include <QStringList>
#include <QDebug>







//copys a permament course into a history table until a specific date

std::vector<long> createHistory(QList<int> DayIDs,QDate startDate,QDate endDate) {

    //qDebug() << "************** COPY TO HISTORY TEST **************";
    //creates a list of dates , whoose id is DayID, starting from today until endDate
    std::vector<long> V;
    //dont return QDates boost does not know how to output QDate and
    // i don't know how to tell Boost how to print one

    QStringList StringDays;
     StringDays.append("Sunday");
     StringDays.append("Monday");
     StringDays.append("Tuesday");
     StringDays.append("Wednesday");
     StringDays.append("Thursday");
     StringDays.append("Friday");
     StringDays.append("Saturday");



//this test is supposed to start at Sunday 31/05/15
    int TodayID =1; //  StringDays.indexOf(QDate::longDayName(QDate::currentDate().dayOfWeek()));


    //qDebug() << TodayID;

    //DayID ==1 is sunday
    int duration = endDate.toJulianDay() - startDate.toJulianDay();

    long StartJul =2457174; // startDate.toJulianDay(); // the start day in julian day

    for (long i=TodayID;i<duration;i++) {
        //all days must be equal to DayIDs

        int nextday = i % 7 ; //seven are the days of the week
        //in 15 days from now there will be again the same TodayID because the modulo will be zero

        //check if next day exists in the list
        if (DayIDs.contains(nextday)==true) {
            //create a day from startJul
            V.push_back(QDate::fromJulianDay(StartJul).toJulianDay());
           // qDebug() << "out " << QDate::fromJulianDay(StartJul);

        }

        StartJul++;
    }

    return V;
}











struct Zukunuft{
    std::vector<long> FutureJulianDays;
    std::vector<int> FutureRoomIDs;
    std::vector<int> FutureHourIDs;
};

struct PermaSettings { //settings for the course
    int DayID;
    int HourID;
    int RoomID;
};



/*  copys a permament course into a history table until a specific date
    THIS FUNCTION CALCULATES THE RoomIDs as well
    returns a vector of long dates,a vector of start hours for that day , and a vector for the roomid
    ASSUMPTION THE CLASS ALWAYS STAYS IN THE SAME ROOM DURING THR LRSSON
*/

Zukunuft createFutureDatesAndRooms(QList<PermaSettings> Settings,QDate startDate,QDate endDate) {

    //qDebug() << "************** COPY TO HISTORY TEST **************";
    //creates a list of dates , whoose id is DayID, starting from today until endDate
    std::vector<long> V;
    std::vector<int> Domatia;
    std::vector<int> Ores;




    Zukunuft Mellon;

    //dont return QDates boost does not know how to output QDate and
    // i don't know how to tell Boost how to print one

    QStringList StringDays;
     StringDays.append("Sunday");
     StringDays.append("Monday");
     StringDays.append("Tuesday");
     StringDays.append("Wednesday");
     StringDays.append("Thursday");
     StringDays.append("Friday");
     StringDays.append("Saturday");



//this test is supposed to start at Sunday 31/05/15
    int TodayID =1; //  StringDays.indexOf(QDate::longDayName(QDate::currentDate().dayOfWeek()));


    //qDebug() << TodayID;

    //DayID ==1 is sunday
    int duration = endDate.toJulianDay() - startDate.toJulianDay();

    long StartJul =2457174; // startDate.toJulianDay(); // the start day in julian day

    for (long i=TodayID;i<duration;i++) {
        //all days must be equal to DayIDs

        int nextday = i % 7 ; //seven are the days of the week
        //in 15 days from now there will be again the same TodayID because the modulo will be zero

        //check if next day exists in the list Settings

        for (PermaSettings p : Settings) {
            if (p.DayID==nextday) {
            //create a day from startJul
            V.push_back(QDate::fromJulianDay(StartJul).toJulianDay());
           // qDebug() << "out " << QDate::fromJulianDay(StartJul);
             Ores.push_back(p.HourID);
             Domatia.push_back(p.RoomID);
            }
        }

        StartJul++;
    }


    Mellon.FutureHourIDs=Ores;
    Mellon.FutureJulianDays=V;
    Mellon.FutureRoomIDs=Domatia;
    return Mellon;
}






BOOST_AUTO_TEST_SUITE(CopyDaysRoomsHoursToHist)



BOOST_AUTO_TEST_CASE(hist_one)
{


    std::vector<long> ShouldReturnDays;

    std::vector<int> ShouldBeHours;
    std::vector<int> ShouldBeRooms;

    QList<PermaSettings> Sets;

    //course takes place at Monday at 0830 at room 3
    PermaSettings p;
    p.DayID=2;
    p.HourID=3;
    p.RoomID=5;

    Sets.append(p);

    ShouldReturnDays.push_back(QDate(2015,6,1).toJulianDay());
    ShouldReturnDays.push_back(QDate(2015,6,8).toJulianDay());
    ShouldReturnDays.push_back(QDate(2015,6,15).toJulianDay());
    ShouldReturnDays.push_back(QDate(2015,6,22).toJulianDay());
    ShouldReturnDays.push_back(QDate(2015,6,29).toJulianDay());
    ShouldReturnDays.push_back(QDate(2015,7,6).toJulianDay());
    ShouldReturnDays.push_back(QDate(2015,7,13).toJulianDay());
    ShouldReturnDays.push_back(QDate(2015,7,20).toJulianDay());
    ShouldReturnDays.push_back(QDate(2015,7,27).toJulianDay());
    ShouldReturnDays.push_back(QDate(2015,8,3).toJulianDay());
    ShouldReturnDays.push_back(QDate(2015,8,10).toJulianDay());
    ShouldReturnDays.push_back(QDate(2015,8,17).toJulianDay());
    ShouldReturnDays.push_back(QDate(2015,8,24).toJulianDay());
    ShouldReturnDays.push_back(QDate(2015,8,31).toJulianDay());
    ShouldReturnDays.push_back(QDate(2015,9,7).toJulianDay());

    for (int i=0;i<ShouldReturnDays.size();i++) {

        ShouldBeHours.push_back(3);
        ShouldBeRooms.push_back(5);
    }




    Zukunuft Gott=  createFutureDatesAndRooms(Sets,QDate(2015,5,31), QDate(2015,9,11));


    //check days
    BOOST_CHECK_EQUAL_COLLECTIONS(Gott.FutureJulianDays.begin(),Gott.FutureJulianDays.end(),ShouldReturnDays.begin(),ShouldReturnDays.end());

    //check rooms
    BOOST_CHECK_EQUAL_COLLECTIONS(Gott.FutureRoomIDs.begin(),Gott.FutureRoomIDs.end(),ShouldBeRooms.begin(),ShouldBeRooms.end());


    //check hours
    BOOST_CHECK_EQUAL_COLLECTIONS(Gott.FutureHourIDs.begin(),Gott.FutureHourIDs.end(),ShouldBeHours.begin(),ShouldBeHours.end());

}





BOOST_AUTO_TEST_CASE(test_more_days)
{



    std::vector<int> ShouldBeHours;
    std::vector<int> ShouldBeRooms;

    QList<PermaSettings> Sets;

    //course takes place at Monday at 0830 at room 3
    PermaSettings p=PermaSettings();
    p.DayID=2;
    p.HourID=3;
    p.RoomID=5;

    Sets.append(p);


     //and at Thursday at 1130 at room 8

    p=PermaSettings();
    p.DayID=5;
    p.HourID=7;
    p.RoomID=12;

    Sets.append(p);


    std::vector<long> ShouldReturn;

    ShouldReturn.push_back(QDate(2015,6,1).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,4).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,8).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,11).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,15).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,18).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,22).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,25).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,29).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,2).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,6).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,9).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,13).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,16).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,20).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,23).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,27).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,30).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,3).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,6).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,10).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,13).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,17).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,20).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,24).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,27).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,31).toJulianDay());
    ShouldReturn.push_back(QDate(2015,9,3).toJulianDay());
    ShouldReturn.push_back(QDate(2015,9,7).toJulianDay());


    // two days monday thursday abwechselnd ...
    for (int q=0;q<ShouldReturn.size();q++) {
        if ((q % 2 ==0 ) || (q==0) ) {
            ShouldBeHours.push_back(3);
            ShouldBeRooms.push_back(5);
        }
        else {
            ShouldBeHours.push_back(7);
            ShouldBeRooms.push_back(12);

        }

    }






    Zukunuft Gott=  createFutureDatesAndRooms(Sets,QDate(2015,5,31), QDate(2015,9,11));


    //check days
    BOOST_CHECK_EQUAL_COLLECTIONS(Gott.FutureJulianDays.begin(),Gott.FutureJulianDays.end(),ShouldReturn.begin(),ShouldReturn.end());

    //check rooms
    BOOST_CHECK_EQUAL_COLLECTIONS(Gott.FutureRoomIDs.begin(),Gott.FutureRoomIDs.end(),ShouldBeRooms.begin(),ShouldBeRooms.end());


    //check hours
    BOOST_CHECK_EQUAL_COLLECTIONS(Gott.FutureHourIDs.begin(),Gott.FutureHourIDs.end(),ShouldBeHours.begin(),ShouldBeHours.end());

}







BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CopyToHist)


BOOST_AUTO_TEST_CASE(hist_one)
{


    QList<int> meres;
    meres.append(2);  // a course takes place on Monday

    std::vector<long> ShouldReturn;

    ShouldReturn.push_back(QDate(2015,6,1).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,8).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,15).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,22).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,29).toJulianDay());


    ShouldReturn.push_back(QDate(2015,7,6).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,13).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,20).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,27).toJulianDay());

    ShouldReturn.push_back(QDate(2015,8,3).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,10).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,17).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,24).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,31).toJulianDay());


    ShouldReturn.push_back(QDate(2015,9,7).toJulianDay());




    std::vector<long> Got= createHistory(meres, QDate(2015,5,31), QDate(2015,9,11));



    BOOST_CHECK_EQUAL_COLLECTIONS(Got.begin(),Got.end(),ShouldReturn.begin(),ShouldReturn.end());
}




BOOST_AUTO_TEST_CASE(hist_two)
{


    QList<int> meres;
    meres.append(2);  // a course takes place on Monday and thursday
    meres.append(5);
    std::vector<long> ShouldReturn;

    ShouldReturn.push_back(QDate(2015,6,1).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,4).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,8).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,11).toJulianDay());

    ShouldReturn.push_back(QDate(2015,6,15).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,18).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,22).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,25).toJulianDay());
    ShouldReturn.push_back(QDate(2015,6,29).toJulianDay());




    ShouldReturn.push_back(QDate(2015,7,2).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,6).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,9).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,13).toJulianDay());

    ShouldReturn.push_back(QDate(2015,7,16).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,20).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,23).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,27).toJulianDay());
    ShouldReturn.push_back(QDate(2015,7,30).toJulianDay());

    ShouldReturn.push_back(QDate(2015,8,3).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,6).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,10).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,13).toJulianDay());



    ShouldReturn.push_back(QDate(2015,8,17).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,20).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,24).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,27).toJulianDay());
    ShouldReturn.push_back(QDate(2015,8,31).toJulianDay());



    ShouldReturn.push_back(QDate(2015,9,3).toJulianDay());
    ShouldReturn.push_back(QDate(2015,9,7).toJulianDay());











    std::vector<long> Got= createHistory(meres, QDate(2015,5,31), QDate(2015,9,11));



   BOOST_CHECK_EQUAL_COLLECTIONS(Got.begin(),Got.end(),ShouldReturn.begin(),ShouldReturn.end());
}


BOOST_AUTO_TEST_SUITE_END()
