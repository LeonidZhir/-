#include "Group.h"
#include <iostream>

Group::Group() {}

Group::~Group() 
{
    for (auto student : students) 
    {
        delete student;
    }
}

void Group::addStudent(Abiturient* student) 
{
    students.push_back(student);
}

void Group::removeStudent() 
{
    if (!students.empty()) 
    {
        delete students.back();
        students.pop_back();
    }
}

void Group::display() const
{
    for (const auto& student : students) 
    {
        student->output();
    }
}

double Group::averageAge() const 
{
    if (students.empty()) return 0.0;

    int totalAge = 0;
    for (const auto& student : students) 
    {
        totalAge += student->getAge();
    }
    return static_cast<double>(totalAge) / students.size();
}

size_t Group::size() const 
{
    return students.size();
}