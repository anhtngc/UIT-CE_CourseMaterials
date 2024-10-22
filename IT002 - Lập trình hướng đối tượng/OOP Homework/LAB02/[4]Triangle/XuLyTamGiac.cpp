#include "TamGiac.h"

Triangle::Triangle(Point A, Point B, Point C)
{
	this->A = A;
	this->B = B;
	this->C = C;
}

Triangle::Triangle(double xA, double yA, double xB, double yB, double xC, double yC)
{
	A = Point(xA, yA);
	B = Point(xB, yB);
	C = Point(xC, yC);
}

void Triangle::NhapTamGiac()
{
	cout << "Nhap toa do diem A" << endl;
	A.NhapDiem();
	cout << "\nNhap toa do diem B" << endl;
	B.NhapDiem();
	cout << "\nNhap toa do diem C" << endl;
	C.NhapDiem();
}

void Triangle::XuatTamGiac()
{
	double a, b, c;
	a = B.TinhKhoangCach(A);
	b = C.TinhKhoangCach(B);
	c = C.TinhKhoangCach(A);
	if (A.KiemTraTamGiac(B, C))
	{
		cout << "\nTam giac ABC duoc tao thanh tu 3 diem: A";
		A.XuatDiem();
		cout << ", B";
		B.XuatDiem();
		cout << " va C";
		C.XuatDiem();
		A.PhanLoaiTamGiac(B, C);
		cout << "Do dai ba canh cua tam giac la: AB = " << a << ", BC = " << b << " va AC = " << c;
	}
	else
	{
		do
		{
			int choice;
			cout << "\nBa diem A, B, C khong tao thanh mot tam giac hop le." << endl;
			cout << "0: Khong va dung chuong trinh\n";
			cout << "1: Co\n";
			cout << "Ban co muon nhap lai tam giac khac khong?: ";
			cin >> choice;
			while (choice != 0 && choice != 1)
			{
				cout << "Ban chi duoc chon so (0 va 1) tuong ung voi 2 lua chon tren, moi ban chon lai: ";
				cin >> choice;
			}
			if (choice == 1)
			{
				cout << "\n";
				cout << "Nhap toa do diem A" << endl;
				A.NhapDiem();
				cout << "\nNhap toa do diem B" << endl;
				B.NhapDiem();
				cout << "\nNhap toa do diem C" << endl;
				C.NhapDiem();
			}
			else if (choice == 0)
			{
				cout << "Nhan phim bat ky de thoat chuong trinh." << endl;
				break;
			}
		} while (A.KiemTraTamGiac(B, C));
		cout << "\nTam giac ABC duoc tao thanh tu 3 diem: A";
		A.XuatDiem();
		cout << ", B";
		B.XuatDiem();
		cout << " va C";
		C.XuatDiem();
		A.PhanLoaiTamGiac(B, C);
		cout << "Do dai ba canh cua tam giac la: AB = " << a << ", BC = " << b << " va AC = " << c;
	}
}

Point Triangle::GetA() const
{
	return A;
}

void Triangle::SetA(Point A)
{
	this->A = A;
}

Point Triangle::GetB() const
{
	return B;
}

void Triangle::SetB(Point B)
{
	this->B = B;
}

Point Triangle::GetC() const
{
	return C;
}

void Triangle::SetC(Point C)
{
	this->C = C;
}

double Triangle::TinhChuVi(Triangle ABC)
{
	return A.TinhChuViTamGiac(B, C);
}

double Triangle::TinhDienTich(Triangle ABC)
{
	return A.TinhDienTichTamGiac(B, C);
}