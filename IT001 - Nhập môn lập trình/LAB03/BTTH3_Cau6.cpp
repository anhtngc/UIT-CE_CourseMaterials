/* nhập vào một số nguyên dương n, in ra các số nguyên tố nhỏ hơn hay bằng n,
tính tổng các số này. */

#include <iostream>
#include <math.h>

using namespace std;

int ktsnt(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    cout << "nhap so nguyen duong n: ";
    cin >> n;
    cout << "cac so nguyen to nho hon " << n << " la: ";
    for (int i = 2; i <= n; i++)
    {
        if (ktsnt(i) == 1)
            cout << i << " ";
    }
    int sum = 0;
    for (int i = 2; i <= n; i++)
    {
        if (ktsnt(i) == 1)
            sum = sum + i;
    }
    cout << "\ntong cac so nguyen to nho hon " << n << " la: " << sum << endl;
}
