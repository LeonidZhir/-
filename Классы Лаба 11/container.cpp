#include "container.h"
#include <cstdlib> // ��� rand()

void fillContainer(std::vector<double>& container, int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        container.push_back(static_cast<double>(rand() % 100)); // ���������� ���������� �������
    }
}