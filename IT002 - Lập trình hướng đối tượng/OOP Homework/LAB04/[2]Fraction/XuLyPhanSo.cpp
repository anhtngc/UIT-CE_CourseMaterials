#include "PhanSo.h"

int PhanSo::count = 0;

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

PhanSo::~PhanSo()
{
	count--;
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
	count++;
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
	RutGon();
	if (MauSo < -1)
	{
		cout << -TuSo << "/" << -MauSo;
	}
	else if (MauSo == -1)
	{
		cout << -TuSo;
	}
	else if (MauSo == 0)
		cout << "Khong the chia cho 0";
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

PhanSo operator+(const PhanSo& ps1, const PhanSo& ps2)
{
	return PhanSo(ps1.TuSo * ps2.MauSo + ps1.MauSo * ps2.TuSo, ps1.MauSo * ps2.MauSo);
}

PhanSo operator-(const PhanSo& ps1, const  PhanSo& ps2)
{
	return PhanSo(ps1.TuSo * ps2.MauSo - ps1.MauSo * ps2.TuSo, ps1.MauSo * ps2.MauSo);
}

PhanSo operator*(const PhanSo& ps1, const  PhanSo& ps2)
{
	return PhanSo(ps1.TuSo * ps2.TuSo, ps1.MauSo * ps2.MauSo);
}

PhanSo operator/(const PhanSo& ps1, const  PhanSo& ps2)
{
	return PhanSo(ps1.TuSo * ps2.MauSo, ps1.MauSo * ps2.TuSo);
}

PhanSo PhanSo::operator++()
{
	TuSo += MauSo; // t?ng lên 1
	return *this;
}

PhanSo PhanSo::operator++(int)
{
	PhanSo pstam(TuSo, MauSo);
	TuSo += MauSo; // t?ng lên 1
	return pstam;
}

PhanSo PhanSo::operator--()
{
	TuSo -= MauSo; // gi?m xu?ng 1
	return *this;
}

PhanSo PhanSo::operator--(int)
{
	PhanSo pstam(TuSo, MauSo);
	TuSo -= MauSo; // gi?m xu?ng 1
	count++;
	return pstam;
}

PhanSo::operator double() const
{
	return (double)TuSo / MauSo;
}

bool operator==(const PhanSo& ps1, const PhanSo& ps2)
{
	return ps1.TuSo * ps2.MauSo == ps2.TuSo * ps1.MauSo;
}

bool operator!=(const PhanSo& ps1, const PhanSo& ps2)
{
	return ps1.TuSo * ps2.MauSo != ps2.TuSo * ps1.MauSo;
}

bool operator<(const PhanSo& ps1, const PhanSo& ps2)
{
	return ps1.TuSo * ps2.MauSo < ps2.TuSo* ps1.MauSo;
}

bool operator<=(const PhanSo& ps1, const PhanSo& ps2)
{
	return ps1.TuSo * ps2.MauSo <= ps2.TuSo * ps1.MauSo;
}

bool operator>(const PhanSo& ps1, const PhanSo& ps2)
{
	return ps1.TuSo * ps2.MauSo > ps2.TuSo * ps1.MauSo;
}

bool operator>=(const PhanSo& ps1, const PhanSo& ps2)
{
	return ps1.TuSo * ps2.MauSo >= ps2.TuSo * ps1.MauSo;
}

istream& operator>>(istream& is, PhanSo& ps)
{
	cout << "Nhap tu so: ";
	is >> ps.TuSo;
	do
	{
		cout << "Nhap mau so (khac 0): ";
		is >> ps.MauSo;
	} while (ps.MauSo == 0);
	ps.count++;
	return is;
}

ostream& operator<<(ostream& os, PhanSo& ps)
{
	ps.RutGon();
	if (ps.MauSo < -1)
		os << -ps.TuSo << "/" << -ps.MauSo;
	else if (ps.MauSo == -1)
		os << -ps.TuSo;
	else if (ps.MauSo == 0)
		os << "Khong chia cho so 0";
	else if (ps.MauSo == 1)
		os << ps.TuSo;
	else
		os << ps.TuSo << "/" << ps.MauSo;
	return os;
}