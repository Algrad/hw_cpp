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

void change_max_to_0(int* array, size_t size) {
	int* max = array;
	int* next = array;
	while (next < array + size)
	if (*max < *++next) {
		max = next;
	}
	*max = 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int n = 10;

	//ex2 replace max elemenet in array by 0
	cout << "ex2" << endl;

	int a[n] { 100, 8, 9, 121, 5, 8, 78, 9, 25, 777 };
	print(a, n);
	change_max_to_0(a, n);
	print(a, n);
	cout << endl;

	system("pause");
	return 0;
}

