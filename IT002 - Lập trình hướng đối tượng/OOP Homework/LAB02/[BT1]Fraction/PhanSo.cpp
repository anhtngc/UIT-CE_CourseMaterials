#include "PhanSo.h"

int main()
{
	PhanSo PS1, PS2;
	cout << "THIET LAP PHAN SO THU NHAT" << endl;
	PS1.NhapPhanSo();
	cout << "THIET LAP PHAN SO THU HAI" << endl;
	PS2.NhapPhanSo();
	cout << "\nHai phan so vua duoc nhap la: ";
	PS1.XuatPhanSo();
	cout << " va ";
	PS2.XuatPhanSo();
	cout << "\nSau khi rut gon ta duoc" << endl;
	cout << "Phan so thu nhat: ";
	PS1.RutGon().XuatPhanSo();
	cout << "\nPhan so thu hai: ";
	PS2.RutGon().XuatPhanSo();
	cout << "\n";
	PhanSo a, b, c, d;
	a = PS1.TinhTong(PS2);
	b = PS1.TinhHieu(PS2);
	c = PS1.TinhTich(PS2);
	d = PS1.TinhThuong(PS2);
	cout << "\nTong hai phan so la: ";
	a.XuatPhanSo();
	cout << "\nHieu hai phan so la: ";
	b.XuatPhanSo();
	cout << "\nTich hai phan so la: ";
	c.XuatPhanSo();
	cout << "\nThuong hai phan so la: ";
	d.XuatPhanSo();
	cout << "\n";
	return 0;
}