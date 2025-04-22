#pragma once
#include <iostream>
using namespace std;
class Money 
{
private:
    long rubles;    // целая часть (рубли)
    int kopecks;    // дробная часть (копейки)

public:
    // Конструкторы
    Money();  // Конструктор без параметров
    Money(long r, int k);  // Конструктор с параметрами
    Money(const Money& other);  // Конструктор копирования

    // Деструктор
    ~Money();

    // Селекторы
    long getRubles() const;
    int getKopecks() const;

    // Модификаторы
    void setRubles(long r);
    void setKopecks(int k);

    // Перегрузка операции присваивания
    Money& operator=(const Money& other);

    // Перегрузка операций ввода и вывода
    friend ostream& operator<<(ostream& os, const Money& money);
    friend istream& operator>>(istream& is, Money& money);

    // Перегрузка операций сравнения
    bool operator>(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator==(const Money& other) const;

    // Перегрузка операции сложения
    Money operator+(double amount) const;  // Сложение суммы и дробного числа
};