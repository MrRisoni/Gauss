#ifndef FEESTRUCTS_H
#define FEESTRUCTS_H

#include <QDate>





//for each month only the last discount is taken into account
// SQL will handle this
/* example
  January

  10/1 : 5%

  28/1 : 2%

  February :

  1 % No change

  March : 5%


  Let the fee for these months be :

  January : 126
  February : 900
  March : 567

  The final discount will be
  January : -126*0.02
  February : -900*0.01
  March : -567*0.05

*/


struct Discount {
  float disc; //100 means 100% discount - 0 means no discount
  QDate dat; //the discount at that specific month and year
};


struct MonthlyFee {
    //this struct models the fees that need to be payed each month
    float Sum;
    QDate dat; // 1 is January the fees at that specific month and year
};


struct FeeSchule {
    //how much was the fee for  CourseID at that date
    int CourseID;
    QDate dat;
    float wage;

};



#endif // FEESTRUCTS_H

