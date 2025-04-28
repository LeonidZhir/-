#include <iostream>
#include "Vector.h"

int main() 
{
    setlocale(LC_ALL, "Russian");
    Vector<int> v;

    v.add(5);
    v.add(15);
    v.add(10);
    std::cout << "Элементы после добавления: " << std::endl;
    for (const auto& elem : v.getElements()) 
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    v.findAndInsert(10, 7, 1);
    std::cout << "После установки 7 перед 10: " << std::endl;
    for (const auto& elem : v.getElements())
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    v.findAndRemove(15);
    std::cout << "После удаления 15: " << std::endl;
    for (const auto& elem : v.getElements()) 
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    v.subtractExtremes();
    std::cout << "После вычитания экстремумов: " << std::endl;
    for (const auto& elem : v.getElements()) 
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}