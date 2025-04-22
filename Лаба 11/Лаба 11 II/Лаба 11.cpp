#include <iostream>
#include <fstream>

using namespace std;

// Структура для узла двунаправленного списка
struct Node 
{
    int key;         // Ключевое поле
    Node* next;     // Указатель на следующий узел
    Node* prev;     // Указатель на предыдущий узел

    Node(int k) : key(k), next(nullptr), prev(nullptr) {} // Конструктор
};

// Класс для двунаправленного списка
class DoublyLinkedList 
{
private:
    Node* head;     // Указатель на голову списка
    Node* tail;     // Указатель на хвост списка

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {} // Конструктор

    // Функция для добавления элемента в начало списка
    void addToFront(int k) 
    {
        Node* newNode = new Node(k);
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
        if (!outFile) 
        {
            cerr << "Ошибка открытия файла для записи." << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) 
        {
            outFile << current->key << endl;
            current = current->next;
        }
        outFile.close();
    }

    // Функция для уничтожения списка
    void destroyList() 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr; // Обнуляем указатели
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
        destroyList(); // Уничтожаем текущий список
        int value;
        while (inFile >> value) 
        {
            addToFront(value); // Добавляем элементы в начало списка
        }
        inFile.close();
    }

    // Деструктор для освобождения памяти
    ~DoublyLinkedList() 
    {
        destroyList();
    }
};

int main()
{
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    system("cls");
    DoublyLinkedList list;

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

    // Печать финального списка
    cout << "Финальный список: ";
    list.printList();
    return 0;
}
