#pragma once
#include <vector>
#include "Abiturient.h"

class Group 
{
private:
    std::vector<Abiturient*> students;

public:
    Group();
    ~Group();

    void addStudent(Abiturient* student);
    void removeStudent();
    void display() const;
    double averageAge() const;
    size_t size() const;
};