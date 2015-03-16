#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <algorithm>

int get_nearest(const int* arr, size_t size, int x) {
	int l = 0;
	int r = size;
	while (l < r) {
		int mid = l + (r - l) / 2;
		
		if (arr[mid] == x) {
			return x;
		}

		if (arr[mid] > x) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
		
	}
	if ( abs(arr[r - 1] - x) < abs(arr[r] - x) ) {
		return arr[r - 1];
	}
	else {
		return arr[r];
	}

}

bool compare(const char* str1, const char* str2) {
	for (;;) {
		while (*str1 == ' ') {
			++str1;
		}
		while (*str2 == ' ') {
			++str2;
		}

		if (*str1 != *str2) {
			return false;
		}
		if (*str1 == '\0') {
			return true;
		}

		++str1;
		++str2;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "get_nearest" << '\n';
	const int a[] {1, 3, 7, 10, 20};
	auto n = get_nearest(a, 5, 0);
	std::cout << n << '\n';
	std::cout << '\n';

	std::cout << "compare" << '\n';
	char s1[100] = "as  dfg    h j";
	char s2[100] = "   a sd    f gh    j";
	bool b = compare(s1, s2);
	std::cout << b << '\n';

	system("pause");
	return 0;
}

