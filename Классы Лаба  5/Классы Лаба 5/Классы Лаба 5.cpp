#include <iostream>
#include "Date.h"
#include "Vector.h"

int main() 
{
    setlocale(LC_ALL, "RU");
    Vector vector;

    Date* date1 = new Date(22, 4, 1870);
    Date* date2 = new Date(22, 4, 1870);

    vector.addElement(date1);
    vector.addElement(date2);

    vector.print(); // демонстрация полиморфизма

    if (*date1 == *date2) 
    {
        cout << "Даты совпадают." << endl;
    }
    else 
    {
        cout << "Даты не совпадают." << endl;
    }

    return 0;
}
