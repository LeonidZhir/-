#include <iostream>
#include "PriorityQueue.h"
#include "Utils.h"

int main() 
{
    PriorityQueue pq;
    setlocale(LC_ALL, "Russian");
    // Добавление элементов
    pq.push(10);
    pq.push(20);
    pq.push(30);
    std::cout << "Верхний элемент: " << pq.top() << std::endl;
    // Задание 3: Найти элемент и добавить его
    findAndAddElement(pq, 20, 1);

    // Задание 4: Найти элемент и удалить его
    findAndRemoveElement(pq, 20);

    // Задание 5: Процесс для разницы
    calculateDifference(pq);

    // Печать элементов:
    while (!pq.isEmpty()) 
    {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;

    return 0;
}