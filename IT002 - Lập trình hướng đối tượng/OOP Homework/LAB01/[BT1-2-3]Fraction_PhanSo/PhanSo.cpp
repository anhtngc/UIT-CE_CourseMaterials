#include "PhanSo.h"

int main()
{
	PS ps, ps1, ps2;
	NhapPhanSo(ps);
	RutGon(ps);
	cout << "\n";
	cout << "< Phan so thu nhat >" << endl;
	NhapPhanSo(ps1);
	cout << "< Phan so thu hai >" << endl;
	NhapPhanSo(ps2);
	SoSanh(ps1, ps2);
	cout << "Tong cua hai phan so la: ";
	Tong(ps1, ps2);
	cout << "Hieu cua hai phan so la: ";
	Hieu(ps1, ps2);
	cout << "Tich cua hai phan so la: ";
	Tich(ps1, ps2);
	cout << "Thuong cua hai phan so la: ";
	Thuong(ps1, ps2);
	return 0; 
}