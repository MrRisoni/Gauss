#include <QDate>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Distances
#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <vector>
#include <limits>
#include <stdlib.h>
#include <math.h>
#include <QDebug>


using namespace std;


struct MoneyScheme {

       int Erfahurng; //months of working experience
       QDate dat;
       float Money;

};

   /* a history of the working hours
    01 January 2015 2 hours
    11 January 2015 1.0 hour
    21 January 2015 1.3 hours
    */

struct Lesson {

    int CourseID;
    QDate dat;
    float Duration;

 };





float CalculateBaseSalary(vector<MoneyScheme> Argent,vector<Lesson> Enseignment) {

    try {

        float sum = 0;

        for (Lesson less : Enseignment) {

            for (int i = 0; i < Argent.size() - 1; i++) {
                if ((Argent.at(i).dat.toJulianDay() < less.dat.toJulianDay() ) && (Argent.at(i + 1).dat.toJulianDay() > less.dat.toJulianDay())) {


                    //multiply with the lowest date
                    sum += less.Duration * Argent.at(i).Money;

                }

            }


        // check for equality between the less.dat and money.dat
            //BUT NOT WITH THE LAST ELEMENT!!!!!!
            for (int w=0;w<Argent.size()-1;w++) {
                if (Argent.at(w).dat.toJulianDay()==less.dat.toJulianDay())  {


                    sum += less.Duration * Argent.at(w).Money;

                }

            }


            //if its greater than the last date ...
            if (less.dat.toJulianDay() > (Argent.at(Argent.size() - 1).dat.toJulianDay())) {

                sum += less.Duration * Argent.at(Argent.size() - 1).Money;
            }


        }
        return sum;
    } catch (exception& ex) {
        qDebug() << ex.what();

        return -1.0;
    }
}






BOOST_AUTO_TEST_CASE(BaseSal)
{

    vector<MoneyScheme> Geld;
    vector<Lesson> Unterricht;



    MoneyScheme m;
    m.Money=8;
    // FORMAT Year,Month,Day
    m.dat= QDate(2015,01,10);
    Geld.push_back(m);



    m.Money=6;
    m.dat= QDate(2015,02,20);
    Geld.push_back(m);

    m.Money=5.5;
    m.dat= QDate(2015,04,20);
    Geld.push_back(m);




    qDebug() << m.dat.month();


    Lesson l;
    l.Duration=6;
    l.dat=QDate(2015,01,11);
    Unterricht.push_back(l);

    l.Duration=10;
    l.dat=QDate(2015,01,19);
    Unterricht.push_back(l);

    l.Duration=2;
    l.dat=QDate(2015,02,20);
    Unterricht.push_back(l);

    l.Duration=5;
    l.dat=QDate(2015,03,20);
    Unterricht.push_back(l);



    l.Duration=5;
    l.dat=QDate(2015,03,28);
    Unterricht.push_back(l);


    l.Duration=2;
    l.dat=QDate(2015,04,24);
    Unterricht.push_back(l);


    l.Duration=36.5;
    l.dat=QDate(2015,04,24);
    Unterricht.push_back(l);


    BOOST_CHECK_CLOSE(CalculateBaseSalary(Geld,Unterricht) , 411.75 , 0.01);

}


