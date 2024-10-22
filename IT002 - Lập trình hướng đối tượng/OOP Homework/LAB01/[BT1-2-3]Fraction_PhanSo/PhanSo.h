#pragma once
#ifndef Fraction
#include <iostream>
using namespace std;
struct PS
{
	int TuSo;
	int MauSo;
};
void NhapPhanSo(PS&);
void XuatPhanSo(PS);
int UCLN(int, int);
void RutGon(PS);
void SoSanh(PS&, PS&);
void Tong(PS, PS);
void Hieu(PS, PS);
void Tich(PS, PS);
void Thuong(PS, PS);
#endif // !Fraction

