#pragma once
#include <iostream>

class Money 
{
public:
    Money(int rub = 0, int kop = 0);
    Money(const Money& other);

    // ���������� ����������
    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator>(const Money& other) const;

    // ��������� ��������
    int getRub() const;
    int getKop() const;

    // �����
    friend std::ostream& operator<<(std::ostream& out, const Money& money);
    friend std::istream& operator>>(std::istream& in, Money& money);

private:
    long rub; // �����
    int kop; // �������
};