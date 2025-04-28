#include "Abiturient.h"
#include <iostream>

Abiturient::Abiturient(const std::string& name, int age, int score, const std::string& specialty)
    : Person(name, age), score(score), specialty(specialty) {
}

void Abiturient::input() 
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите имя: ";
    std::cin >> name;
    std::cout << "Введите возраст: ";
    std::cin >> age;
    std::cout << "Введите количество баллов: ";
    std::cin >> score;
    std::cout << "Введите специальность: ";
    std::cin >> specialty;
}

void Abiturient::output() const 
{
    std::cout << "Имя: " << name << ", Возраст: " << age
        << ", Баллы: " << score << ", Специальность: " << specialty << std::endl;
}

int Abiturient::getScore() const 
{
    return score;
}

const std::string& Abiturient::getSpecialty() const 
{
    return specialty;
}