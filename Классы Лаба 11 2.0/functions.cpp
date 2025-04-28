#include "functions.h"
#include <iostream>
#include <algorithm>

void task3(Container& container, const Money& moneyToFind, const Money& moneyToAdd)
{
    int position = container.findElement(moneyToFind);
    if (position != -1) 
    {
        container.addElement(moneyToAdd);
        std::cout << "Добавлен элемент: " << moneyToAdd << std::endl;
    }
    else 
    {
        std::cout << "Элемент не найден." << std::endl;
    }
}

void task4(Container& container, const Money& moneyToFind)
{
    container.removeElement(moneyToFind);
    std::cout << "Элемент " << moneyToFind << " удален." << std::endl;
}

void task5(Container& container) 
{
    const std::vector<Money>& elements = container.getElements();
    if (elements.empty()) return;

    Money maxElement = elements[0];
    Money minElement = elements[0];

    for (const auto& elem : elements)
    {
        if (elem.getAmount() > maxElement.getAmount()) maxElement = elem;
        if (elem.getAmount() < minElement.getAmount()) minElement = elem;
    }

    double difference = maxElement.getAmount() - minElement.getAmount();
    for (auto& elem : const_cast<std::vector<Money>&>(elements)) 
    {
        elem = Money(elem.getAmount() - difference);
    }
}
