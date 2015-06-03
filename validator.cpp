#include "validator.h"
#include "exception"


Validator::Validator()
{

}



bool Validator::ValidateFields(QList<QLineEdit *> widgets) {

    bool isvaild=true;
    foreach(QLineEdit *widget,widgets) {
        if (widget->text().length()==0) {
            //set a style shhet to empty fields

            widget->setStyleSheet(" border: 3px solid red;");

            isvaild= false;
        }
    }



    return isvaild;


}




