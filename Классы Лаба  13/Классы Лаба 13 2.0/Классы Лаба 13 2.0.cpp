#include <iostream>
#include "Money.h"
#include "ContainerAdapter.h"

void printMoney(const Money& m) 
{
    std::cout << m << " ";
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    ContainerAdapter adapter;
    adapter.add(Money(10, 50));
    adapter.add(Money(5, 75));
    adapter.add(Money(7, 25));
    adapter.add(Money(10, 50));

    std::cout << "Элементы контейнера: ";
    adapter.print();

    // Задача 3: Найти элемент и добавить его на заданную позицию
    Money searchValue(10, 50);
    adapter.add(searchValue); 
    adapter.print();

    // Задача 4: Найти элемент и удалить его
    adapter.remove(searchValue);
    std::cout << "После удаления " << searchValue << ": ";
    adapter.print();

    // Задача 5: Найти разницу между максимальным и минимальным элементами
    Money maxMoney = adapter.findMax();
    Money minMoney = adapter.findMin();
    Money difference = maxMoney - minMoney;

    std::cout << "Разница между максимальным и минимальным значением: " << difference << std::endl;

    std::cout << "Все элементы после применения функции: ";
    adapter.forEach(printMoney);

    return 0;
}