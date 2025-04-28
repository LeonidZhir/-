#include <iostream>
#include "Container.h"
#include "functions.h"

int main() 
{
    Container container;
    setlocale(LC_ALL, "Russian");
    // Пример заполнения контейнера
    container.addElement(Money(10.0));
    container.addElement(Money(20.0));
    container.addElement(Money(30.0));
    // Вывод элементов в контейнере
    for (const auto& elem : container.getElements())
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    // Выполнение заданий
    task3(container, Money(20.0), Money(25.0)); // Задание 3
    task4(container, Money(20.0)); // Задание 4
    task5(container); // Задание 5

    // Вывод элементов в контейнере
    for (const auto& elem : container.getElements()) 
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}