#include <iostream>
#include <map>
#include <iterator>
#include "container_utils.h"

void fillMap(std::map<int, double>& myMap) 
{
    myMap[1] = 1.1;
    myMap[2] = 2.2;
    myMap[3] = 3.3;
    myMap[4] = 4.4;
    myMap[5] = 5.5;
}

void task3(std::map<int, double>& myMap, int key, int position) 
{
    auto it = myMap.find(key);

    if (it != myMap.end()) 
    {
        // ���������� �������� �� �������� �������
        myMap.insert({ position, it->second });
    }
    else 
    {
        std::cout << "������� � ��������� ������ �� ������.\n";
    }
}

void task4(std::map<int, double>& myMap, int key)
{
    auto it = myMap.find(key);

    if (it != myMap.end()) 
    {
        // �������� ��������
        myMap.erase(it);
    }
    else 
    {
        std::cout << "������� � ��������� ������ �� ������.\n";
    }
}

void task5(const std::map<int, double>& myMap) 
{
    if (myMap.empty()) 
    {
        std::cout << "��������� ����.\n";
        return;
    }

    double maxVal = myMap.begin()->second;
    double minVal = myMap.begin()->second;

    for (const auto& pair : myMap) 
    {
        if (pair.second > maxVal) 
        {
            maxVal = pair.second;
        }
        if (pair.second < minVal)
        {
            minVal = pair.second;
        }
    }

    double difference = maxVal - minVal;

    for (const auto& pair : myMap) 
    {
        std::cout << "�������: " << pair.first << " -> " << (pair.second - difference) << "\n";
    }
}