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

// Функция для слияния двух подмассивов
void merge(int arr[], int left, int mid, int right) 
{
    int n1 = mid - left + 1; // Размер первого подмассива
    int n2 = right - mid;    // Размер второго подмассива

    // Временные массивы
    int L[50], R[50];

    // Копируем данные во временные массивы L[] и R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Слияние временных массивов обратно в arr[left..right]
    int i = 0; // Начальный индекс первого подмассива
    int j = 0; // Начальный индекс второго подмассива
    int k = left; // Начальный индекс слияния

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
        cout << "После слияния: ";
        printArray(arr, right + 1);
        k++;
    }

    // Копируем оставшиеся элементы L[], если есть
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
        cout << "После добавления оставшихся из L: ";
        printArray(arr, right + 1);
    }

    // Копируем оставшиеся элементы R[], если есть
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
        cout << "После добавления оставшихся из R: ";
        printArray(arr, right + 1);
    }
}

// Функция сортировки слиянием
void mergeSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        // Рекурсивная сортировка первой и второй половины
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Слияние отсортированных половин
        merge(arr, left, mid, right);
    }
}

int main() 
{
    setlocale(LC_ALL, "RU");
    const int MAX_SIZE = 100; // Максимальный размер массива
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

    mergeSort(arr, 0, n - 1);

    cout << "Отсортированный массив: ";
    printArray(arr, n);

    return 0;
}
