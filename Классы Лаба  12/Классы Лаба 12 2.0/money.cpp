#include "money.h"

// Конструктор
Money::Money(int rub, int kop) : rub(rub), kop(kop)
{
    if (kop >= 100)
    {
        rub += kop / 100;
        this->kop = kop % 100;
    }
    else 
    {
        this->kop = kop;
    }
}

// Конструктор копирования
Money::Money(const Money& other) : rub(other.rub), kop(other.kop) {}

// Перегрузка операторов
Money Money::operator+(const Money& other) const 
{
    return Money(rub + other.rub, kop + other.kop);
}

Money Money::operator-(const Money& other) const 
{
    return Money(rub - other.rub, kop - other.kop);
}

bool Money::operator<(const Money& other) const
{
    return rub < other.rub || (rub == other.rub && kop < other.kop);
}

bool Money::operator>(const Money& other) const 
{
    return rub > other.rub || (rub == other.rub && kop > other.kop);
}

int Money::getRub() const 
{
    return rub;
}

int Money::getKop() const 
{
    return kop;
}

std::ostream& operator<<(std::ostream& out, const Money& money) 
{
    out << money.rub << " руб. " << money.kop << " коп.";
    return out;
}

std::istream& operator>>(std::istream& in, Money& money) 
{
    in >> money.rub >> money.kop;
    return in;
}