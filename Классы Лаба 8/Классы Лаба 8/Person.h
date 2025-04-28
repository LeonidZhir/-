#pragma once
#include <string>
#include <iostream>

class Person 
{
protected:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age);
    virtual ~Person() = default;

    virtual void input() = 0;
    virtual void output() const = 0;

    int getAge() const;
    const std::string& getName() const;
};