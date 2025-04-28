#include <iostream>
#include <vector>
#include "operations.h"
#include "container.h"

int main() 
{
    setlocale(LC_ALL, "Russian");
    std::vector<double> container;
    // Заполнение контейнера
    fillContainer(container, 10); // Заполнение 10 элементами
    std::cout << "Элементы контейнера: ";
    for (const auto& elem : container)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    // Задание 3
    addElementAtPosition(container, 5.0, 2); // Добавление 5.0 на позицию 2

    // Задание 4
    removeElementByValue(container, 5.0); // Удаление элемента 5.0

    // Задание 5
    calculateDifference(container); // Вычисление разности

    // Вывод конечного состояния контейнера
    std::cout << "Элементы контейнера: ";
    for (const auto& elem : container)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}