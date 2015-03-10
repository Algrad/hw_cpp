// Homework.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>   
using namespace std;

int fact_last_non0(int n){
	//if (n == 0)
	//	return 1;
	int prod = 1;
	int num2 = 0;
	int num5 = 0;
	for(int i = 2; i <= n; ++i){
		int i1 = i;
		while (i1 % 2 == 0){
			i1 /= 2;
			++num2;
		}
		while (i1 % 5 == 0){
			i1 /= 5;
			++num5;
		}
		prod *= i1;
		prod %= 10;
	}
	for (int i = 0; i < num2 - num5; i++)
		prod = (prod * 2) % 10;
	return prod;
}
int _tmain(int argc, _TCHAR* argv[])
{
	//1.1
	cout << "1.1"<< endl;
	char again = 'y';
	do{
		cout << "enter n" << endl;
		int n = 0;
		double sum = 0;
		int sign = 1;
		cin >> n;
		for (int i = 1; i <= 2 * n + 1; i += 2){
			sum += (double)sign / (i * i);
			sign = -sign;
		}
		cout << sum << endl;
		cout << "again? (enter y)";
		cin >> again;
	}
	while (again == 'y');
	
	//1.2
	cout << "1.2" << endl;
	do{
		again = '\0';
		cout << "enter numbers, end with 0" << endl;
		int next = 0;
		int prod = 1;
		cin >> (int)next;
		while (next){
			prod *= next;
			cin >> next;
		}
		cout << prod << endl;
		cout << "again? (enter y)";
		cin >> again;
	}
	while (again == 'y');

	//1.3
	do{
		again = '\0';
		cout << "enter n" << endl;
		int n = 0;
		cin >> n;
		cout << fact_last_non0(n) << endl;
		cout << "again? (enter y)";
		cin >> again;
	}
	while (again == 'y');

	//1.4
	cout << "1.4" << endl;
	int a[10] = {1,2,3,4};
	int* p = a;
	while (*p != 0)
		++p;
	cout << p - a << endl;

	system("PAUSE");
	return 0;
}

