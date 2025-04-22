#include "Point.h"

int main() 
{
    setlocale(LC_ALL, "Russian");
    try 
    {
        // Создание объекта Point
        Point p1;
        p1.Init(4.0, 5.0);
        p1.Show();
        cout << "Расстояние от начала: " << p1.distance() << "\n";

        // Ввод координат с клавиатуры
        Point p2;
        p2.Read();
        p2.Show();
        cout << "Расстояние от начала: " << p2.distance() << "\n";

        // Создание массива объектов Point
        const int size = 3;
        Point points[size];
        for (int i = 0; i < size; ++i) 
        {
            double x, y;
            cout << "Введите координаты точки " << (i + 1) << ": ";
            cin >> x >> y;
            points[i].Init(x, y);
        }

        // Вывод всех точек и их расстояний
        for (int i = 0; i < size; ++i)
        {
            points[i].Show();
            cout << "Расстояние от начала: " << points[i].distance() << "\n";
        }
    }
    catch (const invalid_argument& e) 
    {
        cerr << "Ошибка: " << e.what() << "\n";
        return 1;
    }

    return 0;
}