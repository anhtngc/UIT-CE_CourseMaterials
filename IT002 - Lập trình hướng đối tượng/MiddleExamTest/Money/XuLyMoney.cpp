#include "MONEY.h"
MONEY::~MONEY()
{
	this->dollar = 0;
	this->cent = 0;
	//Da Huy 1 MONEY
}
MONEY::MONEY()
{
	this->dollar = 0;
	this->cent = 0;
}
MONEY::MONEY(int dollar, int cent)
{
	this->dollar = dollar;
	this->cent = cent;
}
MONEY::MONEY(const MONEY& m)
{
	this->dollar = m.dollar;
	this->cent = m.cent;
}
int MONEY::GetDollar()
{
	return dollar;
}
int MONEY::GetCent()
{
	return cent;
}
void MONEY::SetDollar(int dollar)
{
	while (dollar <= 0)
	{
		cout << "Nhap dollar (dollar > 0) = " << "";
		cin >> dollar;
	}
	this->dollar = dollar;
}
void MONEY::SetCent(int cent)
{
	while (cent <= 0)
	{
		cout << "Nhap cent (cent > 0) = " << "";
		cin >> cent;
	}
	this->cent = cent;
}
// Phương thức đổi Money sang VND với tỷ giá là tham số truyền vào
int MONEY::To_VND(int menhgia) {
	int total_cents = this->dollar * 100 + this->cent;
	int vnd = total_cents * menhgia;
	return vnd;
}
MONEY& MONEY::operator++()
{
	this->cent += 1;
	if (this->cent == 100) {
		dollar += 1;
		cent = 0;
	}
	return *this;
}
istream& operator>>(istream& is, MONEY& m)
{
	do
	{
		cout << "Nhap dollar (dollar > 0) = ";
		is >> m.dollar;
	} while (m.dollar <= 0);
	do
	{
		cout << "Nhap cent (cent > 0) = ";
		is >> m.cent;
	} while (m.cent <= 0);
	return is;
}
ostream& operator<<(ostream& os, MONEY& m)
{
	if (m.cent >= 100)
	{
		int temp = m.cent / 100;
		m.dollar += temp;
		m.cent = m.cent - temp * 100;
		os << m.dollar << " dollars " << m.cent << " cents." << endl;
	}
	else
		os << m.dollar << " dollars " << m.cent << " cents." << endl;
	return os;
}