#pragma once
#ifndef _DIEM
#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    double x;
    double y;

public:
    //~DIEM();
    Point(double = 0, double = 0);
    double GetX() const;
    double GetY() const;
    void SetX(double);
    void SetY(double);
    void SetXY(double, double);
    void dichuyen(double dx, double dy);
    bool kiemtratrungnhau(const Point&) const;
    float TinhKhoangCach(const Point&) const;
    Point laydoixung() const;
    bool KiemTraTamGiac(const Point&, const Point&) const;
    float TinhChuViTamGiac(const Point&, const Point&) const;
    float TinhDienTichTamGiac(const Point&, const Point&) const;
    string PhanLoaiTamGiac(const Point&, const Point&) const;
    friend istream& operator>>(istream&, Point&);
    friend ostream& operator<<(ostream&, Point);
};
#endif

