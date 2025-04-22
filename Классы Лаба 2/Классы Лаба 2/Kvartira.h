#pragma once
#include <string>
#include <iostream>
using namespace std;
class Kvartira 
{
private:
    string address;// хранит адрес квартиры.
    double area;// хранит площадь квартиры.
    int numberOfRooms;// хранит количество комнат в квартире.

public:
    // Конструктор без параметров
    Kvartira();

    // Конструктор с параметрами
    Kvartira(const string& addr, double ar, int rooms);

    // Конструктор копирования
    Kvartira(const Kvartira& other);

    // Деструктор
    ~Kvartira();

    // Методы для получения значений полей.
    string getAddress() const;
    double getArea() const;
    int getNumberOfRooms() const;

    // Модификаторы
    void setAddress(const string& addr);
    void setArea(double ar);
    void setNumberOfRooms(int rooms);

    // Метод для отображения информации о квартире
    void displayInfo() const;
};