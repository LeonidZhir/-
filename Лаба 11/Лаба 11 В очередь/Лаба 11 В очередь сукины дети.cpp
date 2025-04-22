#include <iostream>
#include <fstream> // Для работы с файлами

using namespace std;

// Структура для узла очереди
struct Node
{
    int key;         // Ключевое поле
    Node* next;     // Указатель на следующий узел

    Node(int k) : key(k), next(nullptr) {} // Конструктор
};

// Структура для очереди на основе односвязного списка
struct Queue
{
    Node* front;     // Указатель на первый элемент очереди
    Node* rear;      // Указатель на последний элемент очереди

    Queue() : front(nullptr), rear(nullptr) {} // Конструктор

    // Функция для добавления элемента в конец очереди
    void enqueue(int k)
    {
        Node* newNode = new Node(k);
        if (rear)
        {
            rear->next = newNode; // Указываем, что следующий элемент - новый узел
        }
        else
        {
            front = newNode; // Если очередь была пустой, новый узел - это и front, и rear
        }
        rear = newNode; // Обновляем rear
    }

    // Функция для удаления элемента после узла с заданным номером
    void deleteAfter(int position)
    {
        Node* current = front;
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
            if (toDelete == rear)
            { // Если удаляем последний элемент
                rear = current; // Обновляем rear
            }
            delete toDelete; // Освобождаем память
            cout << "Элемент после узла с номером " << position << " удален." << endl;
        }
        else
        {
            cout << "Нет элемента для удаления после узла с номером " << position << endl;
        }
    }

    // Функция для добавления K элементов в начало очереди
    void addMultipleToFront(int K)
    {
        for (int i = 0; i < K; ++i)
        {
            int value;
            cout << "Введите элемент " << (i + 1) << ": ";
            cin >> value;
            Node* newNode = new Node(value);
            newNode->next = front; // Новый узел указывает на текущий front
            front = newNode;       // Обновляем front
            if (rear == nullptr) { // Если очередь была пустой, обновляем rear
                rear = newNode;
            }
        }
    }

    // Функция для печати очереди
    void printQueue()
    {
        if (front == nullptr)
        {
            cout << "Очередь пустая." << endl;
            return;
        }
        Node* current = front;
        while (current != nullptr)
        {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Функция для сохранения очереди в файл
    void saveToFile(const string& filename)
    {
        ofstream outFile(filename);
        if (!outFile)
        {
            cout << "Ошибка открытия файла для записи." << endl;
            return;
        }
        Node* current = front;
        while (current != nullptr)
        {
            outFile << current->key << endl; // Сохраняем каждый элемент в файл
            current = current->next;
        }
        outFile.close();
        cout << "Очередь успешно сохранена в файл " << filename << "." << endl;
    }

    // Функция для удаления очереди
    void clear()
    {
        while (front != nullptr)
        {
            Node* temp = front;
            front = front->next;
            delete temp; // Освобождение памяти
        }
        rear = nullptr; // Обновляем rear
        cout << "Очередь успешно удалена." << endl;
    }

    // Функция для восстановления очереди из файла
    void restoreFromFile(const string& filename)
    {
        ifstream inFile(filename);
        if (!inFile)
        {
            cout << "Ошибка открытия файла для чтения." << endl;
            return;
        }
        clear(); // Сначала очищаем очередь, чтобы избежать дублирования

        int value;
        while (inFile >> value)
        {
            enqueue(value); // Добавляем элементы в очередь
        }
        inFile.close();
        cout << "Очередь успешно восстановлена из файла " << filename << "." << endl;
    }
};

int main()
{
    Queue queue;
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    system("cls");

    // Заполнение очереди
    int n;
    cout << "Введите количество элементов для добавления в очередь: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int value;
        cout << "Введите элемент " << (i + 1) << ": ";
        cin >> value;
        queue.enqueue(value);
    }

    // Печать очереди
    cout << "Текущая очередь: ";
    queue.printQueue();

    // Удаление элемента после заданного номера
    int position;
    cout << "Введите номер узла для удаления элемента после него: ";
    cin >> position;
    queue.deleteAfter(position);

    // Печать очереди после удаления
    cout << "Очередь после удаления элемента: ";
    queue.printQueue();

    // Добавление K элементов в начало очереди
    int K;
    cout << "Введите количество элементов для добавления в начало очереди: ";
    cin >> K;
    queue.addMultipleToFront(K);

    // Печать очереди после добавления
    cout << "Очередь после добавления элементов в начало: ";
    queue.printQueue();

    // Сохранение очереди в файл
    string filename = "F5.txt";
    queue.saveToFile(filename);

    // Очистка очереди
    queue.clear();
    // Печать очереди после очистки
    cout << "Очередь после очистки элементов: ";
    queue.printQueue();

    // Восстановление очереди из файла
    queue.restoreFromFile(filename);

    // Печать восстановленной очереди
    cout << "Восстановленная очередь: ";
    queue.printQueue();

    return 0; // Завершение программы
}