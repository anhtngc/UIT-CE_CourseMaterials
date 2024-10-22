#include <iostream>
using namespace std;

class CTime {
private:
    int gio, phut, giay;
public:
    CTime(int h = 0, int m = 0, int s = 0) : gio(h), phut(m), giay(s) {}
    CTime(const CTime& t) { gio = t.gio; phut = t.phut; giay = t.giay; }
    CTime operator+(int s) const;
    CTime operator-(int s) const;
    CTime operator-(const CTime& t) const;
    CTime operator++(int);
    CTime operator--(int);
    friend ostream& operator<<(ostream& os, const CTime& t);
    friend istream& operator>>(istream& is, CTime& t);
};

CTime CTime::operator+(int s) const {
    CTime result(*this);
    result.giay += s;
    if (result.giay >= 60) {
        result.phut += result.giay / 60;
        result.giay %= 60;
    }
    if (result.phut >= 60) {
        result.gio += result.phut / 60;
        result.phut %= 60;
    }
    return result;
}

CTime CTime::operator-(int s) const {
    CTime result(*this);
    result.giay -= s;
    if (result.giay < 0) {
        result.phut -= (abs(result.giay) - 1) / 60 + 1;
        result.giay = 60 - abs(result.giay) % 60;
    }
    if (result.phut < 0) {
        result.gio -= (abs(result.phut) - 1) / 60 + 1;
        result.phut = 60 - abs(result.phut) % 60;
    }
    return result;
}

CTime CTime::operator-(const CTime& t) const
{
    CTime result(*this);
    int kq = 0;
    int first = result.gio * 60 * 60 + result.phut * 60 + result.giay;
    int last = t.gio * 60 * 60 + t.phut * 60 + t.giay;
    int h = 0, p = 0, s = 0;
    if (first >= last)
        kq = first - last;
    else
        kq = last - first;
    h = kq / 3600;
    kq = kq % 3600;
    p = kq / 60;
    kq = kq % 60;
    s = kq;
    return CTime(h, p, s);
}

CTime CTime::operator++(int)
{
    CTime result(*this);
    result.giay += 1;
    if (result.giay >= 60) {
        result.phut += result.giay / 60;
        result.giay %= 60;
    }
    if (result.phut >= 60) {
        result.gio += result.phut / 60;
        result.phut %= 60;
    }
    return result;
}

CTime CTime::operator--(int) {
    CTime result(*this);
    result.giay -= 1;
    if (result.giay < 0) {
        result.phut -= (abs(result.giay) - 1) / 60 + 1;
        result.giay = 60 - abs(result.giay) % 60;
    }
    if (result.phut < 0) {
        result.gio -= (abs(result.phut) - 1) / 60 + 1;
        result.phut = 60 - abs(result.phut) % 60;
    }
    return result;
}

ostream& operator<<(ostream& os, const CTime& t) {
    os << t.gio << "h" << t.phut << "ph" << t.giay << "s";
    return os;
}

istream& operator>>(istream& is, CTime& t) {
    cout << "Nhap gio: ";
    is >> t.gio;
    cout << "Nhap phut: ";
    is >> t.phut;
    cout << "Nhap giay: ";
    is >> t.giay;
    return is;
}


int main()
{
    CTime tg1, tg2, tg3;
    cout << "Nhap thoi gian thu 1: " << endl;
    cin >> tg1;
    cout << "Nhap thoi gian thu 2: " << endl;
    cin >> tg2;
    cout << "\nMENU" << endl;
    cout << "0: DUNG CHUONG TRINH" << endl;
    cout << "1: Nhap lai thoi gian thu 1" << endl;
    cout << "2: Nhap lai thoi gian thu 2" << endl;
    cout << "3: Cong them 1 so nguyen giay vao thoi gian 1" << endl;
    cout << "4: Cong them 1 so nguyen giay vao thoi gian 2" << endl;
    cout << "5: Tru di 1 so nguyen giay vao thoi gian 1" << endl;
    cout << "6: Tru di 1 so nguyen giay vao thoi gian 2" << endl;
    cout << "7: Tim khoang thoi gian giua thoi gian 1 va thoi gian 2 (CTimeSpan)" << endl;
    cout << "8: Cong them 1 giay vao thoi gian 1" << endl;
    cout << "9: Cong them 1 giay vao thoi gian 2" << endl;
    int n;
    cout << "\nChon bai toan ban muon lam: ";
    cin >> n;
    while (n != 0)
    {
        if (n == 1)
        {
            cout << "Nhap lai thoi gian 1" << endl;
            cin >> tg1;
            cout << "\nChon bai toan ban muon lam: ";
            cin >> n;
        }
        else if (n == 2)
        {
            cout << "Nhap lai thoi gian 2" << endl;
            cin >> tg2;
            cout << "\nChon bai toan ban muon lam: ";
            cin >> n;
        }
        else if (n == 3)
        {
            int sn;
            cout << "Nhap so nguyen muon cong them vao thoi gian 1: " << "";
            cin >> sn;
            tg3 = tg1 + sn;
            cout << "Sau khi cong: " << tg3 << endl;
            cout << "\nChon bai toan ban muon lam: ";
            cin >> n;
        }
        else if (n == 4)
        {
            int sn;
            cout << "Nhap so nguyen muon cong them vao thoi gian 2: " << "";
            cin >> sn;
            tg3 = tg2 + sn;
            cout << "Sau khi cong: " << tg3 << endl;
            cout << "\nChon bai toan ban muon lam: ";
            cin >> n;
        }
        else if (n == 5)
        {
            int sn;
            cout << "Nhap so nguyen muon tru di cua thoi gian 1: " << "";
            cin >> sn;
            tg3 = tg1 - sn;
            cout << "Sau khi tru: " << tg3 << endl;
            cout << "\nChon bai toan ban muon lam: ";
            cin >> n;
        }
        else if (n == 6)
        {
            int sn;
            cout << "Nhap so nguyen muon tru di cua thoi gian 2: " << "";
            cin >> sn;
            tg3 = tg2 - sn;
            cout << "Sau khi tru: " << tg3 << endl;;
            cout << "\nChon bai toan ban muon lam: ";
            cin >> n;
        }
        else if (n == 7)
        {
            tg3 = tg1 - tg2;
            cout << "CTimeSpan(t1, t2): " << tg3 << endl;
            cout << "\nChon bai toan ban muon lam: ";
            cin >> n;
        }
        else if (n == 8)
        {
            tg3 = tg1 + 1;
            cout << "Sau khi tang 1: " << tg3 << endl;
            cout << "\nChon bai toan ban muon lam: ";
            cin >> n;
        }
        else if (n == 9)
        {
            tg3 = tg2 + 1;
            cout << "Sau khi tang 1: " << tg3 << endl;
            cout << "\nChon bai toan ban muon lam: ";
            cin >> n;
        }
        else
        {
            cout << "Vui long nhap so trong khoang tu 0 den 9: " << "";
            cin >> n;
        }
    }
    return 0;
}
