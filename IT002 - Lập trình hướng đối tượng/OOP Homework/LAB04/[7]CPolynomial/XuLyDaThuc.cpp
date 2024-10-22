#include "DaThuc.h"

int DaThuc::count = 0;

DaThuc::DaThuc() { count++; }

DaThuc::DaThuc(const vector<double>& h, int b) : heso(h), bac(b) { count++; }

DaThuc::~DaThuc()
{
	count--;
}

int DaThuc::GetBac() const
{
	return heso.size() - 1;
}

void DaThuc::SetBac(int bac)
{
	if (bac >= 0)
	{
		this->bac = bac;
		heso.resize(bac + 1, 0);
	}
}

double DaThuc::GetHeSo(int vitri) const
{
	if (vitri < 0 || vitri >= heso.size())
		return 0.0;
	return heso[vitri];
}

void DaThuc::SetHeSo(int vitri, double giatri)
{
	if (vitri < 0 || vitri >= heso.size())
		return;
	heso[vitri] = giatri;
}

double DaThuc::Tinh(double x) const
{
	double ketqua = 0.0;
	int n = heso.size();
	for (int i = 0; i < n; i++) {
		ketqua += heso[i] * pow(x, i);
	}
	return ketqua;
}

DaThuc DaThuc::operator+(const DaThuc& x) const 
{
	int maxBac = max(bac, x.bac);
	vector<double> ketqua(maxBac + 1, 0.0);
	for (int i = 0; i <= maxBac; i++) {
		double heSo1 = (i <= bac) ? heso[i] : 0.0;
		double heSo2 = (i <= x.bac) ? x.heso[i] : 0.0;
		ketqua[i] = heSo1 + heSo2;
	}
	count++;
	return DaThuc(ketqua, maxBac);
}

DaThuc& DaThuc::operator=(const DaThuc& x)
{
	if (this == &x)
		return *this;
	heso = x.heso;
	SetBac(x.bac);
	return *this;
}

bool DaThuc::operator==(const DaThuc& x) const
{
	return heso == x.heso;
}

istream& operator>>(istream& in, DaThuc& DT)
{
	cout << "Nhap so bac cua da thuc: ";
	in >> DT.bac;
	DT.SetBac(DT.bac);
	DT.heso.resize(DT.bac + 1);
	cout << "Nhap cac he so tuong ung cho: " << endl;
	for (int i = 0; i <= DT.bac; i++) {
		cout << "x^" << i << ": ";
		in >> DT.heso[i];
	}
	DT.count++;
	return in;
}

ostream& operator<<(ostream& out, const DaThuc& DT)
{
	for (int i = DT.bac; i >= 0; i--)
	{
		if (DT.heso[i] != 0) {
			if (DT.heso[i] < 0) {
				out << " - ";
			}
			else if (i != DT.bac) {
				out << " + ";
			}
			int absHeSo = abs(DT.heso[i]);
			if (absHeSo != 1 || i == 0) {
				out << absHeSo;
			}
			if (i > 0) 
			{
				out << "x";
				if (i > 1) {
					out << "^" << i;
				}
			}
		}
	}
	out << endl;
	return out;
}