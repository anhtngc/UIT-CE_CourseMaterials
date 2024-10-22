#pragma once
#ifndef Rectangle
#include <iostream>
#include <cmath>
#include "Diem.h"
using namespace std;
class Rectangle
{
private:
	Point A, B; // Điểm A, B là hai đỉnh đường chéo của hình chữ nhạtae
public:
	Rectangle();
	Rectangle(const Point, const Point);
	Rectangle(double, double, double, double);
	void NhapHCN();
	void XuatHCN();
	void SetA(Point);
	Point GetA();
	void SetB(Point);
	Point GetB();
	void DiChuyenHCN(float, float);
	double TinhChuViHCN() const;
	double TinhDienTichHCN() const;
	bool KiemTraHCN();
	friend istream& operator>>(istream&, Rectangle&);
	friend ostream& operator<<(ostream&, Rectangle);
};
#endif // !Rectangle

