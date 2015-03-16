#include "stdafx.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
using namespace std;

class shape {
	virtual double area() = 0;
	virtual double perim() = 0;
};

class rhombus : public shape {
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

	double area() {
		return  2 * hf_diag_x * hf_diag_y;
	}
	double perim() {
		return 4 * sqrt(hf_diag_x * hf_diag_x + hf_diag_y * hf_diag_y);
	}
};

class circle : public shape {
protected:
	int cent_x = 0;
	int cent_y = 0;
	int radius = 1;
public:
	circle(int center_x, int center_y, int radius_) :
		cent_x(center_x), cent_y(center_y),
		radius(radius_)
	{}

	double area(){
		return M_PI * radius * radius;
	}

	double perim() {
		return 2 * M_PI * radius;
	}
};



int _tmain(int argc, _TCHAR* argv[])
{
	circle c(0, 0, 1);
	rhombus r(0, 0, 3, 4);
	cout << c.area() << endl;
	cout << c.perim() << endl;
	cout << r.area() << endl;
	cout << r.perim() << endl;
	system("pause");
	return 0;
}

