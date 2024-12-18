#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
double f(double x)
{
	return 1 / (3 + sin(3.6 * x)); //Вспомогательная функция f(х)=х
}
double pf(double x)
{
	return -3.6 * cos(3.6 * x) / pow((3 + sin(3.6 * x)), 2); //Производная вспомогательной функция
}
int main()
{
	setlocale(LC_ALL, "RU");
	double a = 0;
	double b = 0.85;
	double x1 = 0;
	const double eps = pow(10, -6);
	if (abs(pf(a)) < 1) //Проверка на сходимость
	{
		double x0 = a;
		x1 = f(x0);
		while (abs(x0 - x1) >= eps) //Проверка на точность
		{
			cout << "Промежуточное значение = " << x1 << endl;
			x0 = x1;
			x1 = f(x0);
		}
	}
	else {
		cout << "Нет сходимости";
	}
	cout << "Корень уравнения = " << x1 << endl;
	return 0;
}