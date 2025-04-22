#include <iostream>
#include "money.h"

int main() 
{
    setlocale(LC_ALL, "Russian");
    // Создание объектов Money
    Money money1(7, 25); // 7 рублей 25 копеек
    Money money2(5, 25);  // 5 рублей 25 копеек

    // Демонстрация перегрузки операций вывода
    cout << "Деньги 1: " << money1 << endl;
    cout << "Деньги 2: " << money2 << endl;

    // Сложение суммы и дробного числа
    Money result = money1 + 2.25; // 2 рубля 25 копеек
    cout << "Результат добавления 2,25 к Деньгам 1: " << result << endl;

    // Операции сравнения
    if (money1 > money2) 
    {
        cout << "Деньги 1 больше, чем Деньги 2." << endl;
    }
    else if (money1 < money2) 
    {
        cout << "Деньги 1 меньше, чем Деньги 2." << endl;
    }
    else 
    {
        cout << "Деньги 1 равны Деньгам 2." << endl;
    }

    // Ввод объекта Money
    Money money3;
    cout << "Введите деньги в формате (рубли, копейки): ";
    cin >> money3;
    cout << "Введено: " << money3 << endl;

    // Демонстрация перегрузки операции присваивания
    Money money4 = money1; // Копирование money1 в money4
    cout << "Деньги 4 (копия Денег 1): " << money4 << endl;

    return 0;
}