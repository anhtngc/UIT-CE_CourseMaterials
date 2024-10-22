#include "PhanSo.h"

void NhapPhanSo(PS& p)
{
	cout << "Nhap tu so: ";
	cin >> p.TuSo;
	do
	{
		cout << "Nhap mau so (khac 0): ";
		cin >> p.MauSo;
	} while (p.MauSo == 0);
}

void XuatPhanSo(PS p)
{
	if (p.MauSo < 1)
		cout << -p.TuSo << "/" << -p.MauSo << endl;
	else if (p.MauSo == -1)
		cout << -p.TuSo << endl;
	else if (p.MauSo == 1)
		cout << p.TuSo << endl;
	else
		cout << p.TuSo << "/" << p.MauSo << endl;
}

int UCLN(int m, int n)
{
	int uscln;
	m = abs(m);
	n = abs(n);
	if (m == 0 && n == 0)
		uscln = 1;
	else if (m == 0 || n == 0)
		uscln = m + n;
	else
	{
		while (m != n)
		{
			if (m > n)
				m -= n;
			else
				n -= m;
		}
		uscln = m;
	}
	return uscln;
}

void RutGon(PS p)
{
	int a = UCLN(p.TuSo, p.MauSo);
	p.TuSo = p.TuSo / a;
	p.MauSo = p.MauSo / a;
	cout << "Phan so vua nhap duoc rut gon thanh : ";
	XuatPhanSo(p);
}

void SoSanh(PS& ps1, PS& ps2)
{
	int a = ps1.TuSo;
	int b = ps1.MauSo;
	int c = ps2.TuSo;
	int d = ps2.MauSo;
	if (float(a) / float(b) > float(c) / float(d))
	{
		cout << "Phan so thu nhat lon hon phan so thu hai." << endl;
	}
	else
		if (float(a) / float(b) < float(c) / float(d))
		{
			cout << "Phan so thu hai lon hon phan so thu nhat." << endl;
		}
		else
		{
			cout << "Hai phan so bang nhau." << endl;
		}
}

void Tong(PS ps1, PS ps2)
{
	PS p;
	p.TuSo = ps1.TuSo * ps2.MauSo + ps1.MauSo * ps2.TuSo;
	p.MauSo = ps1.MauSo * ps2.MauSo;
	XuatPhanSo(p);
}

void Hieu(PS ps1, PS ps2)
{
	PS p;
	p.TuSo = ps1.TuSo * ps2.MauSo - ps1.MauSo * ps2.TuSo;
	p.MauSo = ps1.MauSo * ps2.MauSo;
	XuatPhanSo(p);
}

void Tich(PS ps1, PS ps2)
{
	PS p;
	p.TuSo = ps1.TuSo * ps2.TuSo;
	p.MauSo = ps1.MauSo * ps2.MauSo;
	XuatPhanSo(p);
}

void Thuong(PS ps1, PS ps2)
{
	PS p;
	p.TuSo = ps1.TuSo * ps2.MauSo;
	p.MauSo = ps1.MauSo * ps2.TuSo;
	XuatPhanSo(p);
}