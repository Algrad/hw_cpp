// extra_homework.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
const int n = 10;

void set(int * a, int length, int number) {
	for (int * p = a; p < a + length; p++) {
		*p = number;
	}
}

void my_copy(int * b, const int * a, int length) {
	const int * pointer_to_a = a;
	for (int * pointer_to_b = b; pointer_to_b < b + length; pointer_to_b++) {
		*pointer_to_b = *a;
		pointer_to_a++;
	}

}

int main() {
	int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	set(a, n, 11);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	int b[n] = { 10, 9, 8 };
	my_copy(b, a, n);
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}

