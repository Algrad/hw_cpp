#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <algorithm>

class stack_int {
private:
	int* array;
	int top;
	long long prod = 1;
	int first_zero_pos = 0;
	size_t size; 
	void inc_size(unsigned int x = 100) {
		int* temp_array = new int[size];
		for (size_t i = 0; i < size; ++i) {
			temp_array[i] = array[i];
		}
		delete[] array;
		
		size += x;
		array = new int[size];
		for (size_t i = 0; i < size; ++i) {
			array[i] = temp_array[i];
		}

		delete[] temp_array;
	};
public:
	stack_int() : top(0), prod(1), first_zero_pos(0), size(100) {
		array = new int[size];
	}

	~stack_int() {
		delete[] array;
	}

	void push(int x) {
		if (top == size) {
			inc_size();
		}
		
		if (first_zero_pos == top) {
			if (x) {
				prod *= x;
				++first_zero_pos;
			}
		}
		
		array[top] = x;
		++top;
	}

	int pop() {
		if (!top) {
			return -1; //temporarily
		}
		
		if (first_zero_pos == top) {
			prod /= array[top - 1];
			--first_zero_pos;
		}
		--top;
		return array[top];
	}

	int& s_top() {
		return array[top - 1];
	}

	long long product() {
		if (top > first_zero_pos) {
			return 0;
		}
		else {
			return prod;
		}
	}
};

bool compare(const char* str1, const char* str2) {
	for (auto i = 0;; ++i) {
		if (str1[i] != str2[i]) {
			return false;
		}
		if (str1[i] == '\0') {
			return true;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	//3.2, 3.3, 3.5
	stack_int s; 
	
	
	std::cout << s.product() << "\n";
	
	//3.4
	char s1[100];
	char s2[100];
	std::cin.getline(s1, 100);
	std::cin.getline(s2, 100);
	std::cout << compare(s1, s2) << '\n';
	system("pause");
	return 0;
}

