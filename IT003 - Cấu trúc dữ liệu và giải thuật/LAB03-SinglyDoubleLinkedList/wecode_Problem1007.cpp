#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 100

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};

void NhapSinhVien(SinhVien& sv)
{
    cin >> sv.MASV;
    cin.ignore();
    cin.getline(sv.HoTen, 100);
    cin >> sv.NgaySinh;
    cin >> sv.GioiTinh;
    cin >> sv.DiemToan;
    cin >> sv.DiemLy;
    cin >> sv.DiemHoa;
    sv.DTB = (sv.DiemToan + sv.DiemLy + sv.DiemHoa) / 3;
}

void Nhap(SinhVien A[], int& n)
{
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        NhapSinhVien(A[i]);
    }
}

void Swap(SinhVien& sv1, SinhVien& sv2)
{
    SinhVien tmp = sv1;
    sv1 = sv2;
    sv2 = tmp;
}

void SapXepGiamTheoMASV(SinhVien A[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int my_string_i = atoi(A[i].MASV);
            int my_string_j = atoi(A[j].MASV);
            if (my_string_i < my_string_j) {
                Swap(A[i], A[j]);
            }
        }
    }
}

void Xuat(SinhVien A[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << A[i].MASV << "\t" << A[i].HoTen << "\t" << A[i].NgaySinh << "\t" << A[i].GioiTinh << "\t" << A[i].DiemToan << "\t" << A[i].DiemLy << "\t" << A[i].DiemHoa << "\t";
        cout.precision(3);
        cout << A[i].DTB << endl;
    }
}

int main() {
    SinhVien A[MAXN];
    int n;
    Nhap(A, n);
    SapXepGiamTheoMASV(A, n);
    Xuat(A, n);
    return 0;
}