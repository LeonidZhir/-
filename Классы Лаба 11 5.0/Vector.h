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
    // ����� ��� ���������� ��������
    void add(const T& element);

    // ����� ��� �������� ��������
    void remove(const T& element);

    // ����� ��� ������ �������� �� ����� � ���������� �� �������� �������
    void findAndInsert(const T& key, const T& newElement, size_t position);

    // ����� ��� ������ �������� �� ����� � �������� ���
    void findAndRemove(const T& key);

    // ����� ��� ���������� ������� ����� ������������ � ����������� ���������� � ��������� �� �������
    void subtractExtremes();

    // ����� ��� ��������� ���� ��������� (��� ������)
    std::vector<T> getElements() const;
};