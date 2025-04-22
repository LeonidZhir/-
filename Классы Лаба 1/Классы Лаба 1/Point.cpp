#include "Point.h"

void Pair::Init(double x, double y)//  Инициализирует координаты, проверяя, что они неотрицательные. Если хотя бы одна координата отрицательна, выбрасывается исключение invalid_argument.
{
    if (x < 0 || y < 0) 
    {
        throw invalid_argument("Координаты должны быть неотрицательными.");
    }
    first = x;
    second = y;
}

void Pair::Read() // Запрашивает у пользователя ввод координат и инициализирует их.
{
    double x, y;
    cout << "Введите координаты (x y): ";
    cin >> x >> y;
    Init(x, y);
}

void Pair::Show() const // Выводит текущие координаты на экран.
{
    cout << "Координаты: (" << first << ", " << second << ")\n";
}

void Point::Init(double x, double y) // Инициализирует координаты точки, вызывая метод Init структуры Pair.
{
    coordinates.Init(x, y);
}

double Point::distance() const // Вычисляет и возвращает расстояние от точки до начала координат (0, 0) по формуле нахождения расстояния
{
    return sqrt(coordinates.first * coordinates.first + coordinates.second * coordinates.second);
}

void Point::Read() // Вызывает метод Read структуры Pair для ввода координат.
{
    coordinates.Read();
}

void Point::Show() const // Вызывает метод Show структуры Pair для отображения координат.
{
    coordinates.Show();
}

Point makePoint(double x, double y) // Позволяет создавать объект Point, инициализируя его координаты.
{
    Point p;
    p.Init(x, y);
    return p;
}