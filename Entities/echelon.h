#ifndef ECHELON_H
#define ECHELON_H


class Echelon
{
public:
    Echelon();
    ~Echelon();

    int getExpYears() const;
    void setExpYears(int value);

    int getTeachers() const;
    void setTeachers(int value);

private:
    int ExpYears;
    int Teachers;
};

#endif // ECHELON_H
