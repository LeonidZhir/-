#include "Triad.h"

// ����������� ��� ����������
Triad::Triad() : first(0), second(0), third(0) {}

// ����������� � �����������
Triad::Triad(int f, int s, int t) : first(f), second(s), third(t) {}

// ����������� �����������
Triad::Triad(const Triad& t) : first(t.first), second(t.second), third(t.third) {}

// ����������
Triad::~Triad() {}

// ���������
int Triad::getFirst() const { return first; }
int Triad::getSecond() const { return second; }
int Triad::getThird() const { return third; }

// ������������
void Triad::setFirst(int f) { first = f; }
void Triad::setSecond(int s) { second = s; }
void Triad::setThird(int t) { third = t; }

// �������� ������������
Triad& Triad::operator=(const Triad& t) 
{
    if (this == &t) return *this;
    first = t.first;
    second = t.second;
    third = t.third;
    return *this;
}

// ���������� ��������� ������
ostream& operator<<(ostream& out, const Triad& t) 
{
    out << "(" << t.first << ", " << t.second << ", " << t.third << ")";
    return out;
}

// ���������� ��������� �����
istream& operator>>(istream& in, Triad& t) 
{
    in >> t.first >> t.second >> t.third;
    return in;
}