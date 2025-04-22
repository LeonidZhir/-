#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функция для проверки, содержит ли строка цифры
bool containsDigit(const string& line) 
{
    for (char ch : line) 
    {
        // Проверяем, является ли символ цифрой
        if (ch >= '0' && ch <= '9') 
        {
            return true;
        }
    }
    return false;
}

// Функция для копирования строк из F1 в F2 без цифр
void copyWithoutDigits(const string& inputFilename, const string& outputFilename) 
{
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    system("cls");
    ifstream inputFile(inputFilename);
    ofstream outputFile(outputFilename);

    if (!inputFile.is_open() || !outputFile.is_open()) 
    {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) 
    {
        if (!containsDigit(line)) 
        {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();
}

// Функция для подсчета строк, начинающихся на букву «А»
int countLinesStartingWithA(const std::string& fileName) 
{
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    system("cls");
    std::ifstream file(fileName);

    // Проверка на успешное открытие файла
    if (!file.is_open()) 
    {
        std::cerr << "Ошибка: файл '" << fileName << "' не найден." << std::endl;
        return -1; // Возвращаем -1 в случае ошибки
    }

    std::string line;
    int count = 0;

    // Читаем файл построчно
    while (std::getline(file, line)) 
    {
        // Удаляем пробелы в начале строки
        size_t firstCharIndex = line.find_first_not_of(" \t");
        if (firstCharIndex != std::string::npos) 
        {
            // Проверяем, начинается ли строка с 'А' или 'а'
            if (line[firstCharIndex] == 'А' || line[firstCharIndex] == 'а') 
            {
                count++;
            }
        }
    }

    file.close(); // Закрываем файл
    return count; // Возвращаем количество строк
}

int main() 
{
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    system("cls");
    string inputFilename = "F1.txt";  // Имя входного файла
    string outputFilename = "F2.txt";  // Имя выходного файла

    // Копируем строки из F1 в F2, исключая строки с цифрами
    copyWithoutDigits(inputFilename, outputFilename);

    // Подсчитываем количество строк, начинающихся на букву «А» в F2
    countLinesStartingWithA(outputFilename);
    int countA = countLinesStartingWithA(outputFilename);

    cout << "Количество строк, начинающихся на букву 'А' в файле F2: " << countA << endl;

    return 0;
}
