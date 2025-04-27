#include "Triad.h"

// Конструктор без параметров
Triad::Triad() : first(0), second(0), third(0) {}

// Конструктор с параметрами
Triad::Triad(int f, int s, int t) : first(f), second(s), third(t) {}

// Конструктор копирования
Triad::Triad(const Triad& t) : first(t.first), second(t.second), third(t.third) {}

// Деструктор
Triad::~Triad() {}

// Селекторы
int Triad::getFirst() const { return first; }
int Triad::getSecond() const { return second; }
int Triad::getThird() const { return third; }

// Модификаторы
void Triad::setFirst(int f) { first = f; }
void Triad::setSecond(int s) { second = s; }
void Triad::setThird(int t) { third = t; }

// Операция присваивания
Triad& Triad::operator=(const Triad& t) 
{
    if (this == &t) return *this;
    first = t.first;
    second = t.second;
    third = t.third;
    return *this;
}

// Перегрузка оператора вывода
ostream& operator<<(ostream& out, const Triad& t) 
{
    out << "(" << t.first << ", " << t.second << ", " << t.third << ")";
    return out;
}

// Перегрузка оператора ввода
istream& operator>>(istream& in, Triad& t) 
{
    in >> t.first >> t.second >> t.third;
    return in;
}