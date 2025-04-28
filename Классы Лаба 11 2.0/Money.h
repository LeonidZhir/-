#pragma once
#include <iostream>

class Money 
{
public:
    Money(double amount = 0.0);
    double getAmount() const;
    bool operator==(const Money& other) const;
    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Money& money);
    friend std::istream& operator>>(std::istream& is, Money& money);

private:
    double amount;
};