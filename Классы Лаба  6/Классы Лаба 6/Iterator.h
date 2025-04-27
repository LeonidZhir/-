#pragma once

class Iterator
{
public:
    Iterator(int* ptr) : ptr(ptr) {}
    int& operator*() { return *ptr; }
    Iterator& operator++() { ++ptr; return *this; }
    bool operator!=(const Iterator& other) const { return ptr != other.ptr; }

private:
    int* ptr;
};