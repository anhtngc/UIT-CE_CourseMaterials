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
	void NhapHeSo();
	void GiaiPhuongTrinh();
	void XuatPhuongTrinh();
};
#endif
