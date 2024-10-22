#pragma once
#ifndef TRIANGLE
#include "Diem.h"
using namespace std;
class Triangle
{
private:
	Point A, B, C;
	static int dem;
public:
	Triangle(Point, Point, Point);
	Triangle(double, double, double, double, double, double);
	void NhapTamGiac();
	void XuatTamGiac();
	Point GetA() const;
	void SetA(Point);
	Point GetB() const;
	void SetB(Point);
	Point GetC() const;
	void SetC(Point);
	double TinhChuVi(Triangle);
	double TinhDienTich(Triangle);
};
#endif // !Triangle
