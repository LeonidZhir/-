#include <iostream>
#include <string>

using namespace std;

// Функция для поиска подстроки в строке
void naiveSearch(const string& text, const string& pattern) 
{
    int n = text.size();
    int m = pattern.size();

    for (int i = 0; i <= n - m; i++) 
    {
        int j;
        for (j = 0; j < m; j++) 
        {
            if (text[i + j] != pattern[j]) 
            {
                break; // Если символы не совпадают, выходим из внутреннего цикла
            }
        }

        // Если все символы совпали
        if (j == m) 
        {
            cout << "Подстрока найдена на позиции: " << i << endl;
        }
    }
}
int main() 
{
    setlocale(LC_ALL, "RU");
    string text, pattern;
    cout << "Введите текст: ";
    getline(cin, text);
    cout << "Введите подстроку для поиска: ";
    getline(cin, pattern);
    naiveSearch(text, pattern);
    return 0;
}