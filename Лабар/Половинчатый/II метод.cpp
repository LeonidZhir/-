#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

double f(double xn) //Функция нелинейного уравнения
{
	return (xn - (1 / (3 + sin(3.6 * xn))));
}
double dichotomy(double a, double b)
{
	double xn;
	double xip = 0;
	double eps = pow(10, -6); //Точность решения
	bool rule = true;
    while (rule)
    {
        xn = (a + b) / 2;
        if (abs(xn - xip) <= eps) //Проверка промежуточного значения корня
        {
           rule = false; //Завершаем цикл половинчатого деления
        }
        if (f(xn) * f(a) < 0) //Проверка на какой половине есть корень
        {
            b = xn;
        }
        else
        {
            a = xn;
            xip = xn;
            cout << "Промежуточное значение = " << xip << endl; //Вывод промежуточного значения
        }
    }
    return xn;
}
int main()
{
    setlocale(LC_ALL, "RUS");
    double answer;
    double a = 0;
    double b = 0.85;
    answer = dichotomy(a, b);
    cout << "Корень уравнения = " << answer;
    return 0;
}