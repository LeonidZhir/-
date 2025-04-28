#pragma once
#include <iostream>
#include <vector>

template<typename T>
class Set 
{
private:
    std::vector<T> elements;

public:
    Set() = default;
    ~Set() = default;

    // �������� ������� �� �������
    T& operator[](size_t index) 
    {
        return elements[index];
    }

    // �������� �������� �� ���������
    bool operator==(const Set<T>& other) const 
    {
        return elements == other.elements;
    }

    // �������� ��������������
    bool operator>(const T& value) const 
    {
        return std::find(elements.begin(), elements.end(), value) != elements.end();
    }

    void add(const T& value) 
    {
        if (!(*this > value)) 
        {
            elements.push_back(value);
        }
    }

    void print() const
    {
        for (const auto& element : elements) 
        {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};