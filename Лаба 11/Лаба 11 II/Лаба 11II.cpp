#include <iostream>
#include <fstream>

using namespace std;

// Структура для узла двунаправленного списка
struct Node
{
    int key;         // Ключевое поле
    Node* next;     // Указатель на следующий узел
    Node* prev;     // Указатель на предыдущий узел
};

// Структура для двунаправленного списка
struct DoublyLinkedList
{
    Node* head;     // Указатель на голову списка
    Node* tail;     // Указатель на хвост списка

    // Инициализация списка
    void init()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Функция для добавления элемента в начало списка
    void addToFront(int k)
    {
        Node* newNode = new Node; // Создаем новый узел
        newNode->key = k;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr)
        {
            head = tail = newNode; // Если список пуст
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Функция для удаления элемента после элемента с заданным номером
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
            Node* toDelete = current->next;
            current->next = toDelete->next; // Удаляем следующий узел

            if (toDelete->next != nullptr)
            {
                toDelete->next->prev = current; // Обновляем указатель на предыдущий узел
            }
            else
            {
                tail = current; // Если удаляем последний узел, обновляем хвост
            }

            delete toDelete; // Освобождаем память
        }
        else
        {
            cout << "Нет элемента для удаления после узла с номером " << position << endl;
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

    // Функция для записи списка в файл
    void writeToFile(const string& filename)
    {
        ofstream outFile(filename);
        if (!outFile) {
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
        tail = nullptr; // Обнуляем указатель на хвост
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

    DoublyLinkedList list;
    list.init(); // Инициализация списка

    // Создание списка и добавление элементов
    int n; // Количество элементов для добавления
    cout << "Введите количество элементов для добавления в список: ";
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int value;
        cout << "Введите элемент " << (i + 1) << ": ";
        cin >> value;
        list.addToFront(value); // Добавляем элементы в начало списка
    }

    // Печать исходного списка
    cout << "Исходный список: ";
    list.printList();

    // Удаление элемента после заданной позиции
    int position;
    cout << "Введите позицию узла для удаления следующего элемента: ";
    cin >> position;
    list.deleteAfter(position);
    cout << "Список после удаления: ";
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
        list.addToFront(value); // Добавляем элементы в начало списка
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

    return 0; // Завершение программы
}