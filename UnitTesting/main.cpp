#include "UnitTest++/UnitTest++.h"
#include <QDate>
#include "extensions/TestFactoryRegistry.h"
#include "extensions/HelperMacros.h"
#include "ui/text/TestRunner.h"



using namespace std;
using namespace CppUnit;


struct MoneyScheme {

       QDate dat;
       float Money;

};

   /* a history of the working hours
    01 January 2015 2 hours
    11 January 2015 1.0 hour
    21 January 2015 1.3 hours
    */

struct Lesson {

    QDate dat;
    float Duration;

 };

int main(int, const char *[])
{

   TextUi::TestRunner runner;
   TestFactory &registry= TestFactoryRegistry::getRegistry();
   runner.addTest(registry.makeTest());
   runner.run();
   return 0;
}




