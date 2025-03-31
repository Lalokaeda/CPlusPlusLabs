#include <iostream>
using namespace std;
void main(void)
{
	int a = 2, b = 5;
	void obmen1(int, int);
	void obmen2(int*, int*);
	void obmen3(int&, int&);
	cout << "До обмена: a=" << a << ", b=" << b << endl;
	obmen1(a, b);
	cout << "После обмена 1: a=" << a << ", b=" << b << endl;
	obmen2(&a, &b);
	cout << "После обмена 2: a=" << a << ", b=" << b << endl;
	obmen3(a, b);
	cout << "После обмена 3: a=" << a << ", b=" << b << endl;
}

//этот метод не может менять переменные местами, тк сюда передаются копии переменных
void obmen1(int x, int y)
{
	int z = x;
	x = y;
	y = z;
}

void obmen2(int* x, int* y)
{
	int z = *x;
	*x = *y;
	*y = z;
}

void obmen3(int& x, int& y)
{
	int z = x;
	x = y;
	y = z;
}