#include "Money.h"

Money::Money(double amount) : amount(amount) {}

double Money::getAmount() const 
{
    return amount;
}

bool Money::operator==(const Money& other) const 
{
    return amount == other.amount;
}

Money Money::operator+(const Money& other) const
{
    return Money(amount + other.amount);
}

Money Money::operator-(const Money& other) const
{
    return Money(amount - other.amount);
}

std::ostream& operator<<(std::ostream& os, const Money& money) 
{
    os << money.amount;
    return os;
}

std::istream& operator>>(std::istream& is, Money& money) 
{
    is >> money.amount;
    return is;
}
