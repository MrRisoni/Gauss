#ifndef SALARY_STRUCTS
#define SALARY_STRUCTS



#define BOOST_TEST_DYN_LINK
#ifdef STAND_ALONE
#   define BOOST_TEST_MODULE Main
#endif

#include <boost/test/unit_test.hpp>
#include <vector>
#include <limits>
#include <stdlib.h>
#include <math.h>
#include <QDebug>
#include <QDate>
#include <QList>



struct MoneyScheme {

    int Erfahrung; //months of working experience
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




#endif // SALARY_STRUCTS

