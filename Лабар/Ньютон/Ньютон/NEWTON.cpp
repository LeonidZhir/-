#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
double f1(double xn)
{
	bool rule = true;
	double eps = pow(10, -6); //Точность вычисления
	double xip;
	while (rule) {
		xip = xn - (xn - (1 / (3 + sin(3.6 * xn)))) / (1 + (18 * cos((18 / 5) * xn)) / (5 * pow((3 - sin((18 / 5) * xn)), 2))); //Касательная к графику
		if (abs(xn - xip) <= eps) //Проверка промежуточного корня
		{
			rule = false; //Цикл завершается
		}
		else {
			xn = xip; //Присваиваем новое значение, чтобы найти следующее приблизительное значение корня
			cout << "Промежуточное значение = " << xn << endl; //Вывод промежуточного значения
		}
	}
	return xip;
}
int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Введите любой х, входящий в промежуток [0; 0.85]: ";
	double xn, answer;
	double a = 0;
	double b = 0.85;
	cin >> xn;
	if ((xn >= a) && (xn <= b)) { //Проверяем входит ли х в промежуток а и b
		answer = f1(xn);
		cout << "Ответ равен: " << answer << endl;
	}
	else {
		cout << "x не входит в промежуток [0; 0.85].";
	}
	return 0;
}