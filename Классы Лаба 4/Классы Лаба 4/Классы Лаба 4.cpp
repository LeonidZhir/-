#include "Date.h"

int main() 
{
    setlocale(LC_ALL, "Russian");
    Triad triad1(1, 2, 3);
    Triad triad2;

    cout << "Триада 1: " << triad1 << endl;

    cout << "Введите значения для Триады 2: ";
    cin >> triad2;
    cout << "Триада 2: " << triad2 << endl;

    Date date1(28, 12, 2005);
    Date date2(1, 9, 2001);

    cout << "Дата 1: " << date1 << endl;
    cout << "Дата 2: " << date2 << endl;

    if (date1 > date2) 
    {
        cout << "Дата 1 более поздняя, чем Дата 2." << endl;
    }
    else if (date1 < date2) 
    {
        cout << "Дата 1 более ранняя, чем Дата 2." << endl;
    }
    else 
    {
        cout << "Дата 1 совпадает с Датой 2." << endl;
    }

    return 0;
}