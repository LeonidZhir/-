#include "operations.h"
#include <algorithm>
#include <iostream>

void addElementAtPosition(std::vector<double>& container, double value, size_t position) 
{
    if (position <= container.size()) 
    {
        container.insert(container.begin() + position, value);
    }
    else 
    {
        std::cout << "Ошибка: позиция выходит за границы контейнера." << std::endl;
    }
}

void removeElementByValue(std::vector<double>& container, double value) 
{
    auto it = std::remove(container.begin(), container.end(), value);
    if (it != container.end()) 
    {
        container.erase(it, container.end());
    }
    else 
    {
        std::cout << "Элемент не найден для удаления." << std::endl;
    }
}

void calculateDifference(std::vector<double>& container) 
{
    if (container.empty()) 
    {
        std::cout << "Контейнер пуст." << std::endl;
        return;
    }

    double maxElement = *std::max_element(container.begin(), container.end());
    double minElement = *std::min_element(container.begin(), container.end());
    double difference = maxElement - minElement;

    for (auto& elem : container) 
    {
        elem -= difference; // вычитание разности из каждого элемента
    }

    std::cout << "Разница (max - min): " << difference << std::endl;
}