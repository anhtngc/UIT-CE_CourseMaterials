#pragma once
#ifndef DIEM2CHIEU
#include <iostream>
#include <math.h>
using namespace std;
class POINT2D
{
protected:
	double x, y;
	static int count;
public:
	~POINT2D();
	POINT2D(double = 0, double = 0);
	POINT2D(const POINT2D&);
	double GetX() const;
	double GetY() const;
	static int GetCount() {
		return count;
	}
	void SetX(double);
	void SetY(double);
	void SetXY(double, double);
	void NhapDiem();
	void XuatDiem() const;
	void DiChuyenDiem(double, double);
	bool KiemTraDiemTrung(const POINT2D&) const;
	double TinhKhoangCach(const POINT2D&) const;
	POINT2D TimDiemDoiXung() const;
	bool KiemTraTamGiacHopLe(const POINT2D&, const POINT2D&) const;
	double TinhChuViTamGiac(const POINT2D&, const POINT2D&) const;
	double TinhDienTichTamGiac(const POINT2D&, const POINT2D&) const;
	string PhanLoaiTamGiac(const POINT2D&, const POINT2D&) const;
	friend istream& operator>>(istream&, POINT2D&);
	friend ostream& operator<<(ostream&, const POINT2D&);
};
#endif // !DIEM2CHIEU

