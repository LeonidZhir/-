#include <iostream>
#include <clocale>
#include <string>
using namespace std;
void Sorti(string &str)
{
	int k = 0;
	int l;
	for (int i = 1; i < (str.length()); ++i)
	{
		if (str[i] == '9')
		{
			l = str[k];
			str[k] = str[i];
			str[i] = l;
			k++;
		}
	}
	for (int i = 1; i < (str.length()); ++i)
	{
		if (str[i] == '8')
		{
			l = str[k];
			str[k] = str[i];
			str[i] = l;
			k++;
		}
	}
	for (int i = 1; i < (str.length()); ++i)
	{
		if (str[i] == '7')
		{
			l = str[k];
			str[k] = str[i];
			str[i] = l;
			k++;
		}
	}
	for (int i = 1; i < (str.length()); ++i)
	{
		if (str[i] == '6')
		{
			l = str[k];
			str[k] = str[i];
			str[i] = l;
			k++;
		}
	}
	for (int i = 1; i < (str.length()); ++i)
	{
		if (str[i] == '5')
		{
			l = str[k];
			str[k] = str[i];
			str[i] = l;
			k++;
		}
	}
	for (int i = 1; i < (str.length()); ++i)
	{
		if (str[i] == '4')
		{
			l = str[k];
			str[k] = str[i];
			str[i] = l;
			k++;
		}
	}
	for (int i = 1; i < (str.length()); ++i)
	{
		if (str[i] == '3')
		{
			l = str[k];
			str[k] = str[i];
			str[i] = l;
			k++;
		}
	}
	for (int i = 1; i < (str.length()); ++i)
	{
		if (str[i] == '2')
		{
			l = str[k];
			str[k] = str[i];
			str[i] = l;
			k++;
		}
	}
	for (int i = 1; i < (str.length()); ++i)
	{
		if (str[i] == '1')
		{
			l = str[k];
			str[k] = str[i];
			str[i] = l;
			k++;
		}
	}
	for (int i = 1; i < (str.length()); ++i)
	{
		if (str[i] == '0')
		{
			l = str[k];
			str[k] = str[i];
			str[i] = l;
			k++;
		}
	}
}
int main()
{
	setlocale(LC_ALL, "RU");
	system("chcp 1251");
	system("cls");
	string str;
	cout << "Введите строку: " << endl;
	cin >> str;
	cout << endl << endl;
	Sorti(str);
	cout << str;
	return 0;
}