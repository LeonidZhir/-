#include <iostream>
#include "container_utils.h"

int main() 
{
    std::map<int, double> myMap;
    setlocale(LC_ALL, "Russian");
    // Заполнение карты элементами
    fillMap(myMap);

    // Задание 3
    int keyToFind, positionToAdd;
    std::cout << "Введите ключ для задания 3: ";
    std::cin >> keyToFind;
    std::cout << "Введите позицию для добавления: ";
    std::cin >> positionToAdd;
    task3(myMap, keyToFind, positionToAdd);

    // Задание 4
    std::cout << "Введите ключ для задания 4: ";
    std::cin >> keyToFind;
    task4(myMap, keyToFind);

    // Задание 5
    task5(myMap);

    return 0;
}