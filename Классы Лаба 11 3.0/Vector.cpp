#include "Vector.h"

// ���������� �������� � ���������
template<typename T>
void Vector<T>::addElement(const T& element) 
{
    container.push_back(element);
}

// ���������� �������� �� �������� �������
template<typename T>
void Vector<T>::addAtPosition(size_t position, const T& element) 
{
    if (position <= container.size()) 
    {
        container.insert(container.begin() + position, element);
    }
    else 
    {
        std::cout << "������: ������� ������� �� ������� ����������!" << std::endl;
    }
}

// �������� �������� �� ����������
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
        std::cout << "������� �� ������!" << std::endl;
    }
}

// ���������� ������� ����� ������������ � ����������� ����������
template<typename T>
void Vector<T>::calculateDifference() 
{
    if (container.empty()) 
    {
        std::cout << "��������� ����!" << std::endl;
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

// ������ ��������� ����������
template<typename T>
void Vector<T>::print()
{
    for (const T& elem : container) 
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template class Vector<int>; // ������ ����� ������������� ��� int