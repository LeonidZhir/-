#include <iostream>
#include "Set.h"

int main() 
{
    Set mySet;
    setlocale(LC_ALL, "Russian");
    try 
    {
        mySet.add(5);
        mySet.add(10);
        mySet.add(15);

        std::cout << "Элемент с индексом 1: " << mySet[1] << std::endl;

        if (mySet > 10)
        {
            std::cout << "10 входит в множество." << std::endl;
        }

        mySet.remove(10);
        std::cout << "Удален элемент 10." << std::endl;

        std::cout << "Доступ к индексу 3: " << mySet[3] << std::endl;
    }
    catch (const Error& e) 
    {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}