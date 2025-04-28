#include "Container.h"

void Container::addElement(const Money& money) 
{
    elements.push_back(money);
}

void Container::removeElement(const Money& money) 
{
    auto it = std::remove(elements.begin(), elements.end(), money);
    elements.erase(it, elements.end());
}

int Container::findElement(const Money& money) const 
{
    for (size_t i = 0; i < elements.size(); ++i) 
    {
        if (elements[i] == money) 
        {
            return i;
        }
    }
    return -1; // Не найдено
}

void Container::clear() 
{
    elements.clear();
}

const std::vector<Money>& Container::getElements() const 
{
    return elements;
}
