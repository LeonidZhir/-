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
        std::cout << "������: ������� ������� �� ������� ����������." << std::endl;
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
        std::cout << "������� �� ������ ��� ��������." << std::endl;
    }
}

void calculateDifference(std::vector<double>& container) 
{
    if (container.empty()) 
    {
        std::cout << "��������� ����." << std::endl;
        return;
    }

    double maxElement = *std::max_element(container.begin(), container.end());
    double minElement = *std::min_element(container.begin(), container.end());
    double difference = maxElement - minElement;

    for (auto& elem : container) 
    {
        elem -= difference; // ��������� �������� �� ������� ��������
    }

    std::cout << "������� (max - min): " << difference << std::endl;
}