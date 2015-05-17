#include "faces.h"

Faces::Faces()
{

}

Faces::~Faces()
{

}
int Faces::getFaceID() const
{
    return FaceID;
}

void Faces::setFaceID(int value)
{
    FaceID = value;
}
Teacher Faces::getT() const
{
    return T;
}

void Faces::setT(const Teacher &value)
{
    T = value;
}



