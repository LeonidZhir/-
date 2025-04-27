#include "Date.h"

// Конструктор без параметров
Date::Date() : Triad(0, 0, 0), year(0) {}

// Конструктор с параметрами
Date::Date(int d, int m, int y) : Triad(d, m, 0), year(y) {}

// Конструктор копирования
Date::Date(const Date& d) : Triad(d), year(d.year) {}

// Деструктор
Date::~Date() {}

// Селектор
int Date::getYear() const { return year; }

// Модификатор
void Date::setYear(int y) { year = y; }

// Операция сравнения
bool Date::operator<(const Date& d) const 
{
    if (getYear() != d.getYear())
        return getYear() < d.getYear();
    else if (getFirst() != d.getFirst())
        return getFirst() < d.getFirst();
    else
        return getSecond() < d.getSecond();
}

bool Date::operator>(const Date& d) const 
{
    return d < *this;
}

bool Date::operator==(const Date& d) const 
{
    return getYear() == d.getYear() && getFirst() == d.getFirst() && getSecond() == d.getSecond();
}

// Перегрузка оператора вывода
ostream& operator<<(ostream& out, const Date& d) 
{
    out << d.getFirst() << "/" << d.getSecond() << "/" << d.getYear();
    return out;
}