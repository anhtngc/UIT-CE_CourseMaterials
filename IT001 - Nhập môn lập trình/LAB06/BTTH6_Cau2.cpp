#include <iostream>

using namespace std;

typedef struct FRACTIONS
{
    int tuso;
    int mauso;
} phanso;

void NhapPhanSo(phanso& x)
{
    cout << "Nhap tu so: ";
    cin >> x.tuso;
    do
    {
        cout << "Nhap mau so: ";
        cin >> x.mauso;
    } while (x.mauso == 0);
}

int QuyDong(phanso x, phanso y, int& a, int& b, int& mauchung)
{
    a = x.tuso * y.mauso;
    b = y.tuso * x.mauso;
    mauchung = x.mauso * y.mauso;
    return mauchung;
}

int uscln(int a, int b)
{
    if (a % b == 0)
        return b;
    return uscln(b, a % b);
}

void RutGon(phanso &x)
{
    int uocchung = uscln(x.tuso, x.mauso);
    x.tuso = x.tuso / uocchung;
    x.mauso = x.mauso / uocchung;
    if (x.tuso % x.mauso != 0)
        cout << x.tuso << "/" <<  x.mauso << endl;
    else cout << x.tuso / x.mauso << endl;
}

void Tinh(phanso x, phanso y)
{
    phanso tong, hieu, tich, thuong;
    tong.tuso = x.tuso * y.mauso + y.tuso * x.mauso;
    tong.mauso = x.mauso * y.mauso;
    cout << "\nTong hai phan so la: ";
    RutGon(tong);
    hieu.tuso = x.tuso * y.mauso - y.tuso * x.mauso;
    hieu.mauso = x.mauso * y.mauso;
    cout << "\nHieu hai phan so la: ";
    RutGon(hieu);
    tich.tuso = x.tuso * y.tuso;
    tich.mauso = x.mauso * y.mauso;
    cout << "\nTich hai phan so la: ";
    RutGon(tich);
    thuong.tuso = x.tuso * y.mauso;
    thuong.mauso = y.tuso * x.mauso;
    cout << "\nThuong hai phan so la: ";
    RutGon(thuong);
}

void SoSanh(phanso x, phanso y,int &a,int &b,int &mauchung)
{
    QuyDong(x, y, a, b, mauchung);
    if (a == b)
        cout << "\nHai phan so da nhap bang nhau.";
    else if (a > b)
        cout << "\nPhan so thu nhat lon hon phan so thu hai.";
    else
        cout << "\nPhan so thu nhat nho hon phan so thu hai.";
}

int main()
{
	phanso PS1, PS2;
	int a, b, mauchung;
	cout << "< NHAP PHAN SO THU NHAT >" << endl;
	NhapPhanSo(PS1);
	cout << "Phan so thu nhat duoc rut gon thanh: ";
	RutGon(PS1);
	cout << "< NHAP PHAN SO THU HAI >" << endl;
	NhapPhanSo(PS2);
	cout << "Phan so thu hai duoc rut gon thanh: ";
	RutGon(PS2);
	Tinh(PS1, PS2);
	SoSanh(PS1, PS2, a, b, mauchung);
	cout << "\n";
	return 0;
}
