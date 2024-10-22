#include "SoPhuc.h"

int SoPhuc::count = 0;

double SoPhuc::LayPhanThuc()
{
	return phanThuc;
}

double SoPhuc::LayPhanAo()
{
	return phanAo;
}

void SoPhuc::DatPhanThuc(double phanThuc)
{
	this->phanThuc = phanThuc;
}

void SoPhuc::DatPhanAo(double phanAo)
{
	this->phanAo = phanAo;
}

SoPhuc::~SoPhuc()
{
	count--;
}

SoPhuc operator+(const SoPhuc& sp1, const  SoPhuc& sp2)
{
	return SoPhuc(sp1.phanThuc + sp2.phanThuc, sp1.phanAo + sp2.phanAo);
}

SoPhuc operator-(const SoPhuc& sp1, const  SoPhuc& sp2)
{
	return SoPhuc(sp1.phanThuc - sp2.phanThuc, sp1.phanAo - sp2.phanAo);
}

SoPhuc operator*(const SoPhuc& sp1, const  SoPhuc& sp2)
{
	return SoPhuc(sp1.phanThuc * sp2.phanThuc - sp1.phanAo * sp2.phanAo, sp1.phanThuc * sp2.phanAo + sp1.phanAo * sp2.phanThuc);
}

SoPhuc operator/(const SoPhuc& sp1, const  SoPhuc& sp2)
{
	double denominator = sp2.phanThuc * sp2.phanThuc + sp2.phanAo * sp2.phanAo;
	return SoPhuc((sp1.phanThuc * sp2.phanThuc + sp1.phanAo * sp2.phanAo) / denominator, (sp1.phanAo * sp2.phanThuc - sp1.phanThuc * sp2.phanAo) / denominator);
}

bool operator==(const SoPhuc& sp1, const SoPhuc& sp2)
{
	return sp1.phanThuc == sp2.phanThuc && sp1.phanThuc == sp2.phanThuc;
}

bool operator!=(const SoPhuc& sp1, const SoPhuc& sp2)
{
	return sp1.phanThuc != sp2.phanThuc || sp1.phanThuc != sp2.phanThuc;
}

bool operator>=(const SoPhuc& sp1, const SoPhuc& sp2)
{
	return sp1.phanThuc >= sp2.phanThuc && sp1.phanThuc >= sp2.phanThuc;
}

bool operator>(const SoPhuc& sp1, const SoPhuc& sp2)
{
	return sp1.phanThuc > sp2.phanThuc && sp1.phanThuc > sp2.phanThuc;
}

bool operator<=(const SoPhuc& sp1, const SoPhuc& sp2)
{
	return sp1.phanThuc <= sp2.phanThuc && sp1.phanThuc <= sp2.phanThuc;
}

bool operator<(const SoPhuc& sp1, const SoPhuc& sp2)
{
	return sp1.phanThuc < sp2.phanThuc && sp1.phanThuc < sp2.phanThuc;
}

istream& operator>>(istream& is, SoPhuc& sp)
{
	cout << "Nhap phan thuc so phuc: ";
	is >> sp.phanThuc;
	cout << "Nhap phan ao so phuc: ";
	is >> sp.phanAo;
	sp.count++;
	return is;
}

ostream& operator<<(ostream& os, SoPhuc& sp) {
	if (sp.phanAo == 0)
		os << sp.phanThuc;
	else if (sp.phanAo == -1)
		os << sp.phanThuc << " - i";
	else if (sp.phanAo == 1)
		os << sp.phanThuc << " + i";
	else if (sp.phanAo < 0)
		os << sp.phanThuc << " - " << -sp.phanAo << "i";
	else
		os << sp.phanThuc << " + " << sp.phanAo << "i";
	return os;
}