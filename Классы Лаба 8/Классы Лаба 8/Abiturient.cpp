#include "Abiturient.h"
#include <iostream>

Abiturient::Abiturient(const std::string& name, int age, int score, const std::string& specialty)
    : Person(name, age), score(score), specialty(specialty) {
}

void Abiturient::input() 
{
    setlocale(LC_ALL, "Russian");
    std::cout << "������� ���: ";
    std::cin >> name;
    std::cout << "������� �������: ";
    std::cin >> age;
    std::cout << "������� ���������� ������: ";
    std::cin >> score;
    std::cout << "������� �������������: ";
    std::cin >> specialty;
}

void Abiturient::output() const 
{
    std::cout << "���: " << name << ", �������: " << age
        << ", �����: " << score << ", �������������: " << specialty << std::endl;
}

int Abiturient::getScore() const 
{
    return score;
}

const std::string& Abiturient::getSpecialty() const 
{
    return specialty;
}