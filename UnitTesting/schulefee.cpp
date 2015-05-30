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
#include "feestructs.h"
#include "oldcode/old_salary_structs.h"




float CalcDiscount(QList<MonthlyFee> fees,QList<Discount> disc_monats,QDate Expires,QList<Lesson> mathimata) {
    // accumulated fees for each month , latest discounts for each month , expired date for the discount
    float total_discount=0;



    for (MonthlyFee monat : fees) {
        //for each month
        //find the discount for that month
        for (Discount disc : disc_monats ) {

            //calculate seperately the expired month !!!!

            if ((disc.dat.year()==monat.dat.year()) && (disc.dat.month()==monat.dat.month())) {

                //check for expire
                if ((Expires.year()!=monat.dat.year()) && (Expires.month()!=monat.dat.month()) ) {
                     total_discount -= disc.disc;
                }
                //if they are the same ?????
                //calculate fee for that date
                total_discount += CalculateFeeForThisDate(Expires,mathimata);
            }
        }
    }

    return total_discount; //assert negative


}




QList<MonthlyFee> CalculateSchuleFee(QList<FeeSchule> SchuleSchemes,QList<Lesson> mathimata) {
    //schule will be always sorted by date and course



}
