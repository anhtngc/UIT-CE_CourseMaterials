#include "PTBacHai.h"

PTBacHai::PTBacHai()
{
	this->a = a;
	this->b = b;
	this->c = c;
}

PTBacHai::PTBacHai(float a = 0, float b = 0, float c = 0)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

void PTBacHai::NhapHeSo()
{
	cout << "\nPhuong trinh co dang: ax^2 + bx + c = 0" << endl;
	cout << "Nhap he so a: ";
	cin >> a;
	cout << "Nhap he so b: ";
	cin >> b;
	cout << "Nhap he so c: ";
	cin >> c;
}

void PTBacHai::GiaiPhuongTrinh()
{
	if (a == 0)
	{
		PTBacNhat fx(b, c);
		fx.GiaiPhuongTrinhBacNhat();
	}
}