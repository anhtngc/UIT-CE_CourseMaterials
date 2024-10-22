#pragma once
#ifndef FRACTION
#include <iostream>
#include <math.h>
using namespace std;
class PhanSo
{
private:
	int TuSo, MauSo;
	static int count;
public:
	PhanSo() : TuSo(0), MauSo(1) { count++; }
	PhanSo(int TuSo) : TuSo(TuSo), MauSo(1) { count++; }
	PhanSo(int TuSo, int MauSo) : TuSo(TuSo), MauSo(MauSo) { count++; }
	PhanSo(const PhanSo& ps) : TuSo(ps.TuSo), MauSo(ps.MauSo) { count++; }
	~PhanSo();
	static int GetCount() {
		return count;
	}
	double LayTuSo();
	double LayMauSo();
	void DatTuSo(double);
	void DatMauSo(double);
	void NhapPhanSo();
	double UCLN(double, double);
	PhanSo RutGon();
	void XuatPhanSo();
	PhanSo TinhTong(PhanSo);
	PhanSo TinhHieu(PhanSo);
	PhanSo TinhTich(PhanSo);
	PhanSo TinhThuong(PhanSo);
	friend PhanSo operator+(const PhanSo&, const PhanSo&);
	friend PhanSo operator-(const PhanSo&, const PhanSo&);
	friend PhanSo operator*(const PhanSo&, const PhanSo&);
	friend PhanSo operator/(const PhanSo&, const PhanSo&);
	PhanSo operator++(); 
	PhanSo operator++(int);
	PhanSo operator--();
	PhanSo operator--(int);
	operator double() const; //epkieu
	friend bool operator==(const PhanSo&, const PhanSo&);
	friend bool operator!=(const PhanSo&, const PhanSo&);
	friend bool operator<(const PhanSo&, const PhanSo&);
	friend bool operator<=(const PhanSo&, const PhanSo&);
	friend bool operator>(const PhanSo&, const PhanSo&);
	friend bool operator>=(const PhanSo&, const PhanSo&);
	friend istream& operator>>(istream&, PhanSo&);
	friend ostream& operator<<(ostream&, PhanSo&);
};
#endif // !FRACTION