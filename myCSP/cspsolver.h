#ifndef CSPSOLVER_H
#define CSPSOLVER_H
#include <QList>
#include <variable.h>

class CspSolver
{
public:
    CspSolver();

    //the order with which the variables are going to be assigned
    //is the same as the order with which the variables were inserted into the myVars array
    QList<Variable*> myVars;

    //All Variables are bound with constraints
    bool AreConstraintsViolated(Point *p, int stopVarID);
    void ForwardChecking(int VarID);
     QList<Point*> GeneratePossibleVals();
    void CreateVariables();
    float Overlap(float StartA,float StartB);
    void Solve();
    float max(float a,float b);
    float min(float a,float b);
    void Init();


};

#endif // CSPSOLVER_H
