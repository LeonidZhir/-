#pragma once
#include <vector>
#include <stdexcept>

class PriorityQueue
{
private:
    std::vector<int> data;

public:
    void push(int value);
    void pop();
    int top() const;
    bool isEmpty() const;
    int find(int key) const; // ������� 3
    void remove(int key); // ������� 4
    void process(); // ������� 5
};