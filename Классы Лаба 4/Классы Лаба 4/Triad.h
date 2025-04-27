#pragma once
#include <iostream>
using namespace std;
class Triad 
{
private:
    int first;
    int second;
    int third;

public:
    // Конструкторы
    Triad(); // без параметров
    Triad(int f, int s, int t); // с параметрами
    Triad(const Triad& t); // копирования

    // Деструктор
    ~Triad();

    // Селекторы
    int getFirst() const;
    int getSecond() const;
    int getThird() const;

    // Модификаторы
    void setFirst(int f);
    void setSecond(int s);
    void setThird(int t);

    // Операция присваивания
    Triad& operator=(const Triad& t);

    // Перегрузка операторов
    friend ostream& operator<<(ostream& out, const Triad& t);
    friend istream& operator>>(istream& in, Triad& t);
};