#pragma once
#ifndef ComplexNumber
#include <iostream>
#include <math.h>
using namespace std;
class SoPhuc
{
private:
	double phanThuc;
	double phanAo;
public:
	SoPhuc();
	SoPhuc(double, double);
	double LayPhanThuc();
	double LayPhanAo();
	void DatPhanThuc(double);
	void DatPhanAo(double);
	void NhapSoPhuc();
	void XuatSoPhuc();
	SoPhuc TinhTong(SoPhuc&);
	SoPhuc TinhHieu(SoPhuc&);
	SoPhuc TinhTich(SoPhuc&);
	SoPhuc TinhThuong(SoPhuc&);
};
#endif // !ComplexNumber