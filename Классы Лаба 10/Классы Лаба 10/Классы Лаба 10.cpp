#include <iostream>
#include <vector>
#include "Money.h"
#include "file_operations.h"

void displayMenu()
{
    std::cout << "1. Добавить запись\n";
    std::cout << "2. Удалить записи\n";
    std::cout << "3. Увеличить записи\n";
    std::cout << "4. Смотреть записи\n";
    std::cout << "5. Выход\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<Money> records;
    int choice;

    while (true)
    {
        displayMenu();
        std::cin >> choice;

        // Проверка на корректность ввода
        if (std::cin.fail())
        {
            std::cin.clear(); // Сбрасываем состояние ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем неверный ввод
            std::cout << "Неверный ввод! Пожалуйста, введите число от 1 до 5.\n";
            continue; // Возвращаемся к началу цикла
        }

        switch (choice)
        {
        case 1:
        {
            long r;
            int k;
            std::cout << "Введите рубли и копейки: ";
            std::cin >> r >> k;
            records.emplace_back(r, k);
            saveToFile(records, "money.dat");
            break;
        }
        case 2:
        {
            Money k1, k2;
            long r1, r2;
            int k1c, k2c;
            std::cout << "Введите диапазон (рубли и копейки) для удаления:\n";
            std::cout << "К1: ";
            std::cin >> r1 >> k1c;
            k1 = Money(r1, k1c);
            std::cout << "К2: ";
            std::cin >> r2 >> k2c;
            k2 = Money(r2, k2c);
            removeRecords(records, k1, k2);
            saveToFile(records, "money.dat");
            break;
        }
        case 3:
        {
            doubleRecords(records);
            saveToFile(records, "money.dat");
            break;
        }
        case 4:
        {
            records = loadFromFile("money.dat");
            for (const auto& record : records)
            {
                record.display();
            }
            break;
        }
        case 5:
            return 0;
        default:
            std::cout << "Неверный выбор! Пожалуйста, попробуйте снова.\n";
        }
    }
}