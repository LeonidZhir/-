#include <iostream>
using namespace std;

// Функция сортировки вставками
void insertionSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;

        // Перемещаем элементы, которые больше ключа, на одну позицию вперед
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Функция интерполяционного поиска
int interpolationSearch(int arr[], int size, int target) 
{
    int low = 0;
    int high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) 
    {
        // Вычисляем позицию для поиска
        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (target - arr[low]));

        // Проверяем, найден ли элемент
        if (arr[pos] == target) 
        {
            return pos; // Возвращаем индекс найденного элемента
        }

        // Если элемент больше, ищем в правой части
        if (arr[pos] < target) 
        {
            low = pos + 1;
        }
        else 
        { // Иначе ищем в левой части
            high = pos - 1;
        }
    }
    return -1; // Возвращаем -1, если элемент не найден
}

int main() 
{
    setlocale(LC_ALL, "RU");
    const int MAX_SIZE = 50; // Максимальный размер массива
    int arr[MAX_SIZE];
    int n, target;
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
    // Сортируем массив перед интерполяционным поиском
    insertionSort(arr, n);
    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Введите значение для поиска: ";
    cin >> target;
    int result = interpolationSearch(arr, n, target);
    if (result != -1) 
    {
        cout << "Элемент " << target << " найден на индексе " << result << "." << endl;
    }
    else 
    {
        cout << "Элемент " << target << " не найден в массиве." << endl;
    }
    return 0;
}