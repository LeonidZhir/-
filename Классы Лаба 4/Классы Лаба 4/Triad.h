#pragma once
#include <iostream>
using namespace std;
class Triad 
{
private:
    int first;
    int second;
    int third;

public:
    // ������������
    Triad(); // ��� ����������
    Triad(int f, int s, int t); // � �����������
    Triad(const Triad& t); // �����������

    // ����������
    ~Triad();

    // ���������
    int getFirst() const;
    int getSecond() const;
    int getThird() const;

    // ������������
    void setFirst(int f);
    void setSecond(int s);
    void setThird(int t);

    // �������� ������������
    Triad& operator=(const Triad& t);

    // ���������� ����������
    friend ostream& operator<<(ostream& out, const Triad& t);
    friend istream& operator>>(istream& in, Triad& t);
};