#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура для узла однонаправленного списка
struct Node
{
    int key;         // Ключевое поле
    Node* next;     // Указатель на следующий узел
};

// Структура для однонаправленного списка
struct SinglyLinkedList
{
    Node* head;     // Указатель на голову списка

    // Функция для инициализации списка
    void init()
    {
        head = nullptr; // Устанавливаем голову списка в nullptr
    }

    // Функция для создания списка и добавления элементов
    void createList(int n)
    {
        for (int i = 0; i < n; ++i)
        {
            int value;
            cout << "Введите элемент " << (i + 1) << ": ";
            cin >> value;
            addToFront(value); // Добавляем элементы в начало списка
        }
    }

    // Функция для печати списка
    void printList()
    {
        if (head == nullptr)
        {
            cout << "Список пустой." << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Функция для удаления элемента после узла с заданным номером
    void deleteAfter(int position)
    {
        Node* current = head;
        int index = 0;

        // Поиск узла с заданным номером
        while (current != nullptr && index < position)
        {
            current = current->next;
            index++;
        }

        // Если узел найден и у него есть следующий узел
        if (current != nullptr && current->next != nullptr)
        {
            Node* toDelete = current->next; // Узел для удаления
            current->next = toDelete->next; // Удаляем следующий узел
            delete toDelete; // Освобождаем память
            cout << "Элемент после узла с номером " << position << " удален." << endl;
        }
        else
        {
            cout << "Нет элемента для удаления после узла с номером " << position << endl;
        }
    }

    // Функция для добавления элемента в начало списка
    void addToFront(int k)
    {
        Node* newNode = new Node; // Создаем новый узел
        newNode->key = k; // Устанавливаем значение
        newNode->next = head; // Новый узел указывает на старую голову
        head = newNode; // Обновляем голову
    }

    // Функция для записи списка в файл
    void writeToFile(const string& filename)
    {
        ofstream outFile(filename);
        if (!outFile)
        {
            cerr << "Ошибка открытия файла для записи." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr)
        {
            outFile << current->key << endl; // Записываем каждый элемент в новую строку
            current = current->next;
        }

        outFile.close();
        cout << "Список успешно записан в файл: " << filename << endl;
    }

    // Функция для уничтожения списка
    void destroyList()
    {
        Node* current = head;
        while (current != nullptr)
        {
            Node* nextNode = current->next; // Сохраняем указатель на следующий узел
            delete current; // Освобождаем память текущего узла
            current = nextNode; // Переходим к следующему узлу
        }
        head = nullptr; // Обнуляем указатель на голову
    }

    // Функция для восстановления списка из файла
    void restoreFromFile(const string& filename)
    {
        ifstream inFile(filename);
        if (!inFile)
        {
            cerr << "Ошибка открытия файла для чтения." << endl;
            return;
        }

        int value;
        while (inFile >> value)
        {
            addToFront(value); // Добавляем элементы в начало списка
        }

        inFile.close();
        cout << "Список успешно восстановлен из файла: " << filename << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    system("cls");

    SinglyLinkedList list;
    list.init(); // Инициализация списка
    // Создание списка
    int L;
    cout << "Введите количество элементов для добавления в список: ";
    cin >> L;
    list.createList(L);

    // Печать начального списка
    cout << "Начальный список: ";
    list.printList();

    // Удаление элемента после заданного номера
    int position;
    cout << "Введите номер узла для удаления элемента после него: ";
    cin >> position;
    list.deleteAfter(position);

    // Печать списка после удаления
    cout << "Список после удаления элемента: ";
    list.printList();

    // Добавление K элементов в начало списка
    int K;
    cout << "Введите количество элементов для добавления в начало списка: ";
    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        int value;
        cout << "Введите элемент " << (i + 1) << ": ";
        cin >> value;
        list.addToFront(value);
    }

    // Печать списка после добавления
    cout << "Список после добавления элементов в начало: ";
    list.printList();

    // Запись списка в файл
    string filename;
    cout << "Введите имя файла для записи списка: ";
    cin >> filename;
    list.writeToFile(filename);

    // Уничтожение списка
    list.destroyList();
    cout << "Список уничтожен." << endl;

    // Попытка печати списка после уничтожения
    cout << "Список после уничтожения: ";
    list.printList();

    // Восстановление списка из файла
    cout << "Введите имя файла для восстановления списка: ";
    cin >> filename;
    list.restoreFromFile(filename);

    // Печать восстановленного списка
    cout << "Восстановленный список: ";
    list.printList();

    // Уничтожение списка перед завершением программы
    list.destroyList();
    cout << "Список уничтожен." << endl;

    return 0;
}