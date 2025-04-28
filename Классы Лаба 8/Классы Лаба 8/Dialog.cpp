#include "Dialog.h"
#include <iostream>

void Dialog::run() 
{
    std::string command;

    while (true) 
    {
        std::cout << "������� ������� (m, +, -, s, z, q): ";
        std::cin >> command;

        if (command == "m") 
        {
            int count;
            std::cout << "������� ���������� ��������� ������: ";
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
            std::cout << "��������� ������� ����� �� ������." << std::endl;
        }
        else if (command == "s") 
        {
            std::cout << "���������� �� ��������� ������:" << std::endl;
            group.display();
        }
        else if (command == "z") 
        {
            double avgAge = group.averageAge();
            std::cout << "������� �������: " << avgAge << std::endl;
        }
        else if (command == "q") 
        {
            std::cout << "���������� ������." << std::endl;
            break;
        }
        else 
        {
            std::cout << "����������� �������. ����������, ���������� �����." << std::endl;
        }
    }
}