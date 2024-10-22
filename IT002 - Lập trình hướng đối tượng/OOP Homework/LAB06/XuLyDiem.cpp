#include "Diem.h"
#define epsilon 0.00000001

int POINT2D::count = 0;

POINT2D::~POINT2D()
{
	--count;
}

POINT2D::POINT2D(double x, double y) : x(x), y(y)
{
	++count;
}

POINT2D::POINT2D(const POINT2D& point) : x(point.x), y(point.y)
{
	++count;
}

double POINT2D::GetX() const
{
	return x;
}

double POINT2D::GetY() const
{
	return y;
}

void POINT2D::SetX(double x)
{
	this->x = x;
}

void POINT2D::SetY(double y)
{
	this->y = y;
}

void POINT2D::SetXY(double x, double y)
{
	this->x = x;
	this->y = y;
}

void POINT2D::NhapDiem()
{
	cout << "Nhap hoanh do: ";
	cin >> x;
	cout << "Nhap tung do: ";
	cin >> y;
}

void POINT2D::XuatDiem() const
{
	cout << "(" << x << ", " << y << ")";
}

void POINT2D::DiChuyenDiem(double x, double y)
{
	this->x += x;
	this->y += y;
}

bool POINT2D::KiemTraDiemTrung(const POINT2D& p) const
{
	return x == p.x && y == p.y;
}

double POINT2D::TinhKhoangCach(const POINT2D& p) const
{
	return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

POINT2D POINT2D::TimDiemDoiXung() const // qua gốc tọa độ
{
	return POINT2D(-x == 0 ? x : -x, -y == 0 ? y : -y);
}

bool POINT2D::KiemTraTamGiacHopLe(const POINT2D& d1, const POINT2D& d2) const
{
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	return a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && a + c > b;
}

double POINT2D::TinhChuViTamGiac(const POINT2D& d1, const POINT2D& d2) const
{
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	return a + b + c;
}

double POINT2D::TinhDienTichTamGiac(const POINT2D& d1, const POINT2D& d2) const
{
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

string POINT2D::PhanLoaiTamGiac(const POINT2D& d1, const POINT2D& d2) const
{
	double a = this->TinhKhoangCach(d1);
	double b = d1.TinhKhoangCach(d2);
	double c = d2.TinhKhoangCach(*this);
	string ketqua = "";
	if (!KiemTraTamGiacHopLe(d1, d2))
		ketqua = "tam giac khong hop le.";
	else if (a == b && b == c)
		ketqua = "tam giac deu.";
	else if (a == b || b == c || c == a)
	{
		if (abs(a * a + b * b - c * c) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(b * b + c * c - a * a) <= epsilon)
			ketqua = "tam giac vuong can.";
		else
			ketqua = "tam giac can.";
	}
	else if (abs(a * a + b * b - c * c) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(b * b + c * c - a * a) <= epsilon)
		ketqua = "tam giac vuong.";
	else
		ketqua = "tam giac thuong.";
	return ketqua;
}

istream& operator>>(istream& in, POINT2D& d)
{
	cout << "Nhap hoanh do: ";
	in >> d.x;
	cout << "Nhap tung do: ";
	in >> d.y;
	return in;
}

ostream& operator<<(ostream& out, const POINT2D& d)
{
	out << "(" << d.x << ", " << ")";
	return out;
}