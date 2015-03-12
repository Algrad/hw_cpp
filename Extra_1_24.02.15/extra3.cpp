#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

void print(int* array, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		cout << array[i] << ' ';
	}
	cout << endl;
}

void check(int* array, size_t size) {
	for (int* curr = array; curr < array + size - 1; ++curr)
	for (int* next = curr + 1; next < array + size; ++next)
	if (abs(*curr - *next) == 1) {
		cout << "yes" << endl;
		return;
	}

	cout << "no" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int n = 10;

	//ex3 check array contains a, b: abs(a - b) == 1 
	cout << "ex3" << endl;
	int a[n] { 7, 9, 11, 2, 1};
	check(a, n);
	cout << endl;

	system("pause");
	return 0;
}

