// Homework_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

void swap(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}

void order(int& a, int& b, int& c) {
	if (c < a)
		swap(c, a);
	if (b < a)
		swap(a, b);
	if (c < b)
		swap(b, c);

}

void twice(int* i) {
	*i = 2 * *i;
}

void reverse(int* start, int* end) {
	while (start < end)
		swap(*start++, *end--);
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int n = 10;
	//2.1 reverse array

	cout << "2.1" << endl;
	int a[n] { 7, 2, 3 };
	for (auto i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;
	reverse(a, a + n - 1);
	for (auto i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl << endl;

	//2.2 triangular array
	cout << "2.2" << endl;
	int* a1[n];
	for (int i = 0; i < n; ++i) {
		a1[i] = new int[i + 1];
		for (int j = 0; j < i + 1; ++j) {
			a1[i][j] = (j == i);
			cout << a1[i][j] << ' ';
		}
		cout << endl;
	}
	for (int i = 0; i < n; ++i)
		delete[] a1[i];

	cout << endl;

	// 2.3 order 3 numbers
	cout << "2.3" << endl;
	int q1 = 3;
	int q2 = 2;
	int q3 = 1;
	order(q1, q2, q3);
	cout << q1 << ' ' << q2 << ' ' << q3 << endl;

	// 2.4 twice a number
	cout << "2.1" << endl;
	int i = 5;
	twice(&i);
	cout << i << endl;

	system("PAUSE");
	return 0;
}

