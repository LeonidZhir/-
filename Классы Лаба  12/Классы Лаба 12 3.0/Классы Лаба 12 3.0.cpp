#include "vector.h"

int main() 
{
    Vector<int, double> vec;
    setlocale(LC_ALL, "Russian");
    // Заполняем контейнер
    vec.addElement(1, 2.5);
    vec.addElement(2, 3.0);
    vec.addElement(3, 1.5);
    vec.addElement(4, 4.25);

    std::cout << "Начальный контейнер:" << std::endl;
    vec.display();

    // Задание 3: Найти элемент с заданным ключом и добавить его на заданную позицию
    vec.findAndAdd(2, 5.0, 1);
    std::cout << "После нахождения и добавления:" << std::endl;
    vec.display();

    // Задание 4: Найти элемент с заданным ключом и удалить его
    vec.findAndRemove(3);
    std::cout << "После обнаружения и удаления:" << std::endl;
    vec.display();

    // Задание 5: Найти разницу и вычесть ее из каждого элемента
    vec.calculateDifference();
    std::cout << "После вычисления разницы:" << std::endl;
    vec.display();

    return 0;
}