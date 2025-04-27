#pragma once
#include "Triad.h"

class Date : public Triad 
{
private:
    int year;

public:
    // Конструкторы
    Date(); // без параметров
    Date(int d, int m, int y); // с параметрами
    Date(const Date& d); // копирования

    // Деструктор
    ~Date();

    // Селекторы
    int getYear() const;

    // Модификаторы
    void setYear(int y);

    // Операция сравнения
    bool operator<(const Date& d) const;
    bool operator>(const Date& d) const;
    bool operator==(const Date& d) const;

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& out, const Date& d);
};