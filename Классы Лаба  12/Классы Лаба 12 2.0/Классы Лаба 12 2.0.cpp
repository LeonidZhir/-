#include <iostream>
#include <map>
#include <algorithm> // для std::max_element и std::min_element
#include "money.h"

void addElement(std::map<int, Money>& container, int key, const Money& value)
{
    container[key] = value; // добавляет или обновляет элемент
}

void findAndAddElement(std::map<int, Money>& container, int key,
    const Money& value)
{
    // Если ключ существует, обновляем значение
    if (container.find(key) != container.end())
    {
        container[key] = value; // обновляем значение
    }
}

void findAndRemoveElement(std::map<int, Money>& container, int key)
{
    container.erase(key); // удаляем элемент по ключу
}

void findDifference(std::map<int, Money>& container)
{
    if (container.empty()) return; // Проверка на пустой контейнер

    // max и min элементы
    auto max_it = std::max_element(container.begin(), container.end(),
        [](const auto& a, const auto& b)
        {
            return a.second < b.second;
        });

    auto min_it = std::min_element(container.begin(), container.end(),
        [](const auto& a, const auto& b)
        {
            return a.second < b.second;
        });

    Money difference = max_it->second - min_it->second;

    // Вычитание разности из каждого элемента
    for (auto& pair : container)
    {
        pair.second = pair.second - difference;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    std::map<int, Money> container;

    // Пример заполнения контейнера
    addElement(container, 1, Money(100, 50));
    addElement(container, 2, Money(200, 75));
    // Вывод элементов контейнера
    for (const auto& pair : container)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << std::endl;
    // Выполнение заданий
    findAndAddElement(container, 1, Money(50, 25)); // Задание 3
    findAndRemoveElement(container, 1);              // Задание 4
    findDifference(container);                        // Задание 5

    // Вывод элементов контейнера
    for (const auto& pair : container)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}