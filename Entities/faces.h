#ifndef FACES_H
#define FACES_H


#include <QByteArray>

class Faces
{
public:
    Faces();
    ~Faces();
    int getFaceID() const;
    void setFaceID(int value);


private:
    int FaceID;
    int TeacherID;
    QByteArray pic;
};

#endif // FACES_H
