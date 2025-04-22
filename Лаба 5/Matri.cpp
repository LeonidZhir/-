#include <iostream>
#include <clocale>
using namespace std;
// Функция для транспонирования квадратной матрицы
void trans(int arr[10][10], int n) 
{
    for (int i = 0; i < n; ++i) 
    {
        for (int j = i + 1; j < n; ++j) 
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}
// Функция для проверки симметричности матрицы
bool Symm(int arr[10][10], int n) 
{
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            if (arr[i][j] != arr[j][i]) 
            {
                return false; // Если найдены разные элементы, матрица не симметрична
            }
        }
    }
    return true; // Если все элементы равны, матрица симметрична
}

int main() 
{
    setlocale(LC_ALL, "RU");
    int n;
    cout << "Введите размер квадратной матрицы: ";
    cin >> n;

    // Объявление квадратной матрицы размером n x n
    int arr[10][10];

    // Заполнение матрицы
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            cout << "Элемент [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    // Транспонирование матрицы
    trans(arr, n);

    // Проверка на симметричность
    if (Symm(arr, n)==1) 
    {
        cout << "Матрица является симметрической." << endl;
    }
    else 
    {
        cout << "Матрица не является симметрической." << endl;
    }

    // Вывод транспонированной матрицы
    cout << "Транспонированная матрица:" << endl;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}