/* nhập vào số nguyên dương n, kiểm tra n có phải là số nguyên tố không? */

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cout << "nhap vao so nguyen duong n: ";
    cin >> n;
    if (n < 2)
    {
        cout << n << " khong phai la so nguyen to." << endl;
    }
    int temp = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            temp++;
    }
    if (temp == 0)
    {
        cout << n << " la so nguyen to." << endl;
    }
    else cout << n << " khong la so nguyen to." << endl;
    return 0;
}
