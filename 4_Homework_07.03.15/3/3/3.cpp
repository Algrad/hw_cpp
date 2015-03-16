#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

struct list {
	int val;
	list* next;
};


int _tmain(int argc, _TCHAR* argv[])
{
	list* first = new list;
	first->next = nullptr;
	first->val = 480;

	int n = 15;
	for (auto i = 0; i < n; ++i){
		list* next = new list;
		next->val = i;
		next->next = first;
		first = next;
	}

	list* iter = first;
	while (iter) {
		cout << iter->val << ' ';
		iter = iter->next;
	}
	cout << endl;
	
	while (first) {
		list* tmp = first->next;
		delete first;
		first = tmp;
	}
	system("pause");
	return 0;
}

