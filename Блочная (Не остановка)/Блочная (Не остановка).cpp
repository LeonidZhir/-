#include <iostream>
#include <algorithm> // Для std::sort
using namespace std;

const int MAX_BLOCKS = 10;       // Максимальное количество блоков
const int MAX_ELEMENTS = 10;      // Максимальное количество элементов в блоке

// Структура для представления блока
struct Block
{
    int elements[MAX_ELEMENTS];    // Элементы блока
    int size;                      // Количество элементов в блоке
    int priority;                  // Приоритет блока (разряд числа)
};

// Функция для сравнения блоков по приоритету
bool compareBlocks(const Block& a, const Block& b)
{
    return a.priority < b.priority; // Меньший приоритет - выше
}

// Функция для блочной сортировки
void blockSort(Block blocks[], int blockCount, int sortedArray[], int& sortedIndex)
{
    // Сортируем блоки по приоритету
    sort(blocks, blocks + blockCount, compareBlocks);

    // Сортируем элементы в каждом блоке и объединяем в sortedArray
    for (int i = 0; i < blockCount; ++i)
    {
        sort(blocks[i].elements, blocks[i].elements + blocks[i].size);
        // Выводим отсортированный блок
        cout << "Отсортированный блок " << (i + 1) << " (Приоритет: " << blocks[i].priority << "): ";
        for (int j = 0; j < blocks[i].size; ++j)
        {
            cout << blocks[i].elements[j] << " ";
            sortedArray[sortedIndex++] = blocks[i].elements[j]; // Добавляем в объединённый массив
        }
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    int originalArray[MAX_BLOCKS * MAX_ELEMENTS];
    int arraySize;

    cout << "Введите количество элементов в массиве (максимум " << MAX_BLOCKS * MAX_ELEMENTS << "): ";
    cin >> arraySize;

    // Проверка на допустимое количество элементов
    if (arraySize <= 0 || arraySize > MAX_BLOCKS * MAX_ELEMENTS)
    {
        cout << "Превышено максимальное количество элементов." << endl;
        return 1;
    }

    // Вводим элементы в массив
    cout << "Введите элементы массива: ";
    for (int i = 0; i < arraySize; ++i)
    {
        cin >> originalArray[i];
    }

    Block blocks[MAX_BLOCKS];
    int blockCount = 0;

    // Заполняем блоки по разрядам
    for (int i = 0; i < arraySize; ++i)
    {
        int num = originalArray[i];
        int digitPlace = 1;

        // Определяем разряд числа
        while (num >= 10)
        {
            num /= 10;
            digitPlace++;
        }

        // Проверяем, существует ли блок с данным разрядом
        bool blockFound = false;
        for (int j = 0; j < blockCount; ++j)
        {
            if (blocks[j].priority == digitPlace)
            {
                if (blocks[j].size < MAX_ELEMENTS) // Проверяем, не превышаем ли максимальный размер блока
                {
                    blocks[j].elements[blocks[j].size++] = originalArray[i];
                }
                blockFound = true;
                break;
            }
        }

        // Если блок не найден, создаем новый
        if (!blockFound && blockCount < MAX_BLOCKS)
        {
            blocks[blockCount].priority = digitPlace; // Устанавливаем приоритет по разряду
            blocks[blockCount].size = 0; // Инициализируем размер блока
            blocks[blockCount].elements[blocks[blockCount].size++] = originalArray[i]; // Добавляем элемент
            blockCount++; // Увеличиваем количество блоков
        }
    }

    // Массив для хранения отсортированных элементов
    int sortedArray[MAX_BLOCKS * MAX_ELEMENTS];
    int sortedIndex = 0;

    // Вызываем функцию сортировки
    blockSort(blocks, blockCount, sortedArray, sortedIndex);

    // Выводим окончательный отсортированный массив
    cout << "Окончательный отсортированный массив: ";
    for (int i = 0; i < sortedIndex; ++i)
    {
        cout << sortedArray[i] << " ";
    }
    cout << endl;

    return 0;
}
