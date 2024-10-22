/* nhập vào một số nguyên dương n, 0 < n < 50, tìm số nguyên tố lớn nhất nhỏ hơn
số n */

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
    int n, i, temp = 0;
    cout << "nhap so nguyen duong n (0 < n < 50): ";
    cin >> n;
    if (n < 1 || n > 49)
    {
        do
        {
            cout << "n phai nam trong (0;50), xin hay nhap lai: ";
            cin >> n;
        } while (n < 1 || n > 49);
    }
    for (int i = 2; i < n; i++)
    {
        if (ktsnt(i) == 1)
        {
            temp = i*0 + i;
        }
    }
    cout << "so nguyen to lon nhat nho hon " << n << " la: " << temp << endl;
}
