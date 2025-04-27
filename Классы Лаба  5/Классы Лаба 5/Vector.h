#pragma once
#include <vector>
#include <iostream>
#include "Triada.h"

class Vector 
{
private:
    vector<Triad*> elements;

public:
    void addElement(Triad* elem) 
    {
        elements.push_back(elem);
    }

    void print() const 
    {
        for (const auto& elem : elements) 
        {
            elem->print();
        }
    }

    ~Vector() 
    {
        for (auto& elem : elements) 
        {
            delete elem; // освобождение памяти
        }
    }
};