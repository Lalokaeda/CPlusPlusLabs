#include <iostream>
using namespace std;

void main(void) 
{
	int i, k;
	int num;
	int power(int, int);
	cin >> num;
	for (i = 0; i < 10; i++)
	{
		k = power(num, i);
		cout << "i=" << i << ", k=" << k << endl;
	}
}

int power(int x, int n)
{
	int i, p = 1;
	for (i = 0; i < n; i++) p *= x;
	return p;
}