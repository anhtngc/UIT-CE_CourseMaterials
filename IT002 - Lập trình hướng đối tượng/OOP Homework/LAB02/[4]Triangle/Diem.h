#pragma once
#ifndef POINT
#include <iostream>
using namespace std;
class Point
{
private:
	double x;
	double y;
public:
	Point(double = 0, double = 0);
	void NhapDiem();
	void XuatDiem();
	double GetX();
	void SetX(double);
	double GetY();
	void SetY(double);
	void SetXY(double, double);
	void DiChuyenDiem(double, double);
	bool KiemTraTrungNhau(Point);
	double TinhKhoangCach(Point);
	Point LayDoiXung();
	bool KiemTraTamGiac(Point, Point);
	double TinhChuViTamGiac(Point, Point);
	double TinhDienTichTamGiac(Point, Point);
	void PhanLoaiTamGiac(Point, Point);
};
#endif // !Point
