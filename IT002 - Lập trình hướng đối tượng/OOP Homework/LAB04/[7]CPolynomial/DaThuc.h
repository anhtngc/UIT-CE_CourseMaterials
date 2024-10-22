#pragma once
#ifndef POLYNOMIAL
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class DaThuc
{
private:
	vector<double> heso;
	int bac;
	static int count;
public:
	DaThuc();
	DaThuc(const vector<double>&, int);
	~DaThuc();
	static int GetCount() {
		return count;
	}
	int GetBac() const;
	void SetBac(int);
	double GetHeSo(int) const;
	void SetHeSo(int, double);
	double Tinh(double) const;
	DaThuc operator+(const DaThuc&) const;
	DaThuc& operator=(const DaThuc&);
	bool operator==(const DaThuc&) const;
	friend istream& operator>>(istream& in, DaThuc&);
	friend ostream& operator<<(ostream& out, const DaThuc&);
};
#endif // !POLYNOMIAL

