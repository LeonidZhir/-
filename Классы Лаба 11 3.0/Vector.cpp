#include "Vector.h"

// Добавление элемента в контейнер
template<typename T>
void Vector<T>::addElement(const T& element) 
{
    container.push_back(element);
}

// Добавление элемента на заданную позицию
template<typename T>
void Vector<T>::addAtPosition(size_t position, const T& element) 
{
    if (position <= container.size()) 
    {
        container.insert(container.begin() + position, element);
    }
    else 
    {
        std::cout << "Ошибка: позиция выходит за границы контейнера!" << std::endl;
    }
}

// Удаление элемента из контейнера
template<typename T>
void Vector<T>::removeElement(const T& element) 
{
    auto it = std::find(container.begin(), container.end(), element);
    if (it != container.end()) 
    {
        container.erase(it);
    }
    else 
    {
        std::cout << "Элемент не найден!" << std::endl;
    }
}

// Вычисление разницы между максимальным и минимальным элементами
template<typename T>
void Vector<T>::calculateDifference() 
{
    if (container.empty()) 
    {
        std::cout << "Контейнер пуст!" << std::endl;
        return;
    }
    T minElement = *std::min_element(container.begin(), container.end());
    T maxElement = *std::max_element(container.begin(), container.end());
    T difference = maxElement - minElement;

    for (auto& elem : container) 
    {
        elem -= difference;
    }
}

// Печать элементов контейнера
template<typename T>
void Vector<T>::print()
{
    for (const T& elem : container) 
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template class Vector<int>; // Пример явной специализации для int