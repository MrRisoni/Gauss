#include "orm.h"

//ALL TABLE MODELS ARE MODELLED HERE


namespace MVC {

  //MODEL FOR GENERAL/ShowGroups


  struct General_ShowGroup {
      QString GroupID;
      QString CourseName;
      QString Starts;
      QString Ends;
      QString Teacher;
      QString NumStudents;
      QString HoursPerWeek;
      QString Ausgeben; //how much money have we given the professor
      QString Einnehmen; // how much money have we earned from the fees
      QString Schulden; // how much money do we owe the professor
      QString Deficit; // how much money do the students owe to us
  };

  struct General_ShowGroupsMVC {
       QList<General_ShowGroup> Model;
       QStringList headers;
  };


  General_ShowGroupsMVC getModel() {
      QSqlQuery q;
      General_ShowGroupsMVC view;
      view.headers.append("GroupID");
      view.headers.append("CourseName");
      view.headers.append("Starts");
      view.headers.append("Ends");
      view.headers.append("Teacher");
      view.headers.append("# Students");
      view.headers.append("# Hours per week");
      view.headers.append("Ausgeben");
      view.headers.append("Einnehmen");
      view.headers.append("Schulden");
      view.headers.append("Deficit");

      General_ShowGroup G = General_ShowGroup();



      q.finish();
      return view;
  }

}
