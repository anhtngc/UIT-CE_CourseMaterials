#include "HinhChuNhat.h"

Rectangle::Rectangle()
{
	Point A(0, 0), B(1, 1);
}

Rectangle::Rectangle(const Point A, const Point B)
{
	this->A = A;
	this->B = B;
}

Rectangle::Rectangle(double xA, double yA, double xB, double yB) : A(xA, yA), B(xB, yB)
{
	if (!KiemTraHCN())
		cout << "Hai diem tren khong the tao thanh duong cheo cua hinh chu nhat, vui long nhap lai." << endl;
	cin >> A;
	cin >> B;
}

void Rectangle::NhapHCN()
{
	{
		cout << "Hinh chu nhat ABCD voi AC la duong cheo." << endl;
		cout << "Nhap toa do diem A" << endl;
		cin >> A;
		cout << "\nNhap toa do diem C" << endl;
		cin >> B;
		while (!KiemTraHCN())
		{
			cout << "\nHai diem tren khong the tao thanh duong cheo cua hinh chu nhat, vui long nhap lai." << endl;
			cout << "Nhap toa do diem A" << endl;
			cin >> A;
			cout << "\nNhap toa do diem C" << endl;
			cin >> B;
		}
	}
}

void Rectangle::XuatHCN()
{
	cout << "Hinh chu nhat ABCD co toa do hai dinh cua duong cheo la: A" << A << " va C" << B;
}

void Rectangle::SetA(Point A)
{
	this->A = A;
	while (!KiemTraHCN())
	{
		cout << "Nhap lai toa do dinh A:\n";
		cin >> A;
	}
}

Point Rectangle::GetA()
{
	return A;
}

void Rectangle::SetB(Point B)
{
	this->B = B;
	while (!KiemTraHCN())
	{
		cout << "Nhap lai toa do dinh C:\n";
		cin >> B;
	}
}

Point Rectangle::GetB()
{
	return B;
}

void Rectangle::DiChuyenHCN(float x, float y)
{
	A.dichuyen(x, y);
	B.dichuyen(x, y);
}

double Rectangle::TinhChuViHCN() const
{
	double a = abs(A.GetX() - B.GetX());
	double b = abs(A.GetY() - B.GetY());
	return 2 * (a + b);
}

double Rectangle::TinhDienTichHCN() const
{
	double a = abs(A.GetX() - B.GetX());
	double b = abs(A.GetY() - B.GetY());
	return a * b;
}

bool Rectangle::KiemTraHCN()
{
	float a = abs(A.GetX() - B.GetX());
	float b = abs(A.GetY() - B.GetY());
	return (a > 0 && b > 0);
}

istream& operator>>(istream& in, Rectangle& hcn)
{
	cout << "Hinh chu nhat ABCD voi AC la duong cheo." << endl;
	cout << "Nhap toa do diem A: " << endl;
	in >> hcn.A;
	cout << "Nhap toa do diem C: " << endl;
	in >> hcn.B;
	return in;
}

ostream& operator<<(ostream& out, Rectangle hcn)
{
	out << "Hinh chu nhat ABCD co toa do hai dinh cua duong cheo la: A" << hcn.A << " va C" << hcn.B << endl;
	return out;
}