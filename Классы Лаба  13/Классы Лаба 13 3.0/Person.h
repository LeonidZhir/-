#pragma once
#include <iostream>
#include <string>

class Person
{
public:
    int yearOfBirth;
    std::string name;

    Person(int year, const std::string& name) : yearOfBirth(year), name(name) {}

    bool operator<(const Person& other) const
    {
        return yearOfBirth < other.yearOfBirth;
    }

    bool operator==(const Person& other) const
    {
        return yearOfBirth == other.yearOfBirth && name == other.name;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& person)
    {
        os << person.name << " (" << person.yearOfBirth << ")";
        return os;
    }
};