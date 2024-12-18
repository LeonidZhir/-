#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;
int n;
double x, s;
double pow(double x, int n)
{
	if (n == 0) //условие выхода из рекурсии
		return 1;
	return (x * pow(x, n - 1));
}
double recursion(double x, int n)
{
	if (n == 0) //условие выхода из рекурсии
		return 0;
	return (pow(x, n)) * sin(n * 3.1415926535 / 4) + recursion(x, n - 1);
}
int main()
{
	setlocale(LC_ALL, "RU");
	cout << "Введите натуральное значение n и любое значение x через пробел ";
	cin >> n >> x;
	s = recursion(x, n - 1);
	cout << "S = " << s << endl;
	return 0;
}