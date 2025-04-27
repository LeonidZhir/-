#pragma once
using namespace std;
class Triad 
{
protected:
    int first;
    int second;
    int third;

public:
    Triad(int f, int s, int t) : first(f), second(s), third(t) {}
    virtual ~Triad() {}

    virtual void changeValues(int f, int s, int t)
    {
        first = f; second = s; third = t;
    }

    virtual bool operator==(const Triad& t) const 
    {
        return first == t.first && second == t.second && third == t.third;
    }

    virtual void print() const = 0; // виртуальная функция
};