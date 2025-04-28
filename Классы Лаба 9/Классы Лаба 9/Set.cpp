#include "Set.h"

void Set::add(int value)
{
    if (contains(value))
    {
        throw AlreadyExists();
    }
    elements.push_back(value);
}

void Set::remove(int value) 
{
    auto it = std::find(elements.begin(), elements.end(), value);
    if (it != elements.end())
    {
        elements.erase(it);
    }
    else 
    {
        throw ElementNotFound();
    }
}

bool Set::contains(int value) const 
{
    return std::find(elements.begin(), elements.end(), value) != elements.end();
}

int Set::operator[](size_t index) const 
{
    if (index >= elements.size()) 
    {
        throw IndexOutOfBounds();
    }
    return elements[index];
}

bool Set::operator==(const Set& other) const 
{
    return elements == other.elements;
}

bool Set::operator>(int value) const 
{
    return contains(value);
}
