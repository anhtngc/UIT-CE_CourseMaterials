#include "ClassThiSinh.h"

void Candidate::NhapThongTin()
{
	cin.ignore();
	cout << "Nhap ma so cua thi sinh: ";
	getline(cin, Maso);
	cout << "Nhap ten thi sinh: ";
	getline(cin, Hoten);
	cout << "Nhap ngay, thang, nam sinh cua thi sinh (dd/mm/yyyy): ";
	getline(cin, NgaySinh);
	cout << "Nhap diem Toan: ";
	cin >> diemToan;
	cout << "Nhap diem Van: ";
	cin >> diemVan;
	cout << "Nhap diem Anh: ";
	cin >> diemAnh;
}

double Candidate::TinhTongDiem()
{
	double b = diemToan + diemVan + diemAnh;
	return b;
}

void Candidate::XuatThongTin()
{
	cout << "Ma: " << Maso;
	cout << "   Ten: " << Hoten;
	cout << "   Ngay sinh: " << NgaySinh;
	cout << "   Diem toan: " << diemToan;
	cout << "   Diem van: " << diemVan;
	cout << "   Diem anh: " << diemAnh;
	cout << "   Tong diem: " << TinhTongDiem();
}

void TestCandidate::NhapDanhSachThiSinh()
{
	cout << "Nhap so luong thi sinh: ";
	cin >> n;
	listThiSinh = new Candidate[n];
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap thong tin thi sinh thu " << i + 1 << endl;
		listThiSinh[i].NhapThongTin();
	}
}

void TestCandidate::InDanhSachDiemLonHon15()
{
	int j = 1;
	cout << "\nDanh sach cac thi sinh co tong diem 3 mon (Toan, Van, Anh) lon hon 15: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (listThiSinh[i].TinhTongDiem() > 15)
		{
			cout << j << ".";
			j++;
			listThiSinh[i].XuatThongTin();
			cout << endl << "\n";
		}
	}
}
