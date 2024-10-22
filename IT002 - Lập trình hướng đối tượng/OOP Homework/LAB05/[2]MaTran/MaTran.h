#pragma once
#ifndef MT
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
class MATRAN
{
private:
	int row, col;
	int** p;
public:
	~MATRAN();
	MATRAN(int = 0, int = 0, int = 0);
	int GetROW();
	int GetCOL();
	int** GetP();
	friend istream& operator>>(istream&, MATRAN&);
	friend ostream& operator<<(ostream&, MATRAN&);
	MATRAN& operator=(const MATRAN&);
	bool KiemTraSNT(int);
	void LietKeSoNguyenTo();
	bool KiemTraSoChinhPhuong(int);
	int DemSoChinhPhuong();
	bool KiemTraSoHoanThien(int);
	int TinhTongSoHoanThien(int);
	bool KiemTraDoiXung(int);
	int TinhTBCSoDoiXung(int);
	void SapXepTangDan(int);
	void TaoNgauNhienMaTran();
};
#endif // !_MATRAN
