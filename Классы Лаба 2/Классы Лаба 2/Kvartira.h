#pragma once
#include <string>
#include <iostream>
using namespace std;
class Kvartira 
{
private:
    string address;// ������ ����� ��������.
    double area;// ������ ������� ��������.
    int numberOfRooms;// ������ ���������� ������ � ��������.

public:
    // ����������� ��� ����������
    Kvartira();

    // ����������� � �����������
    Kvartira(const string& addr, double ar, int rooms);

    // ����������� �����������
    Kvartira(const Kvartira& other);

    // ����������
    ~Kvartira();

    // ������ ��� ��������� �������� �����.
    string getAddress() const;
    double getArea() const;
    int getNumberOfRooms() const;

    // ������������
    void setAddress(const string& addr);
    void setArea(double ar);
    void setNumberOfRooms(int rooms);

    // ����� ��� ����������� ���������� � ��������
    void displayInfo() const;
};