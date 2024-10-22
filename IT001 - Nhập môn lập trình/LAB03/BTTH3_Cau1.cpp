/* nhập vào số nguyên dương n, xuất ra số ngược lại */

#include <iostream>

using namespace std;

int main()
{
    int n, temp;
    cout << "nhap vao so nguyen duong n: ";
    cin >> n;
    if (n < 1)
    {
        do
        {
            cout << "n phai la so nguyen duong, xin hay nhap lai: ";
            cin >> n;
        } while (n < 1);
    }
    while (n != 0)
    {
        temp = temp * 10 + n % 10;
        n = n / 10;
    }
    cout << "so dao nguoc cua n la: " << temp << endl;
}
