#pragma once
#ifndef DTBH
#include <iostream>
using namespace std;
class Polynomial
{
private:
	double a, b, c;
public:
	Polynomial() {};
	Polynomial(double, double, double);
	~Polynomial();
	double GetA() const;
	void SetA(double);
	double GetB() const;
	void SetB(double);
	double GetC() const;
	void SetC(double);
	double TinhF0(double) const;
	Polynomial operator+(const Polynomial&) const;
	friend istream& operator>>(istream&, Polynomial&);
	friend ostream& operator<<(ostream&, const Polynomial&);
};
#endif // !DTBH

