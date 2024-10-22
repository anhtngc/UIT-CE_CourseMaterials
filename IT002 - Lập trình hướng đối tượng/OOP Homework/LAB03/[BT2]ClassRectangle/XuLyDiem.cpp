#include "Diem.h"
#define epsilon 0.001

/*DIEM::~DIEM()
{
    cout << "Da Huy 1 Diem \n";
}*/

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Point::GetX() const
{
    return x;
}

double Point::GetY() const
{
    return y;
}

void Point::SetX(double x)
{
    this->x = x;
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

void Point::dichuyen(double dx, double dy) 
{
    x += dx;
    y += dy;
}

bool Point::kiemtratrungnhau(const Point& d) const 
{
    return x == d.x && y == d.y;
}

float Point::TinhKhoangCach(const Point& d) const 
{
    return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}

Point Point::laydoixung() const 
{
    return Point(-x == 0 ? x : -x, -y == 0 ? y : -y);
}

istream& operator>>(istream& in, Point& point)
{
    cout << "Nhap hoanh do x: ";
    in >> point.x;
    cout << "Nhap tung do y: ";
    in >> point.y;
    return in;
}

ostream& operator<<(ostream& out, Point point)
{
    out << "(" << point.x << ", " << point.y << ")" << "";
    return out;
}