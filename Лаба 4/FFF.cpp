#include <iostream>
#include <clocale>
#include <ctime>
#include <stdlib.h>
using namespace std;
int c = 0;
int value;
int N;
int l;
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите кол-во элементов массива: "<<endl;
	cin >> N;
	int* arr = new int[N] {};
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
	cout << "Введите значение: " << endl;
	cin >> value;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == value)
		{
			c++;
		}
	}
	l = N - c;
	int* newarr = new int[l];
	int c = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] != value)
		{
			newarr[c] = arr[i];
			c++;
		}
	}
	delete[]arr;
	int m = 0;
	for (int i = 0; i < l; i++)
	{
		if (newarr[i] % 2 == 0)
		{
			m++;
		}
	}
	c = l + m;
	int* arr1 = new int[c] {};
	m = 0;
	for (int i = 0; i < l; i++)
	{
		if (newarr[i] % 2 == 0)
		{
			arr1[m + 1] = newarr[i];
			m += 2;
		}
		if (newarr[i] % 2 != 0)
		{
			arr1[m] = newarr[i];
			m++;
		}
	}
	newarr = nullptr;
	for (int i = 0; i < c; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl << endl;
	return 0;
}