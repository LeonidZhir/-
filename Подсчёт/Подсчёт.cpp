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

// Функция сортировки подсчётом
void countingSort(int arr[], int n) 
{
    // Находим максимальное и минимальное значения в массиве
    int maxVal = arr[0], minVal = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > maxVal) 
        {
            maxVal = arr[i];
        }
        if (arr[i] < minVal) 
        {
            minVal = arr[i];
        }
    }

    // Вычисляем диапазон значений
    int range = maxVal - minVal + 1;

    // Создаем массив для подсчета частоты
    int* count = new int[range](); // Инициализируем массив нулями

    // Подсчитываем количество вхождений каждого элемента
    for (int i = 0; i < n; i++) 
    {
        count[arr[i] - minVal]++;
    }

    cout << "Массив частот: ";
    printArray(count, range); // Печатаем массив частот

    // Перезаписываем исходный массив на основе массива частот
    int index = 0;
    for (int i = 0; i < range; i++) 
    {
        while (count[i] > 0) 
        {
            arr[index++] = i + minVal;
            count[i]--;
            cout << "После добавления элемента " << (i + minVal) << ": ";
            printArray(arr, n);
        }
    }

    delete[] count; // Освобождаем память
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

    cout << "Введите элементы массива (можно использовать отрицательные числа): ";
    for (int i = 0; i < n; ++i) 
    {
        cin >> arr[i];
    }

    cout << "Исходный массив: ";
    printArray(arr, n);

    countingSort(arr, n);

    cout << "Отсортированный массив: ";
    printArray(arr, n);

    return 0;
}
