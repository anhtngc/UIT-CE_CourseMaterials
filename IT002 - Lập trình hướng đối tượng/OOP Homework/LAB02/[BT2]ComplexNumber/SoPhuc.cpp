#include "SoPhuc.h"

int main()
{
	SoPhuc SP1, SP2;
	cout << "THIET LAP SO PHUC THU NHAT:" << endl;
	SP1.NhapSoPhuc();
	cout << "THIET LAP SO PHUC THU HAI:" << endl;
	SP2.NhapSoPhuc();
	cout << "\nHai so phuc vua nhap la: A = ";
	SP1.XuatSoPhuc();
	cout << " va B = ";
	SP2.XuatSoPhuc();
	SoPhuc a = SP1.TinhTong(SP2);
	SoPhuc b = SP1.TinhHieu(SP2);
	SoPhuc c = SP1.TinhTich(SP2);
	SoPhuc d = SP1.TinhThuong(SP2);
	cout << "\nTong cua hai so phuc la: ";
	a.XuatSoPhuc();
	cout << "\nHieu cua hai so phuc la: ";
	b.XuatSoPhuc();
	cout << "\nTich cua hai so phuc la: ";
	c.XuatSoPhuc();
	cout << "\nThuong cua hai so phuc la: ";
	d.XuatSoPhuc();
	cout << "\n";
	return 0;
}
