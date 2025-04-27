#include <iostream>
#include "SetContainer.h"

int main()
{
    setlocale(LC_ALL, "RU");
    SetContainer set1, set2;

    // Ввод элементов в первое множество
    std::cout << "Введите целые числа для первого набора (заканчивайте нецелым числом): ";
    std::cin >> set1;

    set2 = set1;

    // Вывод множеств
    std::cout << "Первый набор: " << set1 << std::endl;
    std::cout << "Второй набор: " << set2 << std::endl;

    // Проверка на равенство множеств
    if (set1 == set2) 
    {
        std::cout << "Множества равны." << std::endl;
    }
    else 
    {
        std::cout << "Множества не равны." << std::endl;
    }

    // Проверка на принадлежность элемента
    int checkValue;
    checkValue = 15;
    if (set1 > checkValue) 
    {
        std::cout << checkValue << " находится в первом сете." << std::endl;
    }
    else 
    {
        std::cout << checkValue << " его нет в первом сете." << std::endl;
    }

    // Переход к элементу с индексом n
    size_t n;
    n = 3;

    if (n < set1.size()) 
    {
        std::cout << "Элемент в индексе " << n << ": " << set1[n] << std::endl; // Используем оператор доступа к индексу
    }
    else 
    {
        std::cout << "Индекс выходит за рамки допустимого." << std::endl;
    }

    return 0;
}
