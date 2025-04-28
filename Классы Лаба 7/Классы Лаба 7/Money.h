#pragma once
#include <iostream>
#include <iomanip>

class Money 
{
private:
    long rubles;
    int kopecks;

public:
    Money(long r = 0, int k = 0) : rubles(r), kopecks(k) {}

    // Оператор ввода
    friend std::istream& operator>>(std::istream& is, Money& money) 
    {
        is >> money.rubles >> money.kopecks;
        return is;
    }

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Money& money) 
    {
        os << money.rubles << "," << std::setfill('0') << std::setw(2) << money.kopecks;
        return os;
    }

    bool operator==(const Money& other) const 
    {
        return (rubles == other.rubles) && (kopecks == other.kopecks);
    }
};
