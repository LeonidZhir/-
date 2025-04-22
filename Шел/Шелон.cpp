#include <iostream>

using namespace std;

// Функция для визуализации массива
void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функция сортировки Шелла
void shellSort(int arr[], int n) 
{
    // Начальное значение интервала
    for (int gap = n / 2; gap > 0; gap /= 2) 
    {
        cout << "Текущий интервал: " << gap << endl;

        // Проход по элементам с интервалом
        for (int i = gap; i < n; i++) 
        {
            int temp = arr[i];
            int j;

            // Сортировка вставками по интервалу
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;

            // Печать текущего состояния массива после каждой вставки
            cout << "После вставки элемента " << temp << ": ";
            printArray(arr, n);
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "RU");
    const int MAX_SIZE = 50; // Максимальный размер массива
    int arr[MAX_SIZE];
    int n;

    cout << "Введите количество элементов в массиве (максимум " << MAX_SIZE << "): ";
    cin >> n;

    if (n > MAX_SIZE) 
    {
        cout << "Количество элементов превышает максимальный размер!" << endl;
        return 1;
    }

    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) 
    {
        cin >> arr[i];
    }

    cout << "Исходный массив: ";
    printArray(arr, n);

    shellSort(arr, n);

    cout << "Отсортированный массив: ";
    printArray(arr, n);

    return 0;
}
