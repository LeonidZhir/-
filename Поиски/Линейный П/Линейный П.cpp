#include <iostream>
using namespace std;
// Функция для линейного поиска
int linearSearch(int arr[], int size, int target) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == target) 
        {
            return i; // Возвращаем индекс найденного элемента
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

    cout << "Введите значение для поиска: ";
    cin >> target;

    int result = linearSearch(arr, n, target);

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