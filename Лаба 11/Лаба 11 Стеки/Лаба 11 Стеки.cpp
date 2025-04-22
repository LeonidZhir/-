#include <iostream>
#include <fstream> // Для работы с файлами
using namespace std;

// Структура для узла стека
struct Node
{
    int key;         // Ключевое поле
    Node* next;     // Указатель на следующий узел
};

// Структура для стека на основе односвязного списка
struct Stack
{
    Node* top;      // Указатель на верхний элемент стека

    // Функция для инициализации стека
    void init()
    {
        top = nullptr; // Устанавливаем верхний элемент в nullptr
    }

    // Функция для добавления элемента на верх стека
    void push(int k)
    {
        Node* newNode = new Node; // Создаем новый узел
        newNode->key = k; // Устанавливаем значение
        newNode->next = top; // Новый узел указывает на текущий верхний элемент
        top = newNode; // Обновляем верхний элемент
    }

    // Функция для удаления элемента после узла с заданным номером
    void deleteAfter(int position)
    {
        Node* current = top;
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

    // Функция для добавления K элементов в стек
    void addMultipleToFront(int K)
    {
        for (int i = 0; i < K; ++i)
        {
            int value;
            cout << "Введите элемент " << (i + 1) << ": ";
            cin >> value;
            push(value); // Добавляем элемент на верх стека
        }
    }

    // Функция для печати стека
    void printStack()
    {
        if (top == nullptr)
        {
            cout << "Стек пустой." << endl;
            return;
        }
        Node* current = top;
        while (current != nullptr)
        {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Функция для очистки стека
    void clear()
    {
        while (top != nullptr)
        {
            Node* temp = top;
            top = top->next;
            delete temp; // Освобождение памяти
        }
        cout << "Стек очищен." << endl;
    }

    // Функция для сохранения стека в файл
    void saveToFile(const string& filename)
    {
        ofstream outFile(filename);
        if (!outFile)
        {
            cerr << "Ошибка открытия файла для записи." << endl;
            return;
        }
        Node* current = top;
        while (current != nullptr)
        {
            outFile << current->key << endl; // Записываем каждый элемент в файл
            current = current->next;
        }
        outFile.close();
        cout << "Стек сохранен в файл " << filename << "." << endl;
    }

    // Функция для восстановления стека из файла
    void loadFromFile(const string& filename)
    {
        ifstream inFile(filename);
        if (!inFile)
        {
            cerr << "Ошибка открытия файла для чтения." << endl;
            return;
        }
        clear(); // Очищаем текущий стек перед загрузкой
        int value;
        while (inFile >> value) // Читаем значения из файла
        {
            push(value); // Добавляем элементы в стек
        }
        inFile.close();
        cout << "Стек восстановлен из файла " << filename << "." << endl;
    }
};

int main()
{
    Stack stack;
    stack.init(); // Инициализация стека
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    system("cls");

    // Заполнение стека
    int n;
    cout << "Введите количество элементов для добавления в стек: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int value;
        cout << "Введите элемент " << (i + 1) << ": ";
        cin >> value;
        stack.push(value);
    }

    // Печать стека
    cout << "Текущий стек: ";
    stack.printStack();

    // Удаление элемента после заданного номера
    int position;
    cout << "Введите номер узла для удаления элемента после него: ";
    cin >> position;
    stack.deleteAfter(position);

    // Печать стека после удаления
    cout << "Стек после удаления элемента: ";
    stack.printStack();

    // Добавление K элементов в начало стека
    int K;
    cout << "Введите количество элементов для добавления в стек: ";
    cin >> K;
    stack.addMultipleToFront(K);

    // Печать стека после добавления
    cout << "Стек после добавления элементов: ";
    stack.printStack();

    // Запись стека в файл
    string filename;
    cout << "Введите имя файла для записи стека: ";
    cin >> filename;
    stack.saveToFile(filename);

    // Очистка стека
    stack.clear();

    // Печать стека после очистки
    cout << "Стек после очистки: ";
    stack.printStack();

    // Восстановление стека из файла
    cout << "Введите имя файла для восстановления стека: ";
    cin >> filename;
    stack.loadFromFile(filename);

    // Печать восстановленного стека
    cout << "Восстановленный стек: ";
    stack.printStack();

    // Очистка стека перед завершением программы
    stack.clear();

    return 0;
}