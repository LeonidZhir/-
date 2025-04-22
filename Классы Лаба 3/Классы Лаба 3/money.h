#pragma once
#include <iostream>
using namespace std;
class Money 
{
private:
    long rubles;    // ����� ����� (�����)
    int kopecks;    // ������� ����� (�������)

public:
    // ������������
    Money();  // ����������� ��� ����������
    Money(long r, int k);  // ����������� � �����������
    Money(const Money& other);  // ����������� �����������

    // ����������
    ~Money();

    // ���������
    long getRubles() const;
    int getKopecks() const;

    // ������������
    void setRubles(long r);
    void setKopecks(int k);

    // ���������� �������� ������������
    Money& operator=(const Money& other);

    // ���������� �������� ����� � ������
    friend ostream& operator<<(ostream& os, const Money& money);
    friend istream& operator>>(istream& is, Money& money);

    // ���������� �������� ���������
    bool operator>(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator==(const Money& other) const;

    // ���������� �������� ��������
    Money operator+(double amount) const;  // �������� ����� � �������� �����
};