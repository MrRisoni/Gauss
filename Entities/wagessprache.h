#ifndef WAGESSPRACHE_H
#define WAGESSPRACHE_H


class WagesSprache
{
public:
    WagesSprache();
    ~WagesSprache();

    int getTeachers() const;
    void setTeachers(int value);

private:
    int Teachers;

};

#endif // WAGESSPRACHE_H
