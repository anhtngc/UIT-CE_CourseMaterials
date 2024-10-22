/*  viết chương trình nhân 2 số bằng đệ quy */

#include <iostream>

using namespace std;

float tinh(float a, float b)
{
    return a * b;
}

int main()
{
    float a, b;
    cout << "nhap a: ";
    cin >> a;
    cout << "nhap b: ";
    cin >> b;
    cout << a << " x " << b << " = " << tinh(a,b) << endl;
}
