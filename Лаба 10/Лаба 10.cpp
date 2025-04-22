#include <iostream>
#include <clocale>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");
    int rows, cols;

    // Ввод количества строк и столбцов
    cout << "Введите количество строк в матрице: ";
    cin >> rows;
    cout << "Введите количество столбцов в матрице: ";
    cin >> cols;

    // Создание двумерного массива
    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) 
    {
        arr[i] = new int[cols];
    }

    // Ввод элементов матрицы
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << "Элемент [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> arr[i][j];
        }
    }

    // Ввод номера строки для добавления
    int c;
    cout << "Введите номер строки для добавления (0 до " << rows << "): ";
    cin >> c;

    // Проверка корректности введенного номера строки
    if (c < 0 || c > rows) 
    {
        cout << "Некорректный номер строки!" << endl;
        return 1; // Завершаем программу с ошибкой
    }

    // Создание нового массива с увеличенным количеством строк
    int** newarr = new int* [rows + 1];
    for (int i = 0; i < rows + 1; ++i) 
    {
        newarr[i] = new int[cols];
    }

    // Копирование старых строк и добавление новой строки
    for (int i = 0, j = 0; i < rows + 1; ++i) 
    {
        if (i == c) 
        {
            // Ввод новой строки
            cout << "Введите элементы новой строки:" << endl;
            for (int k = 0; k < cols; ++k) 
            {
                cout << "Элемент новой строки [" << c + 1 << "][" << k + 1 << "]: ";
                cin >> newarr[i][k];
            }
        }
        else 
        {
            // Копирование старых строк
            if (i < c) 
            {
                for (int k = 0; k < cols; ++k) 
                {
                    newarr[i][k] = arr[j][k];
                }
            }
            else 
            {
                // Сдвиг строк вниз
                for (int k = 0; k < cols; ++k) 
                {
                    newarr[i][k] = arr[j][k];
                }
                j++; // Увеличиваем j, так как мы уже скопировали одну старую строку
            }
        }
    }

    // Освобождение памяти старого массива
    for (int i = 0; i < rows; ++i) 
    {
        delete[] arr[i];
    }
    delete[] arr;

    arr = newarr; // Перенаправляем указатель на новый массив
    rows++; // Увеличиваем количество строк

    // Вывод обновленного массива
    cout << "Обновленная матрица:" << endl;
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Освобождение памяти нового массива
    for (int i = 0; i < rows; ++i) 
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}