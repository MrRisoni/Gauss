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




float CalcDiscount(QList<MonthlyFee> fees,QList<Discount> disc_monats,QDate Expires) {
    // accumulated fees for each month , latest discounts for each month , expired date for the discount
    float total_discount=0;

    for (MonthlyFee monat : fees) {
        //for each month
        //find the discount for that month
        for (Discount disc :disc_monats ) {
            if (disc.MonthID==monat.MonthID) {
                total_discount -= disc.disc
            }
        }
    }

    return total; //assert negative


}


QList<MonthlyFee> CalculateSchuleFee(QList<FeeSchule> SchuleSchemes,QList<Lesson> mathimata) {
    //schule will be always sorted by date and course



}
