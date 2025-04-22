#include <iostream>
#include <cstring>
#include <algorithm> // Для std::max

using namespace std;

// Максимальный размер алфавита (ASCII)
const int ALPHABET_SIZE = 256;

// Функция для создания таблицы смещений
void createBadCharTable(const char* pattern, int badCharTable[])
{
    // Инициализируем все значения -1
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        badCharTable[i] = -1;
    }

    // Заполняем таблицу последними вхождениями символов подстроки
    int m = strlen(pattern);
    for (int i = 0; i < m; i++)
    {
        badCharTable[(unsigned char)pattern[i]] = i;
    }
}

// Функция поиска подстроки в строке с использованием алгоритма Бойера-Мура
void boyerMooreSearch(const char* text, const char* pattern)
{
    int m = strlen(pattern);
    int n = strlen(text);
    int badCharTable[ALPHABET_SIZE];

    createBadCharTable(pattern, badCharTable);
    int shift = 0;  // Начальный сдвиг

    while (shift <= n - m)
    {
        int j = m - 1;

        // Пока символы совпадают, сдвигаем j
        while (j >= 0 && pattern[j] == text[shift + j])
        {
            j--;
        }

        // Если j < 0, значит, найдено совпадение
        if (j < 0)
        {
            cout << "Подстрока найдена в позиции: " << shift << endl;

            // Сдвигаем на размер подстроки или по таблице смещений
            shift += (shift + m < n) ? m - badCharTable[(unsigned char)text[shift + m]] : 1;
        }
        else
        {
            // Сдвигаем по таблице смещений
            shift += max(1, j - badCharTable[(unsigned char)text[shift + j]]);
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

    boyerMooreSearch(text, pattern);

    return 0;  // Завершение программы
}