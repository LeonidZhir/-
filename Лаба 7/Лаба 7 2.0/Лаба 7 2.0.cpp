#include <iostream>

using namespace std;

// Перегруженная функция min для 5 параметров
int min(int a, int b, int c, int d, int e) 
{
    return std::min({ a, b, c, d, e });
}

// Перегруженная функция min для 10 параметров
int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) 
{
    return std::min({ a, b, c, d, e, f, g, h, i, j });
}

// Перегруженная функция min для 12 параметров
int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) 
{
    return std::min({ a, b, c, d, e, f, g, h, i, j, k, l });
}

int main() 
{
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    system("cls");
    // Пример вызова функции min с 5 параметрами
    int min5 = min(10, 20, 5, 30, 15);
    cout << "Минимум из 5 чисел: " << min5 << endl;

    // Пример вызова функции min с 10 параметрами
    int min10 = min(10, 20, 5, 30, 15, 25, 35, 45, 5, 0);
    cout << "Минимум из 10 чисел: " << min10 << endl;

    // Пример вызова функции min с 12 параметрами
    int min12 = min(10, 20, 5, 30, 15, 25, 35, 45, 5, 0, -10, 100);
    cout << "Минимум из 12 чисел: " << min12 << endl;

    return 0;
}
