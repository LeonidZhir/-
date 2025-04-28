#include "Person.h"

Person::Person(const std::string& name, int age) : name(name), age(age) {}

int Person::getAge() const 
{
    return age;
}

const std::string& Person::getName() const 
{
    return name;
}