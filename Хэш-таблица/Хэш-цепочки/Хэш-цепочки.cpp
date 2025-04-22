#include <iostream>
#include <list>
#include <string>
using namespace std;

class HashTable 
{
private:
    static const int size = 5; // Размер хэш-таблицы
    list<pair<int, string>> table[size]; // Массив списков для цепочек

    // Хэш-функция
    int hashFunction(int key) 
    {
        return key % size; // Простая хэш-функция
    }

public:
    // Вставка элемента в хэш-таблицу
    void insert(int price, const string& product) 
    {
        int index = hashFunction(price);

        // Добавляем элемент в соответствующий индекс (цепочку)
        table[index].emplace_back(price, product);
        cout << "Вставка: " << product << " с ценой " << price << " в индекс " << index << endl;
    }

    // Отображение хэш-таблицы
    void display() 
    {
        for (int i = 0; i < size; ++i) 
        {
            cout << "Индекс " << i << ": ";
            for (const auto& item : table[i]) 
            {
                cout << "(" << item.first << ", '" << item.second << "') ";
            }
            if (table[i].empty()) 
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
    for (int i = 0; i < 5; ++i) { // Даем возможность ввести 5 элементов
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