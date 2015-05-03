#ifndef SCHWIERIGKEIT_H
#define SCHWIERIGKEIT_H


class Schwierigkeit
{
public:
    Schwierigkeit();
    ~Schwierigkeit();

    int getBlue() const;
    void setBlue(int value);

    int getGreen() const;
    void setGreen(int value);

    int getRed() const;
    void setRed(int value);



private:
    int Red;
    int Green;
    int Blue;
};

#endif // SCHWIERIGKEIT_H
