#pragma once
#include <iostream>
#include <cmath>//Для математических операций, таких как вычисление квадратного корня.
#include <stdexcept>//Для обработки исключений(Отрицательное значение координат).
using namespace std;
struct Pair 
{
    double first;  // Координата x
    double second; // Координата y

    void Init(double x, double y);
    void Read();
    void Show() const;
};
class Point 
{
private:
    Pair coordinates;

public:
    void Init(double x, double y);
    double distance() const;
    void Read();
    void Show() const;

    // Дружественная функция для создания точки
    friend Point makePoint(double x, double y);
};