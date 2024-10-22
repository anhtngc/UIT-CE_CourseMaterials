#pragma once
#ifndef BCC
#include <iostream>
#include <iomanip>

using namespace std;

class BangCuuChuong
{
private:
	int m;
	int n;
public:
	BangCuuChuong(int = 2, int = 9);
	int GetM();
	int GetN();
	void SetM(int);
	void SetN(int);
	void SetMN(int, int);
	void NhapBangCuuChuong();
	void InBCCtu1den10();
	void InBCCm();
	void InBCCmn();
	void XuatBangCuuChuong();
};
#endif // !BCC

