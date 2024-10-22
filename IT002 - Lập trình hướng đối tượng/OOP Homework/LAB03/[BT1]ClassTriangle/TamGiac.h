#pragma once
#ifndef Triangle
#include <iostream>
#include <cmath>
#include "Diem.h"
using namespace std;
class Triangle
{
private:
	Point A, B, C;
public:
	Triangle();
	Triangle(const Point, const Point, const Point);
	Triangle(double, double, double, double, double, double);
	void NhapTamGiac();
	void XuatTamGiac();
	void SetA(Point);
	Point GetA() const;
	void SetB(Point);
	Point GetB() const;
	void SetC(Point);
	Point GetC() const;
	void DiChuyenTamGiac(float, float);
	double TinhChuViTamGiac() const;
	double TinhDienTichTamGiac() const;
	bool KiemTraTamGiac();
	void PhanLoaiTamGiac();
	friend istream& operator>>(istream&, Triangle&);
	friend ostream& operator<<(ostream&, Triangle);
};
#endif // !Triangle