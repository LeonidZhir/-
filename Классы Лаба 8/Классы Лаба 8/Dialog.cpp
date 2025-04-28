#include "Dialog.h"
#include <iostream>

void Dialog::run() 
{
    std::string command;

    while (true) 
    {
        std::cout << "Введите команду (m, +, -, s, z, q): ";
        std::cin >> command;

        if (command == "m") 
        {
            int count;
            std::cout << "Введите количество элементов группы: ";
            std::cin >> count;
            for (int i = 0; i < count; ++i) 
            {
                Abiturient* student = new Abiturient("", 0, 0, "");
                student->input();
                group.addStudent(student);
            }
        }
        else if (command == "+") 
        {
            Abiturient* student = new Abiturient("", 0, 0, "");
            student->input();
            group.addStudent(student);
        }
        else if (command == "-") 
        {
            group.removeStudent();
            std::cout << "Последний элемент удалён из группы." << std::endl;
        }
        else if (command == "s") 
        {
            std::cout << "Информация об элементах группы:" << std::endl;
            group.display();
        }
        else if (command == "z") 
        {
            double avgAge = group.averageAge();
            std::cout << "Средний возраст: " << avgAge << std::endl;
        }
        else if (command == "q") 
        {
            std::cout << "Завершение работы." << std::endl;
            break;
        }
        else 
        {
            std::cout << "Неизвестная команда. Пожалуйста, попробуйте снова." << std::endl;
        }
    }
}