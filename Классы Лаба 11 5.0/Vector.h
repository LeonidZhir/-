#pragma once
#include <queue>
#include <vector>
#include <stdexcept>

template<typename T>
class Vector 
{
private:
    std::priority_queue<T> container;

public:
    // Метод для добавления элемента
    void add(const T& element);

    // Метод для удаления элемента
    void remove(const T& element);

    // Метод для поиска элемента по ключу и добавления на заданную позицию
    void findAndInsert(const T& key, const T& newElement, size_t position);

    // Метод для поиска элемента по ключу и удаления его
    void findAndRemove(const T& key);

    // Метод для нахождения разницы между максимальным и минимальным элементами и вычитание из каждого
    void subtractExtremes();

    // Метод для получения всех элементов (для вывода)
    std::vector<T> getElements() const;
};