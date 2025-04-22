#include <iostream>
#include "Kvartira.h"
int main() 
{
    setlocale(LC_ALL, "Russian");
    // Конструктор без параметров
    Kvartira kv1;
    kv1.displayInfo();

    cout << "\n";

    // Конструктор с параметрами
    Kvartira kv2("Кунгур, ул. Ленина, д. 1", 75.5, 3);
    kv2.displayInfo();

    cout << "\n";

    // Конструктор копирования
    Kvartira kv3 = kv2; // Вызов конструктора копирования
    kv3.displayInfo();

    return 0;
}