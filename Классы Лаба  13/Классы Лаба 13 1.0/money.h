#pragma once
#include <iostream>
#include <iomanip>

class Money 
{
public:
    int rubles;
    int kopecks;

    Money(int r = 0, int k = 0) : rubles(r), kopecks(k) 
    {
        if (kopecks >= 100) 
        {
            rubles += kopecks / 100;
            kopecks = kopecks % 100;
        }
    }

    bool operator==(const Money& other) const 
    {
        return rubles == other.rubles && kopecks == other.kopecks;
    }

    bool operator<(const Money& other) const 
    {
        return rubles < other.rubles || (rubles == other.rubles && kopecks < other.kopecks);
    }

    friend std::ostream& operator<<(std::ostream& os, const Money& money) 
    {
        os << money.rubles << " руб. " << std::setw(2) << std::setfill('0') << money.kopecks << " коп.";
        return os;
    }
};