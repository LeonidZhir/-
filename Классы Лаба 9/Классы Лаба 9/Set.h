#pragma once
#include <vector>
#include "error.h"

class Set 
{
public:
    Set() = default;

    void add(int value);
    void remove(int value);
    bool contains(int value) const;

    int operator[](size_t index) const;
    bool operator==(const Set& other) const;
    bool operator>(int value) const;

private:
    std::vector<int> elements;
};
