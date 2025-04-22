#include <iostream>
#include <iomanip> // Для std::setw
using namespace std;

// Функция для слияния двух отсортированных массивов
void merge(int arr[], int left, int mid, int right) 
{
    int n1 = mid - left + 1; // Размер левой части
    int n2 = right - mid;    // Размер правой части

    // Временные массивы
    int* L = new int[n1];
    int* R = new int[n2];

    // Копируем данные во временные массивы
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Слияние временных массивов обратно в arr[left..right]
    int i = 0; // Индекс первого подмассива
    int j = 0; // Индекс второго подмассива
    int k = left; // Индекс слияния

    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы, если есть
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Освобождаем память временных массивов
    delete[] L;
    delete[] R;

    // Визуализируем текущий массив после слияния
    cout << "После слияния (от " << left << " до " << right << "): ";
    for (int m = left; m <= right; m++) 
    {
        cout << setw(4) << arr[m];
    }
    cout << endl;
}

// Рекурсивная функция сортировки слиянием
void mergeSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        // Находим середину
        int mid = left + (right - left) / 2;

        // Рекурсивно сортируем первую и вторую половины
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Сливаем отсортированные половины
        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, SIZE - 1);

    cout << "Отсортированный массив: ";
    printArray(arr, SIZE);

    return 0;
}