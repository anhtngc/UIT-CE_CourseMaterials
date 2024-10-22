#pragma once
#ifndef PTBACHAI
#include <iostream>
#include <math.h>
#include "PTBacNhat.h"
class PTBacHai
{
private:
	float a, b, c;
public:
	PTBacHai();
	PTBacHai(float, float, float);
	void NhapHeSo();
	void GiaiPhuongTrinh();
	void XuatPhuongTrinh();
};
#endif // !PTBACHAI

