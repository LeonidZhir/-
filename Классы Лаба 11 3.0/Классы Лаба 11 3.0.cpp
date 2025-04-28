#include <iostream>
#include "Vector.h"

int main() 
{
    Vector<int> myVector;
    
    // Заполнение контейнера элементами
    myVector.addElement(10);
    myVector.addElement(20);
    myVector.addElement(30);
    myVector.print();
    // Задание 3: Найти элемент с заданным ключом и добавить его на заданную позицию
    myVector.addAtPosition(1, 20); // Добавление 20 на позицию 1
    myVector.print();

    // Задание 4: Найти элемент с заданным ключом и удалить его из контейнера
    myVector.removeElement(20); // Удаление 20
    myVector.print();

    // Задание 5: Найти разницу между максимальным и минимальным элементами
    myVector.calculateDifference();
    myVector.print();

    return 0;
}