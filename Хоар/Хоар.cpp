#include <iostream>

using namespace std;

// Функция для обмена двух элементов
void swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

// Функция для визуализации массива
void printArray(int arr[], int size, int low, int high) 
{
    for (int i = 0; i < size; i++) 
    {
        if (i == low) 
        {
            cout << "[" << arr[i] << "] "; // Отметка "low"
        }
        else if (i == high) 
        {
            cout << "[" << arr[i] << "] "; // Отметка "high"
        }
        else 
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

// Функция быстрой сортировки
void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        // Выбор опорного элемента как среднего
        int mid = low + (high - low) / 2;
        int pivot = arr[mid];

        // Установка стенок
        int i = low;
        int j = high;

        cout << "Опорный элемент: " << pivot << endl;
        printArray(arr, high + 1, low, high);

        while (i <= j) 
        {
            // Найти элемент, который больше или равен опорному
            while (arr[i] < pivot) 
            {
                i++;
            }
            // Найти элемент, который меньше или равен опорному
            while (arr[j] > pivot) 
            {
                j--;
            }
            // Обмен элементов и сдвиг стенок
            if (i <= j) 
            {
                swap(arr[i], arr[j]);
                cout << "Обмен: " << arr[i] << " и " << arr[j] << endl;
                printArray(arr, high + 1, low, high);
                i++;
                j--;
            }
        }

        // Рекурсивная сортировка подмассивов
        if (low < j) 
        {
            quickSort(arr, low, j);
        }
        if (i < high) 
        {
            quickSort(arr, i, high);
        }
    }
}

// Функция для печати итогового массива
void printFinalArray(int arr[], int size) 
{
    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    printFinalArray(arr, n);

    quickSort(arr, 0, n - 1);

    printFinalArray(arr, n);

    return 0;
}
