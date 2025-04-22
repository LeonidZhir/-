#include <iostream>
#include <string>
using namespace std;

class HashTable 
{
private:
    static const int size = 5; // Размер хэш-таблицы
    pair<int, string> table[size]; // Массив пар (цена, название продукта)
    bool occupied[size]; // Массив для отслеживания занятости индексов

    // Хэш-функция
    int hashFunction(int key) 
    {
        return key % size; // Простая хэш-функция
    }

public:
    HashTable() 
    {
        // Инициализация массива занятости
        for (int i = 0; i < size; ++i) 
        {
            occupied[i] = false;
        }
    }

    // Вставка элемента в хэш-таблицу
    void insert(int price, const string& product) 
    {
        int index = hashFunction(price);

        // Проверка на наличие свободного места
        while (occupied[index]) 
        {
            cout << "Коллизия при вставке: " << product << " с ценой " << price << " в индекс " << index << endl;
            index = (index + 1) % size; // Переход к следующему индексу
        }

        table[index] = make_pair(price, product); // Добавляем элемент в соответствующий индекс
        occupied[index] = true; // Отмечаем индекс как занятый
        cout << "Вставка: " << product << " с ценой " << price << " в индекс " << index << endl;
    }

    // Отображение хэш-таблицы
    void display() 
    {
        for (int i = 0; i < size; ++i) 
        {
            cout << "Индекс " << i << ": ";
            if (occupied[i]) 
            {
                cout << "(" << table[i].first << ", '" << table[i].second << "') ";
            }
            else 
            {
                cout << "Пусто ";
            }
            cout << endl;
        }
    }
};
int main() 
{
    HashTable hashTable;
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    system("cls");
    int price;
    string product;
    // Ввод данных пользователем
    for (int i = 0; i < 5; ++i) 
    { // Даем возможность ввести 5 элементов
        cout << "Введите цену продукта: ";
        cin >> price;
        cout << "Введите название продукта: ";
        cin >> product;

        hashTable.insert(price, product);
    }
    // Отображение хэш-таблицы
    cout << "\nСодержимое хэш-таблицы:\n";
    hashTable.display();
    return 0;
}