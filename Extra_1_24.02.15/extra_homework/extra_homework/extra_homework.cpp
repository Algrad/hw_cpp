// extra_homework.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

void print(int* array, size_t size) {
	for (size_t i = 0; i < size; ++i)
		cout << array[i] << ' ';
	cout << endl;
}

void set(int* array, size_t size, int value) {
	for (size_t i = 0; i < size; ++i)
		*array++ = value;
}

void copy1(int* source_array, int* copy_array, size_t size) {
	for (size_t i = 0; i < size; ++i)
		*copy_array++ = *source_array++;
}

void change_max_to_0(int* array, size_t size) {
	int* max = array;
	int* next = array;
	while (next < array + size)
	if (*max < *++next)
		max = next;
	*max = 0;
}
int sum_row(int* array, size_t size) {
	int sum = 0;
	for (size_t i = 0; i < size; ++i)
		sum += array[i];
	return sum;
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
	//ex1 set array, copy array
	cout << "ex1" << endl;
	
	int a[n];
	int b[n];
	set(a, n, 8);
	copy1(a, b, n);
	print(a, n);
	print(b, n);
	cout << endl;
	
	//ex2 replace max elemenet in array by 0
	cout << "ex2" << endl;
	
	int c[n] { 100, 8, 9, 121, 5, 8, 78, 9, 25, 777 };
	print(c, n);
	change_max_to_0(c, n);
	print(c, n);
	cout << endl;

	//ex3 check array contains a, b: abs(a - b) == 1 
	cout << "ex3" << endl;
	int d[n] { 7, 9, 11, 2, 1};
	check(d, n);
	cout << endl;

	//ex4
	
	int e[n][n] { { 3 }, { 6 }, { 4 }, { 1 }, { 8 }, { 9 } };
	int* ref[n];
	int sum_by_rows[n];
	for (size_t i = 0; i < n; ++i) {
		sum_by_rows[i] = sum_row(e[i], n);
		ref[i] = e[i];
	}
	for (size_t i = 0; i < n - 1; ++i)
		for (size_t j = i + 1; j < n; ++j)
		if (sum_by_rows[i] < sum_by_rows[j]) {
			swap(sum_by_rows[i], sum_by_rows[j]);
			swap(ref[i], ref[j]);
		}
	
	for (size_t i = 0; i < n; ++i)
		cout << ref[i][0] << ' ';
	print(sum_by_rows, n);
	
	system("pause");
	return 0;
}

