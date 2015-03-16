#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

class rhombus {
protected:
	int cent_x = 0;
	int cent_y = 0;
	int hf_diag_x = 0;
	int hf_diag_y = 0;

public:
	rhombus(int center_x, int center_y, int half_horizontal_diag, int half_vertical_diag) :
		cent_x(center_x), cent_y(center_y),
		hf_diag_x(half_horizontal_diag), hf_diag_y(half_vertical_diag) 
	{}

	virtual void draw() {
		//something is drawing
		cout << ' ';
		for (auto i = -3; i < 2 * hf_diag_x; ++i)
			cout << '-';
		cout << '\n';
		cout << '|';
		for (auto i = 0; i < hf_diag_x; ++i)
			cout << ' ';
		cout << 'o';
		for (auto i = 0; i < hf_diag_y; ++i)
			cout << '\n' << '|';
		cout << 'o';
		for (auto i = 1; i < 2 * hf_diag_x; ++i)
			cout << ' ';
		cout << 'o';
		for (auto i = 0; i < hf_diag_y; ++i)
			cout << '\n' << '|';
		for (auto i = 0; i < hf_diag_x; ++i)
			cout << ' ';
		cout << 'o' << endl;
	}
};

class digit_rhombus : public rhombus {
public:
	digit_rhombus(int center_x, int center_y, int half_horizontal_diag, int half_vertical_diag) :
		rhombus(center_x, center_y, half_horizontal_diag, half_vertical_diag)
	{}
	void draw() {
		cout << '(' << cent_x - hf_diag_x << ", " << cent_y << "), ";
		cout << '(' << cent_x << ", " << cent_y + hf_diag_y << "), ";
		cout << '(' << cent_x + hf_diag_x << ", " << cent_y << "), ";
		cout << '(' << cent_x << ", " << cent_y - hf_diag_y << ")";
		cout << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	rhombus t(0, 0, 30, 5);
	t.draw();
	digit_rhombus t1(0, 0, 30, 5);
	t1.draw();
	system("pause");
	return 0;
}

