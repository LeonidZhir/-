#include "vector.h"

// ����� ��� ���������� �������� � ���������
template <typename K, typename V>
void Vector<K, V>::addElement(const K& key, const V& value) 
{
    container[key] = value;
}

// ����� ��� �������� �������� �� ����������
template <typename K, typename V>
void Vector<K, V>::removeElement(const K& key) 
{
    container.erase(key);
}

// ����� �������� � �������� ������ � ���������� ��� �� �������� �������
template <typename K, typename V>
void Vector<K, V>::findAndAdd(const K& key, const V& value, int position) 
{
    auto it = container.find(key);
    if (it != container.end()) 
    {
        // ��������� �� �������� �������
        auto insertIt = container.begin();
        std::advance(insertIt, position);
        container.insert(insertIt, *it);
    }
}

// ����� �������� � �������� ������ � �������� ��� �� ����������
template <typename K, typename V>
void Vector<K, V>::findAndRemove(const K& key) 
{
    auto it = container.find(key);
    if (it != container.end()) 
    {
        container.erase(it);
    }
}

// ����� ��� ���������� ������� ����� ������������ � ����������� ����������
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

// ����� ��� ����������� ����������� ����������
template <typename K, typename V>
void Vector<K, V>::display() const 
{
    for (const auto& elem : container)
    {
        std::cout << "����: " << elem.first << ", ���a: " << elem.second << std::endl;
    }
}

// �� �������� ���� �������������� ��������� ����� ��� ����������� �����
template class Vector<int, double>; // ��������, ��� int � double