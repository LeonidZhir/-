#include "Point.h"

void Pair::Init(double x, double y)//  �������������� ����������, ��������, ��� ��� ���������������. ���� ���� �� ���� ���������� ������������, ������������� ���������� invalid_argument.
{
    if (x < 0 || y < 0) 
    {
        throw invalid_argument("���������� ������ ���� ����������������.");
    }
    first = x;
    second = y;
}

void Pair::Read() // ����������� � ������������ ���� ��������� � �������������� ��.
{
    double x, y;
    cout << "������� ���������� (x y): ";
    cin >> x >> y;
    Init(x, y);
}

void Pair::Show() const // ������� ������� ���������� �� �����.
{
    cout << "����������: (" << first << ", " << second << ")\n";
}

void Point::Init(double x, double y) // �������������� ���������� �����, ������� ����� Init ��������� Pair.
{
    coordinates.Init(x, y);
}

double Point::distance() const // ��������� � ���������� ���������� �� ����� �� ������ ��������� (0, 0) �� ������� ���������� ����������
{
    return sqrt(coordinates.first * coordinates.first + coordinates.second * coordinates.second);
}

void Point::Read() // �������� ����� Read ��������� Pair ��� ����� ���������.
{
    coordinates.Read();
}

void Point::Show() const // �������� ����� Show ��������� Pair ��� ����������� ���������.
{
    coordinates.Show();
}

Point makePoint(double x, double y) // ��������� ��������� ������ Point, ������������� ��� ����������.
{
    Point p;
    p.Init(x, y);
    return p;
}