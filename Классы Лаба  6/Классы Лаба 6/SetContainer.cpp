#include "SetContainer.h"
#include <algorithm>

// Конструкторы
SetContainer::SetContainer() {}

SetContainer::SetContainer(const SetContainer& other) : elements(other.elements) {}

// Деструктор
SetContainer::~SetContainer() {}

// Оператор []
int& SetContainer::operator[](size_t index)
{
    return elements[index];
}

// Оператор равенства
bool SetContainer::operator==(const SetContainer& other) const
{
    return elements == other.elements;
}

// Оператор большего
bool SetContainer::operator>(int number) const
{
    return std::find(elements.begin(), elements.end(), number) != elements.end();
}

// Оператор -=
SetContainer& SetContainer::operator-=(size_t n)
{
    if (n < elements.size())
    {
        std::rotate(elements.begin(), elements.begin() + n, elements.end());
    }
    return *this;
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const SetContainer& set)
{
    os << "{ ";
    for (const auto& el : set.elements)
    {
        os << el << " ";
    }
    os << "}";
    return os;
}

// Оператор ввода
std::istream& operator>>(std::istream& is, SetContainer& set)
{
    int value;
    while (is >> value)
    {
        set.elements.push_back(value);
    }
    return is;
}