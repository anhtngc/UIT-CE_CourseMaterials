#pragma once
#ifndef ComplexNumber
#include <iostream>
using namespace std;
class SoPhuc
{
private:
	double phanThuc;
	double phanAo;
	static int count;
public:
	SoPhuc() : phanThuc(0), phanAo(0) { count++; }
	SoPhuc(double phanThuc) : phanThuc(phanThuc), phanAo(0) { count++; }
	SoPhuc(double phanThuc, double phanAo) : phanThuc(phanThuc), phanAo(phanAo) { count++; }
	~SoPhuc();
	static int GetCount() {
		return count;
	}
	double LayPhanThuc();
	double LayPhanAo();
	void DatPhanThuc(double);
	void DatPhanAo(double);
	friend SoPhuc operator+(const SoPhuc&, const SoPhuc&);
	friend SoPhuc operator-(const SoPhuc&, const SoPhuc&);
	friend SoPhuc operator*(const SoPhuc&, const SoPhuc&);
	friend SoPhuc operator/(const SoPhuc&, const SoPhuc&);
	friend bool operator==(const SoPhuc&, const SoPhuc&);
	friend bool operator!=(const SoPhuc&, const SoPhuc&);
	friend bool operator<=(const SoPhuc&, const SoPhuc&);
	friend bool operator<(const SoPhuc&, const SoPhuc&);
	friend bool operator>=(const SoPhuc&, const SoPhuc&);
	friend bool operator>(const SoPhuc&, const SoPhuc&);
	friend istream& operator>>(istream&, SoPhuc&);
	friend ostream& operator<<(ostream&, SoPhuc&);
};
#endif // !ComplexNumber
