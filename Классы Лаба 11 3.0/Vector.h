#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class Vector 
{
private:
    std::vector<T> container;

public:
    void addElement(const T& element);
    void addAtPosition(size_t position, const T& element);
    void removeElement(const T& element);
    void calculateDifference();
    void print();
};