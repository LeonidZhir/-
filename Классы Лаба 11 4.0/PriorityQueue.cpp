#include "PriorityQueue.h"
#include <algorithm>

void PriorityQueue::push(int value) 
{
    data.push_back(value);
    std::push_heap(data.begin(), data.end());
}

void PriorityQueue::pop()
{
    std::pop_heap(data.begin(), data.end());
    data.pop_back();
}

int PriorityQueue::top() const 
{
    if (isEmpty())
    {
        throw std::runtime_error("Queue is empty");
    }
    return data.front();
}

bool PriorityQueue::isEmpty() const 
{
    return data.empty();
}

int PriorityQueue::find(int key) const 
{
    auto it = std::find(data.begin(), data.end(), key);
    return (it != data.end()) ? std::distance(data.begin(), it) : -1; // Возвращает индекс или -1
}

void PriorityQueue::remove(int key) 
{
    auto it = std::remove(data.begin(), data.end(), key);
    if (it != data.end())
    {
        data.erase(it, data.end());
        std::make_heap(data.begin(), data.end());
    }
}

void PriorityQueue::process() 
{
    if (data.empty()) return;

    int max = *std::max_element(data.begin(), data.end());
    int min = *std::min_element(data.begin(), data.end());
    int diff = max - min;

    for (auto& elem : data)
    {
        elem -= diff;
    }
}