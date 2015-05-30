#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE Main
#endif

#include <boost/test/unit_test.hpp>
#include <vector>
#include <limits>
#include <stdlib.h>
#include <math.h>
#include <QDate>
#include "old_salary_structs.h"








float CalculateBaseSalary(std::vector<MoneyScheme> Argent,std::vector<Lesson> Enseignment) {

    try {

        float sum = 0;

        for (Lesson less : Enseignment) {

            for (unsigned int i = 0; i < Argent.size() - 1; i++) {
                if ((Argent.at(i).dat.toJulianDay() < less.dat.toJulianDay() ) && (Argent.at(i + 1).dat.toJulianDay() > less.dat.toJulianDay())) {


                    //multiply with the lowest date
                    sum += less.Duration * Argent.at(i).Money;

                }

            }


            // check for equality between the less.dat and money.dat
            //BUT NOT WITH THE LAST ELEMENT!!!!!!
            for (unsigned int w=0;w<Argent.size()-1;w++) {
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
    } catch (std::exception& ex) {
        qDebug() << ex.what();

        return -1.0;
    }
}



BOOST_AUTO_TEST_SUITE(misthos)



BOOST_AUTO_TEST_CASE(std_BaseSal)
{

    std::vector<MoneyScheme> Geld;
    std::vector<Lesson> Unterricht;



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

BOOST_AUTO_TEST_SUITE_END()
