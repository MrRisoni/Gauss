#include "cspsolver.h"
#include "point.h"
#include "variable.h"
#include <QDebug>
#include "node.h"


#define DUR 2.0

CspSolver::CspSolver()
{

}



void CspSolver::CreateVariables() {

 //create four variables

 QList<Point*> Domain= GeneratePossibleVals();



 //NO NEED FOR ORDER OF ASSIGNMENT USE myVars list
 //create variables
 Variable *var0= new Variable();
 var0->ClassID=0;
 var0->VarID=0;

 var0->InitDomain=Domain;


 Variable *var1= new Variable();
 var1->ClassID=1;
 var1->InitDomain=Domain;
 var1->VarID=0;


 Variable *var2= new Variable();
 var2->ClassID=2;
 var2->InitDomain=Domain;
 var2->VarID=0;


 Variable *var3= new Variable();
 var3->ClassID=3;
 var3->InitDomain=Domain;
 var3->VarID=0;

  myVars.append(var0);
  myVars.append(var1);
  myVars.append(var2);
  myVars.append(var3);


  Variable x;
  Solve();

}


void CspSolver::Init() {

    //create the rootNode
    Node *riza=new Node();

    riza->NodeID=0;
    //this has no variables

    //add a node for the first variable that needs to be assigned

    Node *firstVar=new Node();

    firstVar->prevNode=riza;

    firstVar->NodeID=1;
    firstVar->V=myVars.at(0);

    riza->children.push_back(firstVar);

    //assign to this variable the first value of the domain

    firstVar->V->CurrentDomain= myVars.at(0)->InitDomain.at(0);


    Solve();
}


void CspSolver::Solve() {
    bool Solved=false;

    while (!Solved)  {
        bool deadEnd=false;


        //call forward checking to erase next values
        //actually leave forward for later to avoid bugs
        //ForwardChecking(0);

        //get the next variable and assign value
        bool domainExhausted=false; //if no value of the domain can be assigned raise this flag
        bool valueFound=false; // if a value is found raise this flag
        int i=0;
        while ((domainExhausted==false) || (valueFound==false)) {



        }

        //if domainExhausted==true
        //go back to the previous node assign a different value...
        //and recurse back here!!!



    }


}


bool CspSolver::AreConstraintsViolated(Point* p,int stopVarID) {
    // for the proposed assignment
    //check if violation with the variables that HAVE BEEN ASSIGNED
    //loop myvars until you read stopVarID

    bool IsSmthViolated=false;

    int CheckVarID=0;

    while ((CheckVarID<stopVarID) && (IsSmthViolated==false)) {

        qDebug() << "constraints " << stopVarID << " and " << CheckVarID  << endl;

        //check hour overlap

        if (Overlap(p->StartHour,myVars.at(CheckVarID)->CurrentDomain->StartHour)>0) {

            //check if same day
            qDebug() << stopVarID  << " SAME HOUR  " << CheckVarID << endl;



            if (p->Day==myVars.at(CheckVarID)->CurrentDomain->Day) {

                qDebug() << stopVarID  << " SAME DAT  " << CheckVarID << endl;
                //check if same buidling

                if (p->BuildingID==myVars.at(CheckVarID)->CurrentDomain->BuildingID ) {

                    qDebug() << stopVarID  << " IN SAME BUIDLING " << CheckVarID << endl;
                    IsSmthViolated=true;
                    //GO BACK
                    break;
                }
            }
        }

        CheckVarID++;





    }

    if (IsSmthViolated==true) {
        qDebug() << "VIOLATION" << endl;

    }

    return IsSmthViolated;
}



float CspSolver::Overlap(float StartA, float StartB) {
    float EndA=StartA+DUR;
    float EndB=StartB +  DUR;
    return max(0, min(EndA, EndB) - max(StartA, StartB));

}

float CspSolver::max(float a, float b) {
    if (a>b) {
        return a;
    }
    else {
        return b;
    }
}


float CspSolver::min(float a,float b) {
    if (a>b) {
        return b;
    }
    else {
        return a;
    }
}

void CspSolver::ForwardChecking(int VarID) {
    //remove from the domain the triplet that will cause violation

    //begin from VarID


    //nextVarID now points to the next variable that is unassigned
    for (int i=VarID;i<myVars.size();i++) {
        qDebug() << " erasing from variable " << myVars.at(i)->VarID << endl;


        //erase overlapping values
        for (int k=0;k<myVars.at(i)->InitDomain.size();k++) {

            //check those values that have AllowedValues==1
            if (myVars.at(i)->AllowedValues.at(k)==1) {
            }
        }
    }



}


 QList<Point *> CspSolver::GeneratePossibleVals() {
    QList<Point*> Domain;
    //generate all posible variable values
    int TotalCombos=0;
    for (int build=1;build<2;build++) {
        for (int day=1;day<2;day++) {
            //all classes must end by 22
            for (float hour=9;hour<=20;hour+=0.5) {
                   TotalCombos+=1;
                   qDebug() << "building " << build << " day " << day << " hour " << hour << endl;
                   Point *p=new Point();
                   p->BuildingID=build;
                   p->Day=day;
                   p->StartHour=hour;
                   Domain.append(p);
            }
        }
    }


    qDebug() << "Total combinations " << TotalCombos;
    return Domain;
}
