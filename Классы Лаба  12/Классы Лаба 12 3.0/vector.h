#pragma once
#include <map>
#include <iostream>
#include <algorithm>

template <typename K, typename V>
class Vector 
{
private:
    std::map<K, V> container;

public:
    void addElement(const K& key, const V& value);
    void removeElement(const K& key);
    void findAndAdd(const K& key, const V& value, int position);
    void findAndRemove(const K& key);
    void calculateDifference();
    void display() const;
};