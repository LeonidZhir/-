#pragma once
#include "Triad.h"

class Date : public Triad 
{
private:
    int year;

public:
    // ������������
    Date(); // ��� ����������
    Date(int d, int m, int y); // � �����������
    Date(const Date& d); // �����������

    // ����������
    ~Date();

    // ���������
    int getYear() const;

    // ������������
    void setYear(int y);

    // �������� ���������
    bool operator<(const Date& d) const;
    bool operator>(const Date& d) const;
    bool operator==(const Date& d) const;

    // ���������� ��������� ������
    friend ostream& operator<<(ostream& out, const Date& d);
};