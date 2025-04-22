#include <iostream>
#include <cstring>

using namespace std;

// Функция для создания массива префиксов
void computeLPSArray(const char* pattern, int* lps) 
{
    int length = 0; // Длина предыдущего наибольшего префикса
    lps[0] = 0;     // lps[0] всегда 0
    int i = 1;

    // Построение массива lps
    while (pattern[i] != '0') 
    {
        if (pattern[i] == pattern[length]) 
        {
            length++;
            lps[i] = length;
            i++;
        }
        else 
        {
            if (length != 0) 
            {
                length = lps[length - 1]; // Попробуем с предыдущего префикса
            }
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Функция поиска подстроки методом КМП
void KPMSearch(const char* text, const char* pattern) 
{
    int m = strlen(pattern);
    int n = strlen(text);
    int lps[100]; // Массив для хранения префиксов

    computeLPSArray(pattern, lps); // Создаем массив префиксов

    int i = 0; // Индекс для текста
    int j = 0; // Индекс для подстроки

    while (i < n) 
    {
        if (pattern[j] == text[i]) 
        {
            i++;
            j++;
        }

        if (j == m) 
        {
            cout << "Подстрока найдена в позиции: " << i - j << endl;
            j = lps[j - 1]; // Продолжаем искать
        }
        else if (i < n && pattern[j] != text[i]) 
        {
            // Не совпадает
            if (j != 0) 
            {
                j = lps[j - 1]; // Сдвигаем j по массиву lps
            }
            else 
            {
                i++;
            }
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "RU");
    char text[1000], pattern[100];

    cout << "Введите текст: ";
    cin.getline(text, 1000);
    cout << "Введите подстроку для поиска: ";
    cin.getline(pattern, 100);

    KPMSearch(text, pattern); // Вызов функции поиска

    return 0; // Завершение программы
}