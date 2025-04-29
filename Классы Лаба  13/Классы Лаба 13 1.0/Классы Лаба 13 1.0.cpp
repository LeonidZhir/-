#include <iostream>
#include <list>
#include <algorithm>
#include "money.h"
#include "utils.h"

int main() 
{
    setlocale(LC_ALL, "Russian");
    std::list<Money> moneyList = 
    {
        Money(10, 50), Money(5, 25), Money(7, 75), Money(10, 0), Money(5, 100)
    };

    // Задание 3: Найти элемент и добавить его на заданную позицию
    Money key(10, 50);
    int position = 2; // Вставляем на позицию 2
    addElementAtPosition(moneyList, key, position);

    // Задание 4: Удалить элемент
    removeElement(moneyList, key);

    // Задание 5: Найти разницу между макс. и мин. элементами
    findDifference(moneyList);

    // Сортировка по возрастанию
    moneyList.sort();

    // Вывод списка
    std::cout << "Список денег: " << std::endl;
    for (const auto& money : moneyList) 
    {
        std::cout << money << std::endl;
    }

    return 0;
}