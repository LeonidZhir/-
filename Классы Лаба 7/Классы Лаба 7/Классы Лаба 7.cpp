#include "Set.h"
#include "Money.h"

int main() 
{
    // Тест для стандартных типов данных
    Set<int> intSet;
    intSet.add(1);
    intSet.add(2);
    intSet.add(4);
    intSet.print(); // Ожидается вывод: 1 2 4

    // Тест для пользовательского класса Money
    Set<Money> moneySet;
    Money m1(110, 70);
    Money m2(200, 55);
    moneySet.add(m1);
    moneySet.add(m2);
    moneySet.print(); 

    return 0;
}
