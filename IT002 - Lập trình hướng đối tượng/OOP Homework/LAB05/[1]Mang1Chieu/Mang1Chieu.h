#pragma once
#ifndef M1C
#include <iostream>
#include <cmath>
using namespace std;
class Mang1Chieu
{
private:
	int size;
	int* arr;
public:
	~Mang1Chieu();
	Mang1Chieu();
	Mang1Chieu(int);
	Mang1Chieu(const Mang1Chieu&); 
	int GetSize();
	int* GetArray();
	Mang1Chieu& operator=(const Mang1Chieu&); 
	friend istream& operator>>(istream&, Mang1Chieu&);
	friend ostream& operator<<(ostream&, Mang1Chieu&);
	bool KiemTraSoNguyenTo(int);
	void LietKeSoNguyenTo();
	void DemSoChinhPhuong();
	bool KiemTraSoHoanThien(int); //số hoàn thiện là số dương mà tổng các ước nguyên dương bằng chính nó
	void TinhTongSoHoanThien();
	void TaoMangNgauNhien();
	bool KiemTraDoiXung(int);
	void TinhTrungBinhSoDoiXung();
	void KiemTraChanLe();
	void TimPhanTuChanNhoNhat();
	void Swap(int&, int&);
	void SapXepTangDan(); 
	void SapXepGiamDan();
	void XoaPhanTu(int);
	void ThemPhanTu(int, int);
	bool TimPhanTuX(int);
	void DemViTriXXuatHien(int);
};
#endif // !M1C
