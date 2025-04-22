#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Определение структуры "Покупатель"
struct Покупатель 
{
    string фамилия;
    string имя;
    string отчество;
    string адрес;
    string телефон;
    string номерКредитнойКарточки;
};

// Функция для удаления первых трех покупателей из файла
void удалитьПокупателей(const string& filename) 
{
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    system("cls");
    ifstream inputFile(filename);
    ofstream tempFile("temp.txt");

    if (!inputFile.is_open() || !tempFile.is_open()) 
    {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    Покупатель покупатель;
    int count = 0;

    // Пропускаем первые три записи
    while (count < 3 && getline(inputFile, покупатель.фамилия)) 
    {
        getline(inputFile, покупатель.имя);
        getline(inputFile, покупатель.отчество);
        getline(inputFile, покупатель.адрес);
        getline(inputFile, покупатель.телефон);
        getline(inputFile, покупатель.номерКредитнойКарточки);
        count++;
    }

    // Копируем оставшиеся записи во временный файл
    while (getline(inputFile, покупатель.фамилия)) 
    {
        getline(inputFile, покупатель.имя);
        getline(inputFile, покупатель.отчество);
        getline(inputFile, покупатель.адрес);
        getline(inputFile, покупатель.телефон);
        getline(inputFile, покупатель.номерКредитнойКарточки);

        tempFile << покупатель.фамилия << endl;
        tempFile << покупатель.имя << endl;
        tempFile << покупатель.отчество << endl;
        tempFile << покупатель.адрес << endl;
        tempFile << покупатель.телефон << endl;
        tempFile << покупатель.номерКредитнойКарточки << endl;
    }

    inputFile.close();
    tempFile.close();

    // Заменяем оригинальный файл временным
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}

// Функция для добавления новых покупателей в конец файла
void добавитьПокупателей(const string& filename) 
{
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    system("cls");
    ofstream outputFile(filename, ios::app); // Открываем файл для добавления

    if (!outputFile.is_open()) 
    {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    for (int i = 0; i < 3; i++) 
    {
        Покупатель покупатель;
        cout << "Введите данные покупателя " << (i + 1) << ":" << endl;
        cout << "Фамилия: ";
        cin >> покупатель.фамилия;
        cout << "Имя: ";
        cin >> покупатель.имя;
        cout << "Отчество: ";
        cin >> покупатель.отчество;
        cout << "Адрес: ";
        cin >> покупатель.адрес;
        cout << "Телефон: ";
        cin >> покупатель.телефон;
        cout << "Номер кредитной карточки: ";
        cin >> покупатель.номерКредитнойКарточки;

        // Записываем данные в файл
        outputFile << покупатель.фамилия << endl;
        outputFile << покупатель.имя << endl;
        outputFile << покупатель.отчество << endl;
        outputFile << покупатель.адрес << endl;
        outputFile << покупатель.телефон << endl;
        outputFile << покупатель.номерКредитнойКарточки << endl;
    }

    outputFile.close();
}

int main() 
{
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    system("cls");
    string filename = "покупатели.txt"; // Имя файла

    // Удаляем первых 3 покупателя
    удалитьПокупателей(filename);

    // Добавляем 3 новых покупателя
    добавитьПокупателей(filename);

    cout << "Операции завершены." << endl;

    return 0;
}