/*
19. Написать функцию f(A,B,C), вычисляющую и возвращающую для
чисел A и B их сумму, если С=1, и разность, если С отлично от 1.
Продемонстрировать работу функции для пяти вариантов параметров.
*/

#include <iostream>

using namespace std;

int f_ret(int, int, int);
void f_poi(int, int, int, int*);
void f_ref(int, int, int, int&);

int main()
{
	setlocale(LC_ALL, "ru");

	int a, b;
	cout << "Введите значения a, b: ";
	cin >> a >> b;

	int c;
	cout << "Выберите действие (1 - сумма, != 1 - разность): ";
	cin >> c;

	int n;
	cout << "Выберете способ (1 - return, 2 - указатель, 3 - ссылка): ";
	cin >> n;

	int* r = new int;
	int res;
	int& ref = res;

	switch (n)
	{
	case 1:
		cout << f_ret(a, b, c);
		break;
	case 2:
		f_poi(a, b, c, r);
		cout << *r << endl;
		break;
	case 3:
		f_ref(a, b, c, ref);
		cout << res;
		break;
	default:
		cerr << "Ошибка! Недопустимое значение\n";
		return 1;
	}
	delete r;
}

int f_ret(int a, int b, int c)
{
	if (c == 1)
	{
		return a + b;
	}
	return a - b;
}

void f_poi(int a, int b, int c, int* r)
{
	if (c == 1)
	{
		*r = a + b;
		return;
	}
	*r = a - b;
}

void f_ref(int a, int b, int c, int& ref)
{
	if (c == 1)
	{
		ref = a + b;
		return;
	}
	ref = a - b;
}