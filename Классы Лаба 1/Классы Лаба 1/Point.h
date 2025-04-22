#pragma once
#include <iostream>
#include <cmath>//��� �������������� ��������, ����� ��� ���������� ����������� �����.
#include <stdexcept>//��� ��������� ����������(������������� �������� ���������).
using namespace std;
struct Pair 
{
    double first;  // ���������� x
    double second; // ���������� y

    void Init(double x, double y);
    void Read();
    void Show() const;
};
class Point 
{
private:
    Pair coordinates;

public:
    void Init(double x, double y);
    double distance() const;
    void Read();
    void Show() const;

    // ������������� ������� ��� �������� �����
    friend Point makePoint(double x, double y);
};