#pragma once
#include <list>
#include <algorithm>
#include <iostream>
#include "money.h"

void addElementAtPosition(std::list<Money>& moneyList, const Money& element, int position) 
{
    auto it = moneyList.begin();
    std::advance(it, position);
    moneyList.insert(it, element);
}

void removeElement(std::list<Money>& moneyList, const Money& element) 
{
    moneyList.remove(element);
}

void findDifference(const std::list<Money>& moneyList) 
{
    auto minElement = std::min_element(moneyList.begin(), moneyList.end());
    auto maxElement = std::max_element(moneyList.begin(), moneyList.end());

    int difference = (maxElement->rubles - minElement->rubles) * 100 + (maxElement->kopecks - minElement->kopecks);
    std::cout << "Разница между максимальным и минимальным элементами: " << difference << " коп." << std::endl;

    for (const auto& money : moneyList) 
    {
        Money newMoney(money.rubles, money.kopecks - difference);
        std::cout << "Элемент после вычитания: " << newMoney << std::endl;
    }
}