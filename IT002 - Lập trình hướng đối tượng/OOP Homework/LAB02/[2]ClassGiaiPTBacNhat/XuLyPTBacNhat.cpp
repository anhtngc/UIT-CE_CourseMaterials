#include "PTBacNhat.h"

PTBacNhat::PTBacNhat()
{
	this->a = a;
	this->b = b;
}

PTBacNhat::PTBacNhat(float a = 0, float b = 0)
{
	this->a = a;
	this->b = b;
}

void PTBacNhat::NhapHeSo()
{
	cout << "\nPhuong trinh co dang: ax + b = 0" << endl;
	cout << "Nhap he so a: ";
	cin >> a;
	cout << "Nhap he so b: ";
	cin >> b;
}

void PTBacNhat::GiaiPhuongTrinh()
{
	if (a == 0)
	{
		if (b == 0)
			cout << "\nPhuong trinh nay co vo so nghiem." << endl;
		else
			cout << "\nPhuong trinh nay vo nghiem." << endl;
	}
	else
		cout << "\nPhuong trinh nay co nghiem x = " << -b / a << endl;
	cout << "\n";
}

void PTBacNhat::XuatPhuongTrinh()
{
	if (b < 0)
		cout << "\nPhuong trinh " << a << "x - " << -b << " = 0";
	else
		cout << "\nPhuong trinh " << a << "x + " << b << " = 0";
}