#include "Vector.h"

template<typename T>
void Vector<T>::add(const T& element) 
{
    container.push(element);
}

template<typename T>
void Vector<T>::remove(const T& element) 
{
    // �������� ��������� �������
    std::priority_queue<T> temp;

    while (!container.empty()) 
    {
        T current = container.top();
        container.pop();
        if (current != element)
        {
            temp.push(current);
        }
    }
    container = std::move(temp);
}

template<typename T>
void Vector<T>::findAndInsert(const T& key, const T& newElement, size_t position) 
{
    std::priority_queue<T> temp;
    size_t currentPosition = 0;
    bool inserted = false;

    while (!container.empty()) 
    {
        T current = container.top();
        container.pop();

        if (current == key && !inserted && currentPosition == position) 
        {
            temp.push(newElement);
            inserted = true;
        }

        temp.push(current);
        currentPosition++;
    }

    // ���� ������� �� ������, ������� ����� ������� � �����
    if (!inserted) 
    {
        temp.push(newElement);
    }
    container = std::move(temp);
}

template<typename T>
void Vector<T>::findAndRemove(const T& key) 
{
    remove(key);
}

template<typename T>
void Vector<T>::subtractExtremes() 
{
    if (container.empty()) return;

    T maxElement = container.top();
    container.pop(); // ������� ������������ �������

    T minElement = maxElement; //������������, ��� ������������ ������������ � ����������� - ����������
    std::priority_queue<T> temp;

    while (!container.empty()) 
    {
        T current = container.top();
        container.pop();
        if (current < minElement) 
        {
            minElement = current;
        }
        temp.push(current);
    }

    // ��������� �������
    T difference = maxElement - minElement;

    // ��������������� ������� � �������� ������� �� ������� ��������
    container = std::move(temp);
    temp = std::priority_queue<T>();

    while (!container.empty())
    {
        temp.push(container.top() - difference);
        container.pop();
    }

    container = std::move(temp);
}

template<typename T>
std::vector<T> Vector<T>::getElements() const
{
    std::priority_queue<T> temp = container;
    std::vector<T> elements;

    while (!temp.empty()) 
    {
        elements.push_back(temp.top());
        temp.pop();
    }

    return elements;
}

// �� �������� ����� ������� �������������� ������
template class Vector<int>; // ��� ������ �������� ���