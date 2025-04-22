#include "money.h"

// Конструктор без параметров
Money::Money() : rubles(0), kopecks(0) {}

// Конструктор с параметрами
Money::Money(long r, int k) : rubles(r), kopecks(k) 
{
    if (kopecks >= 100) 
    {
        rubles += kopecks / 100;
        kopecks %= 100;
    }
}

// Конструктор копирования
Money::Money(const Money& other) : rubles(other.rubles), kopecks(other.kopecks) {}

// Деструктор
Money::~Money() {} // Поскольку класс не использует динамическую память, деструктор не выполняет никаких действий.

// Селекторы возвращают значения rubles и kopecks.
long Money::getRubles() const 
{
    return rubles;
}

int Money::getKopecks() const 
{
    return kopecks;
}

// Модификаторы устанавливают значения, корректируя их, если копейки превышают 100.
void Money::setRubles(long r) 
{
    rubles = r;
}

void Money::setKopecks(int k)
{
    if (k >= 100) 
    {
        rubles += k / 100;
        kopecks = k % 100;
    }
    else 
    {
        kopecks = k;
    }
}

// Перегрузка операции присваивания
Money& Money::operator=(const Money& other) 
{
    if (this != &other) 
    {
        rubles = other.rubles;
        kopecks = other.kopecks;
    }
    return *this;
}

// Перегрузка операций ввода и вывода
ostream& operator<<(ostream& os, const Money& money) 
{
    os << money.getRubles() << ',' << (money.getKopecks() < 10 ? "0" : "") << money.getKopecks();
    return os;
}

istream& operator>>(istream& is, Money& money) 
{
    long r;
    int k;
    char comma;
    is >> r >> comma >> k;
    money = Money(r, k);
    return is;
}

// Перегрузка операций сравнения
bool Money::operator>(const Money& other) const 
{
    return rubles > other.rubles || (rubles == other.rubles && kopecks > other.kopecks);
}

bool Money::operator<(const Money& other) const 
{
    return rubles < other.rubles || (rubles == other.rubles && kopecks < other.kopecks);
}

bool Money::operator==(const Money& other) const 
{
    return rubles == other.rubles && kopecks == other.kopecks;
}

// Перегрузка операции сложения
Money Money::operator+(double amount) const 
{
    long r = static_cast<long>(amount);
    int k = static_cast<int>((amount - r) * 100);
    return Money(rubles + r, kopecks + k);
}