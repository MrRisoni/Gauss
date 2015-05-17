#ifndef FACES_H
#define FACES_H

#include "teacher.h"

class Faces
{
public:
    Faces();
    ~Faces();
    int getFaceID() const;
    void setFaceID(int value);

    Teacher getT() const;
    void setT(const Teacher &value);

private:
    int FaceID;
    Teacher T;
    QByteArray pic;
};

#endif // FACES_H
