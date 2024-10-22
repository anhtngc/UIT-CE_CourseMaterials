#pragma once
#ifndef ThiSinh
#include <iostream>
#include <string>
using namespace std;
class Candidate
{
private:
	string Maso;
	string Hoten;
	string NgaySinh;
	double diemToan;
	double diemVan;
	double diemAnh;
public:
	void NhapThongTin();
	double TinhTongDiem();
	void XuatThongTin();
};

class TestCandidate
{
private:
	Candidate* listThiSinh;
	int n;
public:
	void NhapDanhSachThiSinh();
	void InDanhSachDiemLonHon15();
};
#endif // !ThiSinh

