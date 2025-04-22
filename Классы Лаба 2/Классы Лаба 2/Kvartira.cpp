#include "Kvartira.h"

// Конструктор без параметров
Kvartira::Kvartira() 
    : address("Неизвестно"), area(0.0), numberOfRooms(0) {}// Инициализирует поля значениями по умолчанию.

// Конструктор с параметрами
Kvartira::Kvartira(const string& addr, double ar, int rooms)
    : address(addr), area(ar), numberOfRooms(rooms) {}

// Конструктор копирования
Kvartira::Kvartira(const Kvartira& other)
    : address(other.address), area(other.area), numberOfRooms(other.numberOfRooms) {}

// Деструктор
Kvartira::~Kvartira() 
{
    // Здесь можно добавить код для освобождения ресурсов, если это необходимо
}

// Методы для получения значений полей.
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

// Модификаторы
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

// Метод для отображения информации о квартире
void Kvartira::displayInfo() const 
{
    cout << "Адрес: " << address << "\n";
    cout << "Площадь: " << area << " кв. м\n";
    cout << "Количество комнат: " << numberOfRooms << "\n";
}