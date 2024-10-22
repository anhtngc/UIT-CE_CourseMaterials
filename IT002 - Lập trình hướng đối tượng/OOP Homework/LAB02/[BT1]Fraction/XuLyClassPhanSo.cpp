#include "PhanSo.h"

PhanSo::PhanSo(double TuSo, double MauSo)
{
	this->TuSo = TuSo;
	this->MauSo = MauSo;
}

double PhanSo::LayTuSo()
{
	return TuSo;
}

double PhanSo::LayMauSo()
{
	return MauSo;
}

void PhanSo::DatTuSo(double TuSo)
{
	this->TuSo = TuSo;
}

void PhanSo::DatMauSo(double MauSo)
{
	this->MauSo = MauSo;
}

void PhanSo::NhapPhanSo()
{
	cout << "Nhap tu so: ";
	cin >> TuSo;
	do
	{
		cout << "Nhap mau so (khac 0): ";
		cin >> MauSo;
	} while (MauSo == 0);
}

double PhanSo::UCLN(double m, double n)
{
	double uscln;
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

PhanSo PhanSo::RutGon()
{
	PhanSo b;
	double a = UCLN(TuSo, MauSo);
	b.TuSo = this->TuSo / a;
	b.MauSo = this->MauSo / a;
	return b;
}

void PhanSo::XuatPhanSo()
{
	if (MauSo < 1)
	{
		cout << -TuSo << "/" << -MauSo;
	}
	else if (MauSo == -1)
	{
		cout << -TuSo;
	}
	else if (MauSo == 1)
	{
		cout << TuSo;
	}
	else
	{
		cout << TuSo << "/" << MauSo;
	}
}

PhanSo PhanSo::TinhTong(PhanSo a)
{
	PhanSo b;
	b.TuSo = this->TuSo * a.MauSo + a.TuSo * this->MauSo;
	b.MauSo = this->MauSo * a.MauSo;
	return b.RutGon();
}

PhanSo PhanSo::TinhHieu(PhanSo a)
{
	PhanSo b;
	b.TuSo = this->TuSo * a.MauSo - a.TuSo * this->MauSo;
	b.MauSo = this->MauSo * a.MauSo;
	return b.RutGon();
}

PhanSo PhanSo::TinhTich(PhanSo a)
{
	PhanSo b;
	b.TuSo = this->TuSo * a.TuSo;
	b.MauSo = this->MauSo * a.MauSo;
	return b.RutGon();
}

PhanSo PhanSo::TinhThuong(PhanSo a)
{
	PhanSo b;
	b.TuSo = this->TuSo * a.MauSo;
	b.MauSo = this->MauSo * a.TuSo;
	return b.RutGon();
}