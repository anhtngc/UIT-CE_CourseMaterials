#include "CDate.h"

int CDate::count = 0;

CDate::CDate()
{
    this->day = day;
    this->month = month;
    this->year = year;
    count++;
}

//CDate::CDate(int day = 27, int month = 4, int year = 2023)
//{
//	this->day = day;
//	this->month = month;
//	this->year = year;
//}

CDate::~CDate()
{
    count--;
}

// Đếm số ngày trong tháng
int CDate::daysInAMonth(int month, int year)
{
    if (month == 2) 
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
            return 29;
        else 
            return 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) 
        return 30;
    else 
        return 31;
}

// Cộng thêm một số ngày
CDate CDate::operator+(int days)
{
    if (days < 0)
    {
        do
        {
            cout << "Khong hop le, vui long nhap mot so duong!: ";
            cin >> days;
        } while (days < 0);
        CDate temp = *this;
        temp.day += days;
        while (temp.day > daysInAMonth(temp.month, temp.year))
        {
            temp.day -= daysInAMonth(temp.month, temp.year);
            temp.month++;
            if (temp.month > 12)
            {
                temp.month = 1;
                temp.year++;
            }
        }
    }
    else
    {
        CDate temp = *this;
        temp.day += days;
        while (temp.day > daysInAMonth(temp.month, temp.year))
        {
            temp.day -= daysInAMonth(temp.month, temp.year);
            temp.month++;
            if (temp.month > 12)
            {
                temp.month = 1;
                temp.year++;
            }
        }
        return temp;
    }
}

// Trừ đi một số ngày
CDate CDate::operator-(int days)
{
    if (days < 0)
    {
        do
        {
            cout << "Khong hop le, vui long nhap mot so duong!: ";
            cin >> days;
        } while (days < 0);
        CDate temp = *this;
        temp.day -= days;
        while (temp.day < 1)
        {
            if (temp.month == 1)
            {
                temp.month = 12;
                temp.year--;
            }
            else
            {
                temp.month--;
            }
            temp.day += daysInAMonth(temp.month, temp.year);
        }
        return temp;
    }
    else
    {
        CDate temp = *this;
        temp.day -= days;
        while (temp.day < 1)
        {
            if (temp.month == 1)
            {
                temp.month = 12;
                temp.year--;
            }
            else
            {
                temp.month--;
            }
            temp.day += daysInAMonth(temp.month, temp.year);
        }
        return temp;
    }
}

// Thêm một ngày
CDate CDate::operator++()
{
    *this = *this + 1;
    return *this;
}

// Bớt một ngày
CDate CDate::operator--()
{
    *this = *this - 1;
    return *this;
}

// Tính số ngày chênh lệch giữa hai CDate
int CDate::setThuTuChoNgay()
{
    int day_year[2][12] = { {31,29,31,30,31,30,31,31,30,31,30,31},{31,28,31,30,31,30,31,31,30,31,30,31} };
    int i;
    int s = day;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) i = 0;
    else i = 1;
    for (int j = 0; j < month - 1; j++)  
        s += day_year[i][j];
    return s;
}

int CDate::DaysInAYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) 
        return 366;
    return 365;
}

int CDate::operator-(CDate& d)
{
    int d1 = setThuTuChoNgay();
    int d2 = d.setThuTuChoNgay();
    if (year == d.year) 
        return(abs(d1 - d2));
    int s = 0;
    if (year < d.year)
    {
        d1 = DaysInAYear(year) - d1;
        for (int i = year + 1; i < d.year; i++) 
            s += DaysInAYear(i);
        return(s + d1 + d2);
    }
    else
    {
        d2 = DaysInAYear(d.year) - d2;
        for (int i = d.year + 1; i < year; i++) 
            s += DaysInAYear(i);
        return(s + d1 + d2);
    }
}

// Nhập CDate
istream& operator>>(istream& in, CDate& date) 
{
    cout << "Ngay (tu 1 den 31): ";
    in >> date.day;
    cout << "Thang (tu 1 den 12): ";
    in >> date.month;
    cout << "Nam: ";
    in >> date.year;
    if (date.day > date.daysInAMonth(date.month, date.year))
    {
        do
        {
            cout << "Ngay, thang, nam khong hop le! Vui long nhap lai." << endl;
            cout << "Luu y: " << endl;
            cout << "- Thang 1,3,5,7,8,10,12 co 31 ngay" << endl;
            cout << "- Thang 2 co 28 ngay va trong nam nhuan thi co 29 ngay" << endl;
            cout << "- Nam nhuan la cac nam chia het cho 4" << endl;
            cout << "Ngay (tu 1 den 31): ";
            in >> date.day;
            cout << "Thang (tu 1 den 12): ";
            in >> date.month;
            cout << "Nam: ";
            in >> date.year;
        } while (date.day > date.daysInAMonth(date.month, date.year));
    }
    date.count++;
    return in;
}

// Xuất CDate
ostream& operator<<(ostream& out, CDate& date)
{
    out << date.day << "/" << date.month << "/" << date.year;
    return out;
}