#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "Person.h"
#include "Functions.h"

int main()
{
    setlocale(LC_ALL, "Russinan");
    system("chcp 1251");
    system("cls");
    // Контейнер-словарь с дубликатами
    std::multimap<int, Person> birthYears;

    // Заполнение контейнера
    birthYears.emplace(1984, Person(1987, "Иван"));
    birthYears.emplace(1990, Person(1990, "Максим"));
    birthYears.emplace(1987, Person(1987, "Черешня"));

    // Задание 3: Найти элемент с заданным ключом и добавить его на заданную позицию
    addPerson(birthYears, 1990, 2); // Добавляем на позицию 1

    // Задание 4: Найти элемент с заданным ключом и удалить его из контейнера
    removePerson(birthYears, 1984, "Иван"); // Удаляем только Иван

    // Задание 5: Найти разницу между максимальным и минимальным элементами контейнера
    calculateDifference(birthYears);

    // Сортировка по возрастанию и убыванию
    std::vector<std::pair<int, Person>> sortedBirthYears(birthYears.begin(), birthYears.end());

    // Убывание
    std::sort(sortedBirthYears.begin(), sortedBirthYears.end(), std::greater<>());

    // Вывод результатов в порядке убывания
    std::cout << "Отсортировано по убыванию:\n";
    for (const auto& p : sortedBirthYears)
    {
        std::cout << p.second << std::endl;
    }

    // Возрастание
    std::sort(sortedBirthYears.begin(), sortedBirthYears.end());

    // Вывод результатов в порядке возрастания
    std::cout << "Отсортировано по возрастанию:\n";
    for (const auto& p : sortedBirthYears)
    {
        std::cout << p.second << std::endl;
    }

    return 0;
}