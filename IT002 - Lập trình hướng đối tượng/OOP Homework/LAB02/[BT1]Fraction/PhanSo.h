#pragma once
#ifndef FRACTION
#include <iostream>
#include <math.h>
using namespace std;
class PhanSo
{
private:
	double TuSo;
	double MauSo;
public:
	PhanSo(double = 1.1, double = 1.1);
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
};
#endif // !FRACTION

