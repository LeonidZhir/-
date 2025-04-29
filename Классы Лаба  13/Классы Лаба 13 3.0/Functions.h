#pragma once
#include <iostream>
#include <map>
#include <algorithm>

void addPerson(std::multimap<int, Person>& birthYears, int year, int position)
{
    auto it = birthYears.find(year);
    if (it != birthYears.end())
    {
        // ѕроверка, чтобы позици€ не превышала количество найденных элементов
        int count = std::distance(birthYears.lower_bound(year), birthYears.upper_bound(year));
        if (position >= count) {
            birthYears.emplace(year, Person(year, it->second.name));
        }
        else {
            std::advance(it, position);
            birthYears.emplace(it->first, Person(year, it->second.name));
        }
    }
}

void removePerson(std::multimap<int, Person>& birthYears, int year, const std::string& name)
{
    auto range = birthYears.equal_range(year);
    for (auto it = range.first; it != range.second; ++it)
    {
        if (it->second.name == name)
        {
            birthYears.erase(it);
            return; // ”дал€ем только первого совпавшего человека
        }
    }
}

void calculateDifference(const std::multimap<int, Person>& birthYears)
{
    auto minMax = std::minmax_element(birthYears.begin(), birthYears.end(),
        [](const auto& a, const auto& b)
        {
            return a.second.yearOfBirth < b.second.yearOfBirth;
        });

    int minYear = minMax.first->second.yearOfBirth;
    int maxYear = minMax.second->second.yearOfBirth;
    int difference = maxYear - minYear;

    std::cout << "–азница между максимальным и минимальным годом: " << difference << std::endl;
}