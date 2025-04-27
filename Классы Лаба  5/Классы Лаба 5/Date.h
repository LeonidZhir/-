#pragma once
#include "Triada.h"
#include <iostream>

class Date : public Triad 
{
public:
    Date(int day, int month, int year) : Triad(day, month, year) {}

    void changeValues(int day, int month, int year) override 
    {
        first = day; second = month; third = year;
    }

    bool operator==(const Date& d) const 
    {
        return Triad::operator==(d);
    }

    void print() const override 
    {
        cout << "Date: " << first << "/" << second << "/" << third << std::endl; // ÄÄ/ÌÌ/ÃÃÃÃ
    }
};