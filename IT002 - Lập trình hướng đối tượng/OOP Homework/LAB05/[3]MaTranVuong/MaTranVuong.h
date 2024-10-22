#pragma once
#ifndef MTV
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
class MATRANVUONG
{
private:
	int n;
	int** p;
public:
	~MATRANVUONG();
	MATRANVUONG(int = 0, int = 0);
	int GetN();
	int** GetP();
	friend istream& operator>>(istream&, MATRANVUONG&);
	friend ostream& operator<<(ostream&, MATRANVUONG&);
	MATRANVUONG& operator=(const MATRANVUONG&);
	void LietKeSoLeTrenDCheoChinh();
	int DemSoLuongPhanTuCoKyTuSoCuoiLa3();
	bool KiemTraNuaMang();
	int TimPhanTuChanMangVuongPhiaDuoiDCheoPhu();
	void SapXepGiamDanCacPhanTuNamTrenDCheoPhu();
	void TaoNgauNhienMaTranVuong();
};
#endif // !MTV

