# pragma once
#include <iostream>

class Money 
{
private:
    int rubles;   // рубли
    int kopecks;  // копейки

public:
    Money(int r = 0, int k = 0) : rubles(r), kopecks(k) 
    {
        if (kopecks >= 100) 
        {
            rubles += kopecks / 100;
            kopecks %= 100;
        }
    }

    // Перегрузка операторов
    friend std::ostream& operator<<(std::ostream& os, const Money& m) 
    {
        os << m.rubles << "." << (m.kopecks < 10 ? "0" : "") << m.kopecks;
        return os;
    }

    bool operator==(const Money& other) const 
    {
        return rubles == other.rubles && kopecks == other.kopecks;
    }

    bool operator<(const Money& other) const 
    {
        return rubles * 100 + kopecks < other.rubles * 100 + other.kopecks;
    }

    int toCents() const 
    {
        return rubles * 100 + kopecks;
    }

    Money operator-(const Money& other) const 
    {
        int totalKopecks = (rubles * 100 + kopecks) - (other.rubles * 100 + other.kopecks);
        return Money(totalKopecks / 100, totalKopecks % 100);
    }
};