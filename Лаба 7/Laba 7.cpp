#include <iostream>
#include <string>

using namespace std;

// Первая перегруженная функция: принимает номер года и возвращает название эпохи
string getEraName(int year) 
{
    setlocale(LC_ALL, "RU");
    if (year < 1) 
    {
        return "Некорректный год. Введите положительное число.";
    }
    else if (year >= 1 && year <= 1868) 
    {
        return "Эпоха Эдо (Токугава)";
    }
    else if (year >= 1869 && year <= 1912) 
    {
        return "Эпоха Мэйдзи";
    }
    else if (year >= 1913 && year <= 1926) 
    {
        return "Эпоха Тайсё";
    }
    else if (year >= 1927 && year <= 1989) 
    {
        return "Эпоха Сёва";
    }
    else if (year >= 1990) 
    {
        return "Эпоха Хэйсэй";
    }
    else 
    {
        return "Некорректный год.";
    }
}

// Вторая перегруженная функция: принимает номер года и название эпохи, возвращает описание
string getEraName(int year, const string& description) 
{
    cout << "Главное событие " << year << " года: "<< description;
    return "";
}

int main() 
{
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    system("cls");
    int year;
    cout << "Введите год: ";
    cin >> year;

    // Вызов первой перегруженной функции
    string eraName = getEraName(year);
    cout << "Название эпохи для года " << year << ": " << eraName << endl;

    // Вызов второй перегруженной функции с описанием
    string description;
    cout << "Введите главное событие " << year <<" года: ";
    cin >> description;
    string EraInfo = getEraName(year, description);
    cout << EraInfo << endl;

    return 0;
}