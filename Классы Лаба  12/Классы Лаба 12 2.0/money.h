#pragma once
#include <iostream>

class Money 
{
public:
    Money(int rub = 0, int kop = 0);
    Money(const Money& other);

    // Перегрузка операторов
    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator>(const Money& other) const;

    // Получение значений
    int getRub() const;
    int getKop() const;

    // Вывод
    friend std::ostream& operator<<(std::ostream& out, const Money& money);
    friend std::istream& operator>>(std::istream& in, Money& money);

private:
    long rub; // Рубли
    int kop; // Копейки
};