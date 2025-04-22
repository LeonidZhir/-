#include "money.h"

// ����������� ��� ����������
Money::Money() : rubles(0), kopecks(0) {}

// ����������� � �����������
Money::Money(long r, int k) : rubles(r), kopecks(k) 
{
    if (kopecks >= 100) 
    {
        rubles += kopecks / 100;
        kopecks %= 100;
    }
}

// ����������� �����������
Money::Money(const Money& other) : rubles(other.rubles), kopecks(other.kopecks) {}

// ����������
Money::~Money() {} // ��������� ����� �� ���������� ������������ ������, ���������� �� ��������� ������� ��������.

// ��������� ���������� �������� rubles � kopecks.
long Money::getRubles() const 
{
    return rubles;
}

int Money::getKopecks() const 
{
    return kopecks;
}

// ������������ ������������� ��������, ����������� ��, ���� ������� ��������� 100.
void Money::setRubles(long r) 
{
    rubles = r;
}

void Money::setKopecks(int k)
{
    if (k >= 100) 
    {
        rubles += k / 100;
        kopecks = k % 100;
    }
    else 
    {
        kopecks = k;
    }
}

// ���������� �������� ������������
Money& Money::operator=(const Money& other) 
{
    if (this != &other) 
    {
        rubles = other.rubles;
        kopecks = other.kopecks;
    }
    return *this;
}

// ���������� �������� ����� � ������
ostream& operator<<(ostream& os, const Money& money) 
{
    os << money.getRubles() << ',' << (money.getKopecks() < 10 ? "0" : "") << money.getKopecks();
    return os;
}

istream& operator>>(istream& is, Money& money) 
{
    long r;
    int k;
    char comma;
    is >> r >> comma >> k;
    money = Money(r, k);
    return is;
}

// ���������� �������� ���������
bool Money::operator>(const Money& other) const 
{
    return rubles > other.rubles || (rubles == other.rubles && kopecks > other.kopecks);
}

bool Money::operator<(const Money& other) const 
{
    return rubles < other.rubles || (rubles == other.rubles && kopecks < other.kopecks);
}

bool Money::operator==(const Money& other) const 
{
    return rubles == other.rubles && kopecks == other.kopecks;
}

// ���������� �������� ��������
Money Money::operator+(double amount) const 
{
    long r = static_cast<long>(amount);
    int k = static_cast<int>((amount - r) * 100);
    return Money(rubles + r, kopecks + k);
}