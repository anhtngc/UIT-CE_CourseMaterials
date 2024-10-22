#include <iostream>
#include <math.h>

using namespace std;

typedef struct COMPLEX_NUMBERS
{
    float phanthuc;
    float phanao;
} sophuc;

void NhapSoPhuc(sophuc &a)
{
    cout << "Nhap phan thuc: ";
    cin >> a.phanthuc;
    cout << "Nhap phan ao: ";
    cin >> a.phanao;
}

void XuatSoPhuc(sophuc &a)
{
    if (a.phanao > 0 || a.phanao == 0)
        cout << a.phanthuc << " + " << a.phanao << "i" << endl;
    else
        cout << a.phanthuc << " - " << -(a.phanao) << "i" << endl;
}

void Tinh(sophuc &a, sophuc &b)
{
    sophuc tong, hieu, tich, thuong;
    tong.phanthuc = a.phanthuc + b.phanthuc;
    tong.phanao = a.phanao + b.phanao;
    cout << "\nTong hai so phuc la: ";
    XuatSoPhuc(tong);
    hieu.phanthuc = a.phanthuc - b.phanthuc;
    hieu.phanao = a.phanao - b.phanao;
    cout << "\nHieu hai so phuc la: ";
    XuatSoPhuc(hieu);
    tich.phanthuc = a.phanthuc * b.phanthuc - a.phanao * b.phanao;
    tich.phanao = a.phanthuc * b.phanao - a.phanao * b.phanthuc;
    cout << "\nTich hai so phuc la: ";
    XuatSoPhuc(tich);
    float tongbinhphuong = b.phanthuc * b.phanthuc + b.phanao * b.phanao;
    thuong.phanthuc = (a.phanthuc * a.phanao + b.phanthuc * b.phanao) / tongbinhphuong;
    thuong.phanao = (a.phanao * b.phanthuc - a.phanthuc * b.phanao) / tongbinhphuong;
    cout << "\nThuong hai so phuc la: ";
    XuatSoPhuc(thuong);
}

void Argument_Modul(sophuc &a)
{
    cout << "\nArgument cua so phuc A la: " << atan(a.phanao / a.phanthuc) << endl;
    cout << "\nModule cua so phuc A la: " << sqrt(a.phanthuc * a.phanthuc + a.phanao * a.phanao) << endl;
}
int main()
{
    sophuc Z1, Z2;
    cout << "< NHAP SO PHUC THU NHAT >" << endl;
    NhapSoPhuc(Z1);
    cout << "So phuc A co dang: ";
    XuatSoPhuc(Z1);
    cout << "< NHAP SO PHUC THU HAI >" << endl;
    NhapSoPhuc(Z2);
    cout << "So phuc B co dang: ";
    XuatSoPhuc(Z2);
    Tinh(Z1, Z2);
    Argument_Modul(Z1);
    cout << "\n";
    return 0;
}
