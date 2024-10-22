#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    float a,b;
    cout << "- hinh chu nhat -" << endl;
    cout << "nhap chieu dai: ";
    cin >> a;
    cout << "nhap chieu rong: ";
    cin >> b;
    cout << "dien tich hinh chu nhat la: " << a * b << endl;
    cout << "chu vi hinh chu nhat la: " << (a + b) * 2 << endl;

    float n;
    cout << "- hinh vuong -" << endl;
    cout << "nhap canh hinh vuong: ";
    cin >> n;
    cout << "dien tich hinh vuong la: " << n * n << endl;
    cout << "chu vi hinh vuong la: " << 4 * n << endl;

    float r;
    cout << "- hinh tron -" << endl;
    cout << "nhap ban kinh r: ";
    cin >> r;
    cout << "dien tich hinh tron la: " << r * r * 3.14 << endl;
    cout << "chu vi hinh tron la: " << 2 * 3.14 * r << endl;
}
