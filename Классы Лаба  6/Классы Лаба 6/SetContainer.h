#pragma once
#include <vector>
#include <iostream>
#include "Iterator.h" // Подключаем заголовок итератора

class SetContainer
{
public:
    // Конструкторы и деструктор
    SetContainer();
    SetContainer(const SetContainer& other);
    ~SetContainer();

    // Операторы
    int& operator[](size_t index);
    bool operator==(const SetContainer& other) const;
    bool operator>(int number) const;
    SetContainer& operator-=(size_t n);

    friend std::ostream& operator<<(std::ostream& os, const SetContainer& set);
    friend std::istream& operator>>(std::istream& is, SetContainer& set);

    Iterator begin() { return Iterator(elements.data()); }
    Iterator end() { return Iterator(elements.data() + elements.size()); }
    size_t size() const { return elements.size(); }
private:
    std::vector<int> elements;
};