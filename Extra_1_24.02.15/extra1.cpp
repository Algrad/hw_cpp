#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

void print(const int* array, size_t size) {
	for (size_t i = 0; i < size; ++i)
		cout << array[i] << ' ';
	cout << endl;
}

void set(int* array, size_t size, int value) {
	for (size_t i = 0; i < size; ++i) {
		*array++ = value;
	}
}

void my_copy(const int* source_array, int* copy_array, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		*copy_array++ = *source_array++;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int n = 10;
	//ex1 set array, copy array
	cout << "ex1" << endl;
	
	int a[n];
	int b[n];
	set(a, n, 8);
	my_copy(a, b, n);
	print(a, n);
	print(b, n);
	cout << endl;
		
	system("pause");
	return 0;
}

