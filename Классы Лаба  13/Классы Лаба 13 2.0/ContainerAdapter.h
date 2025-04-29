#pragma once
#include <vector>
#include <algorithm>
#include "Money.h"

class ContainerAdapter 
{
private:
    std::vector<Money> container;

public:
    void add(const Money& m)
    {
        container.push_back(m);
    }

    void remove(const Money& m) 
    {
        container.erase(std::remove(container.begin(), container.end(), m), container.end());
    }

    void replaceIf(const Money& oldValue, const Money& newValue) 
    {
        std::replace_if(container.begin(), container.end(),
            [&oldValue](const Money& m) { return m == oldValue; }, newValue);
    }

    void sortAscending()
    {
        std::sort(container.begin(), container.end());
    }

    void sortDescending() 
    {
        std::sort(container.rbegin(), container.rend());
    }

    void print() const 
    {
        for (const auto& money : container) 
        {
            std::cout << money << " ";
        }
        std::cout << std::endl;
    }

    Money findMax() const 
    {
        return *std::max_element(container.begin(), container.end());
    }

    Money findMin() const 
    {
        return *std::min_element(container.begin(), container.end());
    }

    void forEach(void (*func)(const Money&)) const 
    {
        std::for_each(container.begin(), container.end(), func);
    }
};