#include <iostream>
#include <iomanip> // Для std::setw
using namespace std;

// Функция для слияния двух серий
void merge(int arr[], int start1, int end1, int start2, int end2) 
{
    int i = start1; // Индекс для первой серии
    int j = start2; // Индекс для второй серии
    int k = 0; // Индекс для результирующего массива

    int size = end2 - start1 + 1; // Размер результирующего массива
    int* temp = new int[size]; // Временный массив для хранения результата

    // Слияние серий
    while (i <= end1 && j <= end2) 
    {
        if (arr[i] <= arr[j]) 
        {
            temp[k++] = arr[i++];
        }
        else 
        {
            temp[k++] = arr[j++];
        }
    }

    // Копируем оставшиеся элементы первой серии
    while (i <= end1) 
    {
        temp[k++] = arr[i++];
    }

    // Копируем оставшиеся элементы второй серии
    while (j <= end2) 
    {
        temp[k++] = arr[j++];
    }

    // Копируем отсортированные элементы обратно в оригинальный массив
    for (int m = 0; m < size; m++) 
    {
        arr[start1 + m] = temp[m];
    }

    delete[] temp; // Освобождение памяти временного массива

    // Визуализация текущего состояния массива после слияния
    cout << "После слияния серий: ";
    for (int m = 0; m < size; m++) 
    {
        cout << setw(4) << arr[start1 + m];
    }
    cout << endl;
}

// Функция для естественного слияния
void naturalMergeSort(int arr[], int size) 
{
    bool sorted = false;

    while (!sorted) 
    {
        sorted = true;
        int start1 = 0;

        // Разделение на серии
        while (start1 < size) 
        {
            int end1 = start1;

            // Находим конец первой серии
            while (end1 + 1 < size && arr[end1] <= arr[end1 + 1]) 
            {
                end1++;
            }

            if (end1 == size - 1) break; // Если достигнут конец массива

            int start2 = end1 + 1;

            // Находим конец второй серии
            while (start2 < size && arr[start2 - 1] > arr[start2]) 
            {
                start2++;
            }

            // Слияние серий
            merge(arr, start1, end1, end1 + 1, start2 - 1);

            // Если произошло слияние, значит массив не отсортирован
            sorted = false;

            // Визуализация текущего состояния массива после разбиения на серии
            cout << "После разбиения на серии: ";
            for (int m = 0; m < size; m++) 
            {
                cout << setw(4) << arr[m];
            }
            cout << endl;

            // Устанавливаем начало следующей серии
            start1 = start2;
        }
    }
}

// Функция для вывода массива
void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << arr[i]; // Выравнивание для лучшего отображения
    cout << endl;
}

// Главная функция
int main() 
{
    setlocale(LC_ALL, "RU");
    const int SIZE = 10; // Размер массива
    int arr[SIZE];

    cout << "Введите " << SIZE << " элементов массива: ";
    for (int i = 0; i < SIZE; i++) 
    {
        cin >> arr[i];
    }
    cout << "Исходный массив: ";
    printArray(arr, SIZE);

    naturalMergeSort(arr, SIZE);

    cout << "Отсортированный массив: ";
    printArray(arr, SIZE);

    return 0;
}