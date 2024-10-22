#include "DaThucBacHai.h"

Polynomial::Polynomial(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

Polynomial::~Polynomial()
{
	cout << "Da huy mot da thuc." << endl;
}

double Polynomial::GetA() const
{
	return a;
}

void Polynomial::SetA(double a)
{
	this->a = a;
}

double Polynomial::GetB() const
{
	return b;
}

void Polynomial::SetB(double b)
{
	this->b = b;
}

double Polynomial::GetC() const
{
	return c;
}

void Polynomial::SetC(double c)
{
	this->c = c;
}

double Polynomial::TinhF0(double x0) const
{
	return a * x0 * x0 + b * x0 + c;
}

Polynomial Polynomial::operator+(const Polynomial& x) const
{
	double sumA = a + x.GetA();
	double sumB = b + x.GetB();
	double sumC = c + x.GetC();
	return Polynomial(sumA, sumB, sumC);
}

istream& operator>>(istream& in, Polynomial& x)
{
	cout << "Nhap he so a: ";
	in >> x.a;
	if (x.a == 0)
	{
		do
		{
			cout << "He so a phai khac 0, vui long nhap lai he so a: ";
			in >> x.a;
		} while (x.a == 0);
	}
	cout << "Nhap he so b: ";
	in >> x.b;
	cout << "Nhap he so c: ";
	in >> x.c;
	return in;
}

ostream& operator<<(ostream& out, const Polynomial& x)
{
	if (x.b != 0 && x.c != 0)
	{
		if (x.b < 0 && x.c < 0) {
			out << x.a << "x^2 - " << -x.b << "x - " << -x.c;
		}
		else if (x.b > 0 && x.c < 0) {
			out << x.a << "x^2 + " << x.b << "x - " << -x.c;
		}
		else if (x.b < 0 && x.c > 0) {
			out << x.a << "x^2 - " << -x.b << "x + " << x.c;
		}
		else {
			out << x.a << "x^2 + " << x.b << "x + " << x.c;
		}
	}
	else if (x.b == 0 || x.c == 0)
	{
		if (x.b == 0) {
			out << x.a << "x^2 + " << x.c;
		}
		else if (x.c == 0) {
			out << x.a << "x^2 + " << x.b << "x";
		}
	}
	else if (x.b == 0 && x.c == 0)
	{
		out << x.a << "x^2";
	}
	out << endl;
	return out;
}