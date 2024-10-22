#include <iostream>
using namespace std;
int main()
{
    int h,p,s;
    cout << "nhap gio: ";
    cin >> h;
    cout << "nhap phut: ";
    cin >> p;
    cout << "nhap giay: ";
    cin >> s;
    if (h < 0 || h > 23 || p < 0 || p > 59 || s < 0 || s > 59)
        cout << "Khong hop le." << endl;
    else cout << "Gio, phut, giay hop le." << endl;
}
