#pragma once
#include <vector>
#include "Money.h"

class Container 
{
public:
    void addElement(const Money& money);
    void removeElement(const Money& money);
    int findElement(const Money& money) const;
    void clear();
    const std::vector<Money>& getElements() const;

private:
    std::vector<Money> elements;
};