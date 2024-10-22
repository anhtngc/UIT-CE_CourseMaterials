#pragma once
#ifndef PTBACNHAT
#include <iostream>
#include <math.h>

using namespace std;

class PTBacNhat
{
private:
	float a;
	float b;
public:
	PTBacNhat();
	PTBacNhat(float, float);
	void NhapHeSoBacNhat();
	void GiaiPhuongTrinhBacNhat();
	void XuatPhuongTrinhBacNhat();
};
#endif

