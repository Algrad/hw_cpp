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

int sum_row(int* array, size_t size) {
	int sum = 0;
	for (size_t i = 0; i < size; ++i) {
		sum += array[i];
	}
	
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int n = 10;

	//ex4

	int a[n][n] {{ 3 }, { 6 }, { 4 }, { 1 }, { 8 }, { 9 } };
	int* b[n];
	int sum_by_rows[n];

	for (size_t i = 0; i < n; ++i) {
		sum_by_rows[i] = sum_row(a[i], n);
		b[i] = a[i];
	}

	for (size_t i = 0; i < n - 1; ++i)
	for (size_t j = i + 1; j < n; ++j)
	if (sum_by_rows[i] < sum_by_rows[j]) {
		swap(sum_by_rows[i], sum_by_rows[j]);
		swap(b[i], b[j]);
	}

	for (size_t i = 0; i < n; ++i) {
		cout << b[i][0] << ' ';
	}

	cout << endl;
	print(sum_by_rows, n);

	system("pause");
	return 0;
}

