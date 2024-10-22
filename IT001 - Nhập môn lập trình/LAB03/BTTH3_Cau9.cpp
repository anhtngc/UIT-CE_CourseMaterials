/* nhập vào một số nguyên dương n. tính n! */

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "nhap so nguyen duong n: ";
    cin >> n;
    if (n < 1)
    {
        do
        {
            cout << "n phai la so nguyen duong, xin hay nhap lai: ";
            cin >> n;
        } while (n < 1);
    }
    int giaithua = 1;
    for (int i = 1; i <= n; i++)
    {
        giaithua = giaithua * i;
    }
    cout << n << "! = " << giaithua << endl;
}
