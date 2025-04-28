#include "Money.h"

void Money::display() const
{
    std::cout << rubles << " рублей " << kopecks << " копеек" << std::endl;
}

Money Money::operator+(const Money& m) const 
{
    return Money(rubles + m.rubles, kopecks + m.kopecks);
}

bool Money::operator>(const Money& m) const 
{
    return rubles > m.rubles || (rubles == m.rubles && kopecks > m.kopecks);
}

bool Money::operator<(const Money& m) const 
{
    return rubles < m.rubles || (rubles == m.rubles && kopecks < m.kopecks);
}

bool Money::operator==(const Money& m) const 
{
    return rubles == m.rubles && kopecks == m.kopecks;
}

long Money::getRubles() const 
{
    return rubles;
}

int Money::getKopecks() const
{
    return kopecks;
}

void Money::setRubles(long r) 
{
    rubles = r;
}

void Money::setKopecks(int k) 
{
    kopecks = k;
}