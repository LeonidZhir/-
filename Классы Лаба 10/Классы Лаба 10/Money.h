#pragma once
#include <iostream>

class Money 
{
private:
    long rubles; // рубли
    int kopecks; // копейки

public:
    Money(long r = 0, int k = 0) : rubles(r), kopecks(k) 
    {
        if (kopecks >= 100) 
        {
            rubles += kopecks / 100;
            kopecks %= 100;
        }
    }

    void display() const;

    Money operator+(const Money& m) const;
    bool operator>(const Money& m) const;
    bool operator<(const Money& m) const;
    bool operator==(const Money& m) const;

    long getRubles() const;
    int getKopecks() const;

    void setRubles(long r);
    void setKopecks(int k);
};