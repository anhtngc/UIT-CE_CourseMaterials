#include "Diem.h"

using namespace std;

#define e 0.0001

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Point::NhapDiem()
{
	cout << "Nhap hoanh do: ";
	cin >> x;
	cout << "Nhap tung do: ";
	cin >> y;
}

void Point::XuatDiem()
{
	cout << "(" << x << ", " << y << ")";
}

double Point::GetX()
{
	return x;
}

void Point::SetX(double x)
{
	this->x = x;
}

double Point::GetY()
{
	return y;
}

void Point::SetY(double y)
{
	this->y = y;
}

void Point::SetXY(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Point::DiChuyenDiem(double dx, double dy)
{
	x += dx;
	y += dy;
}

bool Point::KiemTraTrungNhau(Point d)
{
	return x == d.x && y == d.y;
}

double Point::TinhKhoangCach(Point d)
{
	return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}

Point Point::LayDoiXung()
{
	this->x = -x;
	this->y = -y;
	return Point(x, y);
}

bool Point::KiemTraTamGiac(Point d1, Point d2)
{
	double a = TinhKhoangCach(d1);
	double b = TinhKhoangCach(d2);
	double c = d1.TinhKhoangCach(d2);
	if (a + b > c && b + c > a && c + a > b)
		return true;
	return false;
}

double Point::TinhChuViTamGiac(Point d1, Point d2)
{
	double a = TinhKhoangCach(d1);
	double b = TinhKhoangCach(d2);
	double c = d1.TinhKhoangCach(d2);
	return a + b + c;
}

double Point::TinhDienTichTamGiac(Point d1, Point d2)
{
	double a = TinhKhoangCach(d1);
	double b = TinhKhoangCach(d2);
	double c = d1.TinhKhoangCach(d2);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Point::PhanLoaiTamGiac(Point d1, Point d2)
{
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	if (a == b && a == c)
	{
		cout << "\nABC la tam giac deu." << endl;
	}
	else if (a == b || b == c || c == a)
	{
		if ((a * a + b * b - c * c) < e || (b * b + c * c - a * a) < e || (c * c + a * a - b * b) < e)
		{
			cout << "\nABC la tam giac vuong can." << endl;
		}
		else cout << "\nABC la tam giac can." << endl;
	}
	else if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b)
	{
		cout << "\nABC la tam giac vuong." << endl;
	}
	else
	{
		cout << "\nABC la tam giac thuong." << endl;
	}
}