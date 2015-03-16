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
		if (top == 0) {
			throw "Stack is empty!";
		}

		if (top != 0 && first_zero_pos == top) {
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

void f(stack_int& s) {
	int* array = new int[10000];
	try {
		for (;;) {
			std::cout << s.pop() << ' ';
		}
	}
	catch (const char* s) {
		std::cout << "Error: " << s << '\n';
	}
	std::cout << '\n';
	//std::cout << "Mem?" << '\n';
	delete[] array;
	//std::cout << "Yep" << '\n';

}

int _tmain(int argc, _TCHAR* argv[])
{
	stack_int s;
	try {
		s.pop();
	}
	catch(const char* s) {
		std::cout << "Error: " << s << '\n';
	}

	s.push(5);
	s.push(0);
	s.push(3);
	f(s);
	system("pause");
	return 0;
}

