#pragma once
#include "Person.h"

class Abiturient : public Person 
{
private:
    int score;
    std::string specialty;

public:
    Abiturient(const std::string& name, int age, int score, const std::string& specialty);
    void input() override;
    void output() const override;

    int getScore() const;
    const std::string& getSpecialty() const;
};