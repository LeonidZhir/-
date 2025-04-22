#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Максимальный размер массива
const int MAX_SIZE = 100;

// Функция для разбиения массива на "файлы"
int distributeSeries(int arr[], int size, int files[][MAX_SIZE]) 
{
    int fileCount = 0;
    int start = 0;

    while (start < size) 
    {
        int fileSize = 0;

        // Находим конец серии
        while (start + 1 < size && arr[start] <= arr[start + 1]) 
        {
            files[fileCount][fileSize++] = arr[start];
            start++;
        }
        files[fileCount][fileSize++] = arr[start]; // Добавляем последний элемент серии
        fileCount++;
        start++;
    }

    return fileCount; // Возвращаем количество файлов
}

// Функция для слияния двух подмассивов
int merge(int left[], int leftSize, int right[], int rightSize, int result[]) 
{
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) 
    {
        if (left[i] <= right[j]) 
        {
            result[k++] = left[i++];
        }
        else 
        {
            result[k++] = right[j++];
        }
    }

    // Копируем оставшиеся элементы
    while (i < leftSize) 
    {
        result[k++] = left[i++];
    }
    while (j < rightSize) 
    {
        result[k++] = right[j++];
    }

    return k; // Возвращаем размер объединенного массива
}

// Функция для многофазного слияния
void multiPhaseMerge(int files[][MAX_SIZE], int fileCount, int& sortedSize, int sortedArray[]) 
{
    while (fileCount > 1) 
    {
        int newFileCount = 0;

        for (int i = 0; i < fileCount; i += 2) 
        {
            if (i + 1 < fileCount) 
            {
                // Два файла для слияния
                int left[MAX_SIZE], right[MAX_SIZE];
                int leftSize = 0, rightSize = 0;

                // Заполняем левый файл
                while (files[i][leftSize] != 0) 
                {
                    left[leftSize++] = files[i][leftSize];
                }

                // Заполняем правый файл
                while (files[i + 1][rightSize] != 0) 
                {
                    right[rightSize++] = files[i + 1][rightSize];
                }

                // Слияние
                int merged[MAX_SIZE];
                int mergedSize = merge(left, leftSize, right, rightSize, merged);

                // Сохраняем результат в новом "файле"
                for (int j = 0; j < mergedSize; j++) 
                {
                    files[newFileCount][j] = merged[j];
                }
                files[newFileCount][mergedSize] = 0; // Завершаем файл нулем
                newFileCount++;

                // Визуализация текущего состояния слияния
                cout << "Слияние файлов " << i + 1 << " и " << i + 2 << ": ";
                for (int j = 0; j < mergedSize; j++) 
                {
                    cout << merged[j] << " ";
                }
                cout << endl;
            }
            else 
            {
                // Если нечётное количество файлов, добавляем последний без слияния
                for (int j = 0; files[i][j] != 0; j++) 
                {
                    files[newFileCount][j] = files[i][j];
                }
                files[newFileCount][0] = 0; // Завершаем файл нулем
                newFileCount++;
            }
        }

        fileCount = newFileCount; // Обновляем количество файлов
    }

    // Сохраняем окончательный отсортированный массив
    sortedSize = 0;
    while (files[0][sortedSize] != 0)
    {
        sortedArray[sortedSize] = files[0][sortedSize];
        sortedSize++;
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    cout << "Введите количество элементов массива (максимум " << MAX_SIZE << "): ";
    int size;
    cin >> size;

    if (size <= 0 || size > MAX_SIZE) 
    {
        cout << "Некорректный размер массива!" << endl;
        return 1;
    }

    int arr[MAX_SIZE];
    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < size; i++) 
    {
        cin >> arr[i];
    }

    // Массив для хранения "файлов"
    int files[MAX_SIZE][MAX_SIZE] = { 0 };

    // Разбиение массива на "файлы"
    int fileCount = distributeSeries(arr, size, files);

    // Массив для хранения отсортированного результата
    int sortedArray[MAX_SIZE] = { 0 };
    int sortedSize = 0;

    // Сортировка методом многофазного слияния
    multiPhaseMerge(files, fileCount, sortedSize, sortedArray);

    // Вывод окончательного отсортированного массива
    cout << "Отсортированный массив: ";
    for (int i = 0; i < sortedSize; i++) 
    {
        cout << sortedArray[i] << " ";
    }
    cout << endl;

    return 0;
}