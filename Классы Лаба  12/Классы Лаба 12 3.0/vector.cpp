#include "vector.h"

// Метод для добавления элемента в контейнер
template <typename K, typename V>
void Vector<K, V>::addElement(const K& key, const V& value) 
{
    container[key] = value;
}

// Метод для удаления элемента из контейнера
template <typename K, typename V>
void Vector<K, V>::removeElement(const K& key) 
{
    container.erase(key);
}

// Поиск элемента с заданным ключом и добавление его на заданную позицию
template <typename K, typename V>
void Vector<K, V>::findAndAdd(const K& key, const V& value, int position) 
{
    auto it = container.find(key);
    if (it != container.end()) 
    {
        // Добавляем на заданную позицию
        auto insertIt = container.begin();
        std::advance(insertIt, position);
        container.insert(insertIt, *it);
    }
}

// Поиск элемента с заданным ключом и удаление его из контейнера
template <typename K, typename V>
void Vector<K, V>::findAndRemove(const K& key) 
{
    auto it = container.find(key);
    if (it != container.end()) 
    {
        container.erase(it);
    }
}

// Метод для нахождения разницы между максимальным и минимальным элементами
template <typename K, typename V>
void Vector<K, V>::calculateDifference() 
{
    if (container.empty()) return;

    auto maxIt = std::max_element(container.begin(), container.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; });

    auto minIt = std::min_element(container.begin(), container.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; });

    V difference = maxIt->second - minIt->second;

    for (auto& elem : container) 
    {
        elem.second -= difference;
    }
}

// Метод для отображения содержимого контейнера
template <typename K, typename V>
void Vector<K, V>::display() const 
{
    for (const auto& elem : container)
    {
        std::cout << "Ключ: " << elem.first << ", Ценa: " << elem.second << std::endl;
    }
}

// Не забудьте явно инстанцировать шаблонный класс для необходимых типов
template class Vector<int, double>; // например, для int и double