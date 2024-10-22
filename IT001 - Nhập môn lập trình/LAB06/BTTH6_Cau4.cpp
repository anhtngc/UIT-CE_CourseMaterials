#include <iostream>
#include <math.h>

using namespace std;

typedef struct POINT
{
    double hoanhdo;
    double tungdo;
} diem;

void NhapToaDo(diem &x)
{
    cout << "Nhap hoanh do x: ";
    cin >> x.hoanhdo;
    cout << "Nhap tung do y: ";
    cin >> x.tungdo;
}

void XuatToaDo(diem &x)
{
    cout << "(" << x.hoanhdo << ";" << x.tungdo << ")" << endl;
}

void KhoangCach(diem &x, diem &y)
{
    double a = y.hoanhdo - x.hoanhdo;
    double b = y.tungdo - x.tungdo;
    cout << "\nKhoang cach giua hai diem A va B la: " << sqrt(a * a - b * b) << endl;
}

void DoiXung(diem &x)
{
    diem goc, trucOx, trucOy;
    goc.hoanhdo = -x.hoanhdo;
    goc.tungdo = -x.tungdo;
    cout << "Diem doi xung qua goc toa do la: ";
    XuatToaDo(goc);
    trucOx.hoanhdo = x.hoanhdo;
    trucOx.tungdo = -x.tungdo;
    cout << "Diem doi xung qua truc Ox la: ";
    XuatToaDo(trucOx);
    trucOy.hoanhdo = -x.hoanhdo;
    trucOy.tungdo = x.tungdo;
    cout << "Diem doi xung qua truc Oy la: ";
    XuatToaDo(trucOy);
}

void GocPhanTu(diem &x)
{
    if (x.hoanhdo > 0 && x.tungdo > 0)
    {
        cout << "thuoc goc phan tu thu I." << endl;
    }
    else if (x.hoanhdo < 0 && x.tungdo > 0)
    {
        cout << "thuoc goc phan tu thu II." << endl;
    }
    else if (x.hoanhdo < 0 && x.tungdo < 0)
    {
        cout << "thuoc goc phan tu thu III." << endl;
    }
    else cout << "thuoc goc phan tu thu IV." << endl;
}

int main()
{
    diem A, B;
    cout << "< NHAP TOA DO DIEM A >" << endl;
    NhapToaDo(A);
    cout << "Diem A";
    XuatToaDo(A);
    cout << "< NHAP TOA DO DIEM B >" << endl;
    NhapToaDo(B);
    cout << "Diem B";
    XuatToaDo(B);
    KhoangCach(A, B);
    cout << "\n- Doi voi diem A -" << endl;
    DoiXung(A);
    cout << "\n- Doi voi diem B -" << endl;
    DoiXung(B);
    cout << "\nDiem A ";
    GocPhanTu(A);
    cout << "\nDiem B ";
    GocPhanTu(B);
    return 0;
}
