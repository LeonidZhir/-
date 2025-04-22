#include "Kvartira.h"

// ����������� ��� ����������
Kvartira::Kvartira() 
    : address("����������"), area(0.0), numberOfRooms(0) {}// �������������� ���� ���������� �� ���������.

// ����������� � �����������
Kvartira::Kvartira(const string& addr, double ar, int rooms)
    : address(addr), area(ar), numberOfRooms(rooms) {}

// ����������� �����������
Kvartira::Kvartira(const Kvartira& other)
    : address(other.address), area(other.area), numberOfRooms(other.numberOfRooms) {}

// ����������
Kvartira::~Kvartira() 
{
    // ����� ����� �������� ��� ��� ������������ ��������, ���� ��� ����������
}

// ������ ��� ��������� �������� �����.
string Kvartira::getAddress() const 
{
    return address;
}

double Kvartira::getArea() const 
{
    return area;
}

int Kvartira::getNumberOfRooms() const 
{
    return numberOfRooms;
}

// ������������
void Kvartira::setAddress(const string& addr) 
{
    address = addr;
}

void Kvartira::setArea(double ar) 
{
    area = ar;
}

void Kvartira::setNumberOfRooms(int rooms) 
{
    numberOfRooms = rooms;
}

// ����� ��� ����������� ���������� � ��������
void Kvartira::displayInfo() const 
{
    cout << "�����: " << address << "\n";
    cout << "�������: " << area << " ��. �\n";
    cout << "���������� ������: " << numberOfRooms << "\n";
}